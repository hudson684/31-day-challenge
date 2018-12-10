class Room {
  constructor(w, h) {
    this.w = w
    this.h = h

    this.squares = []
    for (let i = 0; i < h; ++i) {
      this.squares.push(new Array(w).fill(0))
    }
  }
}

class Door {
  constructor(x, y) {
    this.x = x
    this.y = y
  }
}
