/**
 * CODEmas day 02
 * Multi-Language Fibonacci Fun!
 *
 * JavaScript (NodeJS) implementation
 */

#include <iostream>

using namespace std;

// Headers
void FibSmallerThan(int goal);

void FibSmallerThan(int goal) {
  // Print all Fibonacci numbers less than goal
  int last = 0,
      current = 1,
      tmp;
  cout << current;

  while (current < goal) {
    cout << ", " << current;
    tmp = current;
    current += last;
    last = tmp;
  }

  cout << endl;
}

int main() {
  int goal;
  cout << "Enter goal (0 to exit): ";
  cin >> goal;

  if (goal > 0) {
    FibSmallerThan(goal);
    main();
  }
}
