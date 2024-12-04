import { Solution, TestCases } from "../types";
type ParseResult = { left: number[]; right: number[] };

function parseRawInput(rawInput: string): ParseResult {
  const input: ParseResult = {
    left: [],
    right: [],
  };

  rawInput.split("\n").forEach((line) => {
    const [left, right] = line.split(/\s+/);
    input.left.push(parseInt(left));
    input.right.push(parseInt(right));
  });

  return input;
}

function part1(rawInput: string) {
  const input = parseRawInput(rawInput);

  input.left.sort((a, b) => a - b);
  input.right.sort((a, b) => a - b);

  let distance = 0;
  for (let i = 0; i < input.left.length; i++) {
    distance += Math.abs(input.left[i] - input.right[i]);
  }

  return distance;
}

function part2(rawInput: string) {
  const input = parseRawInput(rawInput);

  let score = 0;
  for (let i = 0; i < input.left.length; i++) {
    const leftVal = input.left[i];
    const count = input.right.filter((v) => v === leftVal).length;
    score += leftVal * count;
  }

  return score;
}

const testCases: TestCases = {
  part1: [
    {
      input: `3   4
4   3
2   5
1   3
3   9
3   3`,
      expectedOutput: 11,
    },
  ],
  part2: [
    {
      input: `3   4
4   3
2   5
1   3
3   9
3   3`,
      expectedOutput: 31,
    },
  ],
};

const solution: Solution = {
  part1,
  part2,
  testCases,
};

export default solution;
