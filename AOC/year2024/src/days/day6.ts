import { Solution, TestCases } from "../types";
type ParseResult = string[][];

type Dir = "l" | "r" | "u" | "d";

function parseRawInput(rawInput: string): ParseResult {
  return rawInput.split("\n").map((v) => v.split(""));
}

function part1(rawInput: string) {
  const input = parseRawInput(rawInput);

  const Y = input.length;
  const X = input[0].length;

  const startY = input.findIndex((v) => v.includes("^"));
  const startX = input[startY].indexOf("^");

  let y = startY,
    x = startX,
    dir: Dir = "u";

  const visited = new Set<number>();
  while (true) {
    const d = delta(dir);
    const nextX = x + d.dx;
    const nextY = y + d.dy;

    visited.add(y * X + x);

    if (nextX >= X || nextY >= Y || nextX < 0 || nextY < 0) {
      break;
    }

    if (input[nextY][nextX] === "#") {
      dir = rotateRight(dir);
    } else {
      x = nextX;
      y = nextY;
    }
  }

  return visited.size;
}

function part2(rawInput: string) {
  const input = parseRawInput(rawInput);

  const Y = input.length;
  const X = input[0].length;

  const startY = input.findIndex((v) => v.includes("^"));
  const startX = input[startY].indexOf("^");

  let ans = 0;

  for (let yy = 0; yy < Y; yy++) {
    for (let xx = 0; xx < X; xx++) {
      if (input[yy][xx] === "#" || input[yy][xx] === "^") {
        continue;
      }

      const left = new Set<number>();
      const right = new Set<number>();
      const up = new Set<number>();
      const down = new Set<number>();

      let y = startY,
        x = startX,
        dir: Dir = "u";

      while (true) {
        const d = delta(dir);
        const nextX = x + d.dx;
        const nextY = y + d.dy;

        if (dir === "l") left.add(y * X + x);
        if (dir === "r") right.add(y * X + x);
        if (dir === "u") up.add(y * X + x);
        if (dir === "d") down.add(y * X + x);

        if (nextX >= X || nextY >= Y || nextX < 0 || nextY < 0) {
          break;
        }

        // If next node has obstacle then just change the direction
        if (input[nextY][nextX] === "#" || (nextY === yy && nextX === xx)) {
          dir = rotateRight(dir);
          continue;
        }

        // Check if next node already has the current direction
        if (
          (dir === "l" && left.has(nextY * Y + nextX)) ||
          (dir === "r" && right.has(nextY * Y + nextX)) ||
          (dir === "u" && up.has(nextY * Y + nextX)) ||
          (dir === "d" && down.has(nextY * Y + nextX))
        ) {
          ans++;
          break;
        }

        x = nextX;
        y = nextY;
      }
    }
  }

  return ans;
}

function rotateRight(dir: Dir): Dir {
  if (dir === "u") return "r";
  else if (dir === "r") return "d";
  else if (dir === "d") return "l";
  else return "u";
}

function delta(dir: Dir) {
  if (dir === "l") {
    return {
      dx: -1,
      dy: 0,
    };
  } else if (dir === "r") {
    return {
      dx: 1,
      dy: 0,
    };
  } else if (dir === "u") {
    return {
      dx: 0,
      dy: -1,
    };
  } else {
    return {
      dx: 0,
      dy: 1,
    };
  }
}

const testCases: TestCases = {
  part1: [
    {
      input: `....#.....
.........#
..........
..#.......
.......#..
..........
.#..^.....
........#.
#.........
......#...`,
      expectedOutput: 41,
    },
  ],
  part2: [
    {
      input: `....#.....
.........#
..........
..#.......
.......#..
..........
.#..^.....
........#.
#.........
......#...`,
      expectedOutput: 6,
    },
    //     {
    //       input: `.#..
    // ...#
    // #^..
    // ..#.`,
    //       expectedOutput: 0,
    //     },
  ],
};

const solution: Solution = {
  part1,
  part2,
  testCases,
};

export default solution;
