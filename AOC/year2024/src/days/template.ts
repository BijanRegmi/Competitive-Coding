import { Solution, TestCases } from "../types";
type ParseResult = string[];

function parseRawInput(rawInput: string): ParseResult {
  return rawInput.split("\n");
}

function part1(rawInput: string) {
  const input = parseRawInput(rawInput);
  const ans = input.length;

  return ans;
}

function part2(rawInput: string) {
  const input = parseRawInput(rawInput);
  const ans = input.length;

  return ans;
}

const testCases: TestCases = {
  part1: [{ input: `1`, expectedOutput: 1 }],
  part2: [{ input: `1`, expectedOutput: 1 }],
};

const solution: Solution = {
  part1,
  part2,
  testCases,
};

export default solution;
