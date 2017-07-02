/**
 * CODEmas day 01
 * Random Library Implementation - Password Creation
 *
 * Implementation of Mersenne Twister pseudorandom number generator (PRNG)
 */

#include <iostream>
#include <time.h>
#include <limits.h>

using namespace std;

// Headers
int Random();
int Random(int max);
int Random(int min, int max);
char RandChar(bool isUpper);
void PasswordGeneration(char* password, int length);

// MT Headers
void seed_mt(int seed);
long long extract_number();

// Function implementations

int Random() {
  return extract_number() % 10;
}

int Random(int max) {
  return extract_number() % max;
}

int Random(int min, int max) {
  return min + extract_number() % (max - min + 1);
}

char RandChar(bool isUpper) {
  char out = isUpper ? 65 : 97;
  return out + Random(26);
}

void PasswordGeneration(char* password, int length) {
  // Generate a password
  char next = '0';

  for (int i = 0; i < length; ++i) {
    // Decide between char or int
    switch (Random(3)) {
      case 0: // int
        next = '0' + Random();
        break;
      case 1: // lowercase
        next = RandChar(false);
        break;
      case 2: // uppercase
        next = RandChar(true);
        break;
    }

    password[i] = next;
  }

  password[length] = '\0';
}

int main() {
  // Seed the PRNG
  seed_mt(int(time(NULL)));

  // Ask for password length
  int length;
  cout << "Enter a length for your password: ";
  cin >> length;
  cout << "\nYour password is: ";

  char password[length + 1];
  PasswordGeneration(password, length);

  for (int i = 0; i < length; ++i) {
    cout << password[i];
  }

  cout << endl;
}

// Constants
enum {
  W = 32,
  N = 624,
  M = 397,
  R = 31,

  A = 0x9908b0df,

  U = 11,
  D = 0xffffffff,

  S = 7,
  B = 0x9d2c5680,

  T = 15,
  C = 0xefc60000,

  L = 18,

  F = 1812433253,

  LOWER_MASK = (1ull << R) - 1,
  UPPER_MASK = (~LOWER_MASK << 32)
};

// Mersenne twister implementation
int* MT = new int[N];
unsigned int index = N + 1;

long long lowest_bits(long long x) {
  return (x & 0xffffffff);
}

void seed_mt(int seed) {
  index = N;
  MT[0] = seed;

  for (unsigned int i = 1; i < N + 1; ++i) {
    MT[i] = lowest_bits(F * (MT[i - 1] ^ (MT[i - 1] >> (W - 2))) + i);
  }
}

void twist() {
  for (unsigned int i = 0; i < N; ++i) {
    int x = (MT[i] & UPPER_MASK) + (MT[(i + 1) % N] & LOWER_MASK);
    int xA = x >> 1;
    if (x % 2 != 0) {
      xA ^= A;
    }
    MT[i] = MT[(i + M) % N] ^ A;
  }
  index = 0;
}

long long extract_number() {
  if (index >= N) {
    if (index > N) {
      cout << "Generator was never seeded!" << endl;
    } else {
      twist();
    }
  }

  int y = MT[index++];
  y ^= ((y >> U) & D);
  y ^= ((y << S) & B);
  y ^= ((y << T) & C);
  y ^= (y >> L);

  return lowest_bits(y);
}
