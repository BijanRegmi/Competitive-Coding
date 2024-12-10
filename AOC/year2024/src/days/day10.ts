import { Solution, TestCases } from "../types";
type ParseResult = number[][];

function parseRawInput(rawInput: string): ParseResult {
  return rawInput
    .split("\n")
    .map((l) => l.split("").map((n) => (n === "." ? -1 : Number(n))));
}

function part1(rawInput: string) {
  const input = parseRawInput(rawInput);
  const R = input.length;
  const C = input[0].length;

  const dfs = (
    x: number,
    y: number,
    v: Set<number>,
    n: number,
  ): [number, number][] => {
    if (v.has(y * C + x)) return []; // if already visited
    if (x < 0 || x >= C || y < 0 || y >= R) return []; // if out of bounds
    if (input[y][x] !== n) return []; // if not the target number

    v.add(y * C + x);

    if (input[y]?.[x] === 9) return [[y, x]];

    const left = dfs(x - 1, y, v, n + 1);
    const right = dfs(x + 1, y, v, n + 1);
    const down = dfs(x, y - 1, v, n + 1);
    const up = dfs(x, y + 1, v, n + 1);

    return [...left, ...right, ...down, ...up];
  };

  let ans = 0;
  for (let y = 0; y < R; y++) {
    for (let x = 0; x < C; x++) {
      const nines = dfs(x, y, new Set(), 0);
      const ninesSet = new Set(nines.map(([yy, xx]) => yy * C + xx));
      ans += ninesSet.size;
    }
  }

  return ans;
}

function part2(rawInput: string) {
  const input = parseRawInput(rawInput);
  const R = input.length;
  const C = input[0].length;

  const dfs = (x: number, y: number, v: Set<number>, n: number): number => {
    if (x < 0 || x >= C || y < 0 || y >= R) return 0; // if out of bounds
    if (input[y][x] !== n) return 0; // if not the target number

    v.add(y * C + x);

    if (input[y]?.[x] === 9) return 1;

    const left = dfs(x - 1, y, v, n + 1);
    const right = dfs(x + 1, y, v, n + 1);
    const up = dfs(x, y - 1, v, n + 1);
    const down = dfs(x, y + 1, v, n + 1);

    return left + right + up + down;
  };

  let ans = 0;
  for (let y = 0; y < R; y++) {
    for (let x = 0; x < C; x++) {
      ans += dfs(x, y, new Set(), 0);
    }
  }

  return ans;
}

const testCases: TestCases = {
  part1: [
    {
      input: `89010123
78121874
87430965
96549874
45678903
32019012
01329801
10456732`,
      expectedOutput: 36,
    },
  ],
  part2: [
    {
      input: `.....0.
..4321.
..5..2.
..6543.
..7..4.
..8765.
..9....`,
      expectedOutput: 3,
    },
    {
      input: `89010123
78121874
87430965
96549874
45678903
32019012
01329801
10456732`,
      expectedOutput: 81,
    },
  ],
};

const solution: Solution = {
  part1,
  part2,
  testCases,
};

export default solution;
