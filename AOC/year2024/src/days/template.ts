import { Solution, TestCases } from "../types";
type ParseResult = string;

const testCases: TestCases = {
  part1: [{ input: "1", expectedOutput: "1" }],
  part2: [{ input: "1", expectedOutput: "1" }],
};

function parseInput(input: string): ParseResult {
  return input;
}

function part1(content: string): string {
  const input = parseInput(content);

  return input;
}

function part2(content: string): string {
  const input = parseInput(content);

  return input;
}

const solution: Solution = {
  part1,
  part2,
  testCases,
};

export default solution;
