import { Solution, TestCases } from "../types";
type ParseResult = { result: number; nums: number[] }[];

function parseRawInput(rawInput: string): ParseResult {
  return rawInput.split("\n").map((l) => {
    const [result, nums] = l.split(": ");

    return {
      result: Number(result),
      nums: nums.split(" ").map(Number),
    };
  });
}

function part1(rawInput: string) {
  const input = parseRawInput(rawInput);
  let ans = 0;

  for (let line of input) {
    const { result, nums } = line;

    function rec(curr: number, idx: number): number {
      if (idx >= nums.length) return curr;
      if (curr > result) return curr;

      const plus = rec(curr + nums[idx], idx + 1);
      if (plus === result) return result;

      const mul = rec(curr * nums[idx], idx + 1);
      if (mul === result) return result;

      return 0;
    }

    ans += rec(nums[0], 1);
  }

  return ans;
}

function part2(rawInput: string) {
  const input = parseRawInput(rawInput);
  let ans = 0;

  for (let line of input) {
    const { result, nums } = line;

    function rec(curr: number, idx: number): number {
      if (idx >= nums.length) return curr;
      if (curr > result) return curr;

      const plus = rec(curr + nums[idx], idx + 1);
      if (plus === result) return result;

      const mul = rec(curr * nums[idx], idx + 1);
      if (mul === result) return result;

      const concat = rec(Number(`${curr}${nums[idx]}`), idx + 1);
      if (concat === result) return result;

      return 0;
    }

    ans += rec(nums[0], 1);
  }

  return ans;
}

const testCases: TestCases = {
  part1: [
    {
      input: `190: 10 19
3267: 81 40 27
83: 17 5
156: 15 6
7290: 6 8 6 15
161011: 16 10 13
192: 17 8 14
21037: 9 7 18 13
292: 11 6 16 20`,
      expectedOutput: 3749,
    },
  ],
  part2: [
    {
      input: `190: 10 19
3267: 81 40 27
83: 17 5
156: 15 6
7290: 6 8 6 15
161011: 16 10 13
192: 17 8 14
21037: 9 7 18 13
292: 11 6 16 20`,
      expectedOutput: 11387,
    },
  ],
};

const solution: Solution = {
  part1,
  part2,
  testCases,
};

export default solution;
