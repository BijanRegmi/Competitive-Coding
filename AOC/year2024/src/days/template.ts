import { Solution, TestCases } from "../types";
type ParseResult = string;

const testCases: TestCases = {
  part1: [{ input: "1", expectedOutput: "1" }],
  part2: [{ input: "1", expectedOutput: "1" }],
};

function parseRawInput(rawInput: string): ParseResult {
  return rawInput;
}

function part1(rawInput: string) {
  const input = parseRawInput(rawInput);

  return input;
}

function part2(rawInput: string) {
  const input = parseRawInput(rawInput);

  return input;
}

const solution: Solution = {
  part1,
  part2,
  testCases,
};

export default solution;
