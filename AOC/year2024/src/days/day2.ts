import { Solution, TestCases } from "../types";
type ParseResult = number[][];

function parseRawInput(rawInput: string): ParseResult {
  return rawInput.split("\n").map((l) => l.split(" ").map((n) => parseInt(n)));
}

function part1(rawInput: string) {
  const input = parseRawInput(rawInput);

  return input.filter(isReportSafe).length;
}

function part2(rawInput: string) {
  const input = parseRawInput(rawInput);

  return input.filter((report) => {
    let safe = isReportSafe(report);
    let idx = 0;
    while (!safe && idx < report.length) {
      const arr = [...report];
      arr.splice(idx, 1);
      safe = isReportSafe(arr);
      idx++;
    }

    return safe;
  }).length;
}

function isReportSafe(report: number[]) {
  let previousDiff = 0;
  let previousValue = report[0];

  for (let i = 1; i < report.length; i++) {
    const currentDiff = report[i] - previousValue;

    const signChanged =
      previousDiff && Math.sign(previousDiff) !== Math.sign(currentDiff);
    const diffOutOfRange = currentDiff === 0 || Math.abs(currentDiff) > 3;

    if (signChanged || diffOutOfRange) {
      return false;
    } else {
      previousValue = report[i];
      previousDiff = currentDiff;
    }
  }

  return true;
}

const testCases: TestCases = {
  part1: [
    {
      input: `7 6 4 2 1
1 2 7 8 9
9 7 6 2 1
1 3 2 4 5
8 6 4 4 1
1 3 6 7 9`,
      expectedOutput: 2,
    },
  ],
  part2: [
    {
      input: `7 6 4 2 1
1 2 7 8 9
9 7 6 2 1
1 3 2 4 5
8 6 4 4 1
1 3 6 7 9`,
      expectedOutput: 4,
    },
  ],
};

const solution: Solution = {
  part1,
  part2,
  testCases,
};

export default solution;
