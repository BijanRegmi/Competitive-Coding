import { Solution, TestCases } from "../types";
type ParseResult = string[];

function parseRawInput(rawInput: string): ParseResult {
  return rawInput.split("\n");
}

type Coord = [number, number];

function part1(rawInput: string) {
  const input = parseRawInput(rawInput);
  const antinodes = new Set<number>();

  const R = input.length;
  const C = input[0].length;

  const signalCoordMap: { [key: string]: Coord[] } = {};

  for (let y = 0; y < R; y++) {
    for (let x = 0; x < C; x++) {
      const c = input[y][x];
      if (c === ".") continue;
      if (!signalCoordMap[c]) signalCoordMap[c] = [];
      signalCoordMap[c].push([y, x]);
    }
  }

  for (let signal in signalCoordMap) {
    const coords = signalCoordMap[signal];
    for (let i = 0; i < coords.length; i++) {
      for (let j = i + 1; j < coords.length; j++) {
        const c1 = coords[i];
        const c2 = coords[j];

        const next1 = [c2[0] + (c2[0] - c1[0]), c2[1] + (c2[1] - c1[1])];
        const next2 = [c1[0] + (c1[0] - c2[0]), c1[1] + (c1[1] - c2[1])];

        if (next1[0] >= 0 && next1[0] < R && next1[1] >= 0 && next1[1] < C)
          antinodes.add(next1[0] * C + next1[1]);

        if (next2[0] >= 0 && next2[0] < R && next2[1] >= 0 && next2[1] < C)
          antinodes.add(next2[0] * C + next2[1]);
      }
    }
  }

  return antinodes.size;
}

function part2(rawInput: string) {
  const input = parseRawInput(rawInput);
  const antinodes = new Set<number>();

  const R = input.length;
  const C = input[0].length;

  const signalCoordMap: { [key: string]: Coord[] } = {};

  for (let y = 0; y < R; y++) {
    for (let x = 0; x < C; x++) {
      const c = input[y][x];
      if (c === ".") continue;
      if (!signalCoordMap[c]) signalCoordMap[c] = [];
      antinodes.add(y * C + x);
      signalCoordMap[c].push([y, x]);
    }
  }

  for (let signal in signalCoordMap) {
    const coords = signalCoordMap[signal];
    for (let i = 0; i < coords.length; i++) {
      for (let j = i + 1; j < coords.length; j++) {
        let c1 = coords[i];
        let c2 = coords[j];

        while (true) {
          const next: Coord = [
            c2[0] + (c2[0] - c1[0]),
            c2[1] + (c2[1] - c1[1]),
          ];

          if (next[0] >= 0 && next[0] < R && next[1] >= 0 && next[1] < C) {
            c1 = c2;
            c2 = next;
            antinodes.add(next[0] * C + next[1]);
          } else {
            break;
          }
        }

        while (true) {
          const next: Coord = [
            c1[0] + (c1[0] - c2[0]),
            c1[1] + (c1[1] - c2[1]),
          ];

          if (next[0] >= 0 && next[0] < R && next[1] >= 0 && next[1] < C) {
            c2 = c1;
            c1 = next;
            antinodes.add(next[0] * C + next[1]);
          } else {
            break;
          }
        }
      }
    }
  }

  return antinodes.size;
}

const testCases: TestCases = {
  part1: [
    {
      input: `............
........0...
.....0......
.......0....
....0.......
......A.....
............
............
........A...
.........A..
............
............`,
      expectedOutput: 14,
    },
  ],
  part2: [
    {
      input: `T.........
...T......
.T........
..........
..........
..........
..........
..........
..........
..........`,
      expectedOutput: 9,
    },
    {
      input: `............
........0...
.....0......
.......0....
....0.......
......A.....
............
............
........A...
.........A..
............
............`,
      expectedOutput: 34,
    },
  ],
};

const solution: Solution = {
  part1,
  part2,
  testCases,
};

export default solution;
