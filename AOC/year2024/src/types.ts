export type TestCases = {
  part1: {
    input: string;
    expectedOutput: string;
  }[];
  part2: {
    input: string;
    expectedOutput: string;
  }[];
};

export type Solution = {
  part1: (input: string) => string;
  part2: (input: string) => string;
  testCases: TestCases;
};

export type Status = {
  part: number;
  case: number;
  input: string;
  output: string;
  expectedOutput: string;
  passed: boolean;
  time: number;
};
