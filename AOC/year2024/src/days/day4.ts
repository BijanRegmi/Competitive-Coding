import { Solution, TestCases } from "../types";
type ParseResult = string[];

function parseRawInput(rawInput: string): ParseResult {
  return rawInput.split("\n");
}

function part1(rawInput: string) {
  const input = parseRawInput(rawInput);
  const n = input[0].length;
  let ans = 0;

  for (let i = 0; i < input.length; i++) {
    for (let j = 0; j < n; j++) {
      const horizontal =
        input[i]?.[j] +
        input[i]?.[j + 1] +
        input[i]?.[j + 2] +
        input[i]?.[j + 3];
      const vertical =
        input[i]?.[j] +
        input[i + 1]?.[j] +
        input[i + 2]?.[j] +
        input[i + 3]?.[j];
      const mainDiagonal =
        input[i]?.[j] +
        input[i + 1]?.[j + 1] +
        input[i + 2]?.[j + 2] +
        input[i + 3]?.[j + 3];
      const otherDiagonal =
        input[i]?.[j] +
        input[i + 1]?.[j - 1] +
        input[i + 2]?.[j - 2] +
        input[i + 3]?.[j - 3];

      if (horizontal === "XMAS" || horizontal === "SAMX") ans++;
      if (vertical === "XMAS" || vertical === "SAMX") ans++;
      if (mainDiagonal === "XMAS" || mainDiagonal === "SAMX") ans++;
      if (otherDiagonal === "XMAS" || otherDiagonal === "SAMX") ans++;
    }
  }

  return ans;
}

function part2(rawInput: string) {
  const input = parseRawInput(rawInput);

  const n = input[0].length;
  let ans = 0;

  for (let i = 0; i < input.length; i++) {
    for (let j = 0; j < n; j++) {
      const mainDiagonal =
        input[i - 1]?.[j - 1] + input[i]?.[j] + input[i + 1]?.[j + 1];
      const otherDiagonal =
        input[i - 1]?.[j + 1] + input[i]?.[j] + input[i + 1]?.[j - 1];

      if (
        (mainDiagonal === "MAS" || mainDiagonal === "SAM") &&
        (otherDiagonal === "MAS" || otherDiagonal === "SAM")
      )
        ans++;
    }
  }

  return ans;
}

const testCases: TestCases = {
  part1: [
    {
      input: `MMMSXXMASM
MSAMXMSMSA
AMXSXMAAMM
MSAMASMSMX
XMASAMXAMM
XXAMMXXAMA
SMSMSASXSS
SAXAMASAAA
MAMMMXMMMM
MXMXAXMASX`,
      expectedOutput: 18,
    },
  ],
  part2: [
    {
      input: `.M.S......
..A..MSMS.
.M.S.MAA..
..A.ASMSM.
.M.S.M....
..........
S.S.S.S.S.
.A.A.A.A..
M.M.M.M.M.
..........`,
      expectedOutput: 9,
    },
  ],
};

const solution: Solution = {
  part1,
  part2,
  testCases,
};

export default solution;
