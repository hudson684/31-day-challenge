/**
 * CODEmas day 02
 * Multi-Language Fibonacci Fun!
 *
 * JavaScript (NodeJS) implementation
 */

const readline = require('readline')
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
})

function FibSmallerThan(goal) {
  let fibs = [0, 1]
  let i = 1
  while (fibs[i] < goal) {
    fibs.push(fibs[i] + fibs[i-1])
    i++
  }
  return fibs.slice(1, fibs.length - 1)
}

function test_int(str) {
  return /^(?:0|[1-9]\d*)$/.test(str)
}

function get_input() {
  return new Promise((resolve, reject) => {
    rl.question('Enter goal (0 to exit): ', answer => {
      let input = Math.floor(Number(answer))
      if (test_int(answer) && input > -1) {
        resolve(input)
      } else {
        reject('Invalid input!')
      }
    })
  })
}

// Main
function main() {
  get_input().then(input => {
    if (input > 0) {
      console.log(FibSmallerThan(input))
      main()
    } else {
      // Exit program
      rl.close()
    }
  }).catch(err => {
    console.log(err)
    main()
  })
}

// Start main loop
main()
