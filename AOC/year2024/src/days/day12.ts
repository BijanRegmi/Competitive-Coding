import { Solution, TestCases } from "../types";
type ParseResult = string[];

function parseRawInput(rawInput: string): ParseResult {
  return rawInput.split("\n");
}

function dfs(y: number, x: number, c: string, v: Set<string>, G: string[]) {
  if (v.has(`${y} ${x}`)) return;
  if (y < 0 || y >= G.length || x < 0 || x >= G[0].length) return;
  if (G[y][x] !== c) return;

  v.add(`${y} ${x}`);
  dfs(y + 1, x, c, v, G);
  dfs(y - 1, x, c, v, G);
  dfs(y, x + 1, c, v, G);
  dfs(y, x - 1, c, v, G);
  return;
}

function part1(rawInput: string) {
  const input = parseRawInput(rawInput);

  const R = input.length;
  const C = input[0].length;

  const visited = new Set<string>();

  let ans = 0;
  for (let y = 0; y < R; y++) {
    for (let x = 0; x < C; x++) {
      if (visited.has(`${y} ${x}`)) continue;

      const region = new Set<string>();
      const plant = input[y][x];
      dfs(y, x, plant, region, input);
      for (let r of region) visited.add(r);

      let perimeter = 0;
      for (let coord of region) {
        const [y, x] = coord.split(" ").map(Number);

        const bottom = input[y + 1]?.[x] !== plant;
        const up = input[y - 1]?.[x] !== plant;
        const right = input[y]?.[x + 1] !== plant;
        const left = input[y]?.[x - 1] !== plant;

        perimeter += Number(bottom) + Number(up) + Number(right) + Number(left);
      }
      ans += perimeter * region.size;
    }
  }

  return ans;
}

function part2(rawInput: string) {
  const input = parseRawInput(rawInput);

  const R = input.length;
  const C = input[0].length;

  const visited = new Set<string>();

  let ans = 0;
  for (let y = 0; y < R; y++) {
    for (let x = 0; x < C; x++) {
      if (visited.has(`${y} ${x}`)) continue;

      const region = new Set<string>();
      const plant = input[y][x];
      dfs(y, x, plant, region, input);
      for (let r of region) visited.add(r);

      let corners = 0; // Counting the corners for all coord will give the number of sides
      for (let coord of region) {
        const [y, x] = coord.split(" ").map(Number);

        const topLeft =
          input[y - 1]?.[x] !== plant && input[y]?.[x - 1] !== plant;
        const outsideTopLeft =
          input[y - 1]?.[x] === plant &&
          input[y]?.[x - 1] === plant &&
          input[y - 1]?.[x - 1] !== plant;

        const topRight =
          input[y - 1]?.[x] !== plant && input[y]?.[x + 1] !== plant;
        const outsideTopRight =
          input[y - 1]?.[x] === plant &&
          input[y]?.[x + 1] === plant &&
          input[y - 1]?.[x + 1] !== plant;

        const bottomLeft =
          input[y + 1]?.[x] !== plant && input[y]?.[x - 1] !== plant;
        const outsideBottomLeft =
          input[y + 1]?.[x] === plant &&
          input[y]?.[x - 1] === plant &&
          input[y + 1]?.[x - 1] !== plant;

        const bottomRight =
          input[y + 1]?.[x] !== plant && input[y]?.[x + 1] !== plant;
        const outsideBottomRight =
          input[y + 1]?.[x] === plant &&
          input[y]?.[x + 1] === plant &&
          input[y + 1]?.[x + 1] !== plant;

        corners +=
          Number(topLeft) +
          Number(outsideTopLeft) +
          Number(topRight) +
          Number(outsideTopRight) +
          Number(bottomLeft) +
          Number(outsideBottomLeft) +
          Number(bottomRight) +
          Number(outsideBottomRight);
      }
      ans += corners * region.size;
    }
  }

  return ans;
}

const testCases: TestCases = {
  part1: [
    {
      input: `AAAA
BBCD
BBCC
EEEC`,
      expectedOutput: 140,
    },
    {
      input: `OOOOO
OXOXO
OOOOO
OXOXO
OOOOO`,
      expectedOutput: 772,
    },
    {
      input: `RRRRIICCFF
RRRRIICCCF
VVRRRCCFFF
VVRCCCJFFF
VVVVCJJCFE
VVIVCCJJEE
VVIIICJJEE
MIIIIIJJEE
MIIISIJEEE
MMMISSJEEE`,
      expectedOutput: 1930,
    },
  ],
  part2: [
    {
      input: `AAAA
BBCD
BBCC
EEEC`,
      expectedOutput: 80,
    },
    {
      input: `OOOOO
OXOXO
OOOOO
OXOXO
OOOOO`,
      expectedOutput: 436,
    },
    {
      input: `RRRRIICCFF
RRRRIICCCF
VVRRRCCFFF
VVRCCCJFFF
VVVVCJJCFE
VVIVCCJJEE
VVIIICJJEE
MIIIIIJJEE
MIIISIJEEE
MMMISSJEEE`,
      expectedOutput: 1206,
    },
    {
      input: `EEEEE
EXXXX
EEEEE
EXXXX
EEEEE`,
      expectedOutput: 236,
    },
    {
      input: `AAAAAA
AAABBA
AAABBA
ABBAAA
ABBAAA
AAAAAA`,
      expectedOutput: 368,
    },
  ],
};

const solution: Solution = {
  part1,
  part2,
  testCases,
};

export default solution;
