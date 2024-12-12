export type TestCases = {
  part1: {
    input: string;
    expectedOutput: any;
    enabled?: boolean
  }[];
  part2: {
    input: string;
    expectedOutput: any;
    enabled?: boolean
  }[];
};

export type Solution = {
  part1: (input: string) => any;
  part2: (input: string) => any;
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
