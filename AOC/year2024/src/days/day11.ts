import { Solution, TestCases } from "../types";
type ParseResult = string[];

function parseRawInput(rawInput: string): ParseResult {
  return rawInput.split(" ");
}

function expand(num: string, times: number, dp: Map<string, number>): number {
  if (times === 0) return 1;

  const cacheSol = dp.get(`${num}-${times}`);
  if (cacheSol !== undefined) return cacheSol;

  let ans: number;

  if (num === "0") {
    ans = expand("1", times - 1, dp);
  } else if (num.length % 2 === 0) {
    const l = num.length;
    const left = Number(num.slice(0, l / 2)).toString();
    const right = Number(num.slice(l / 2, l)).toString();
    ans = expand(left, times - 1, dp) + expand(right, times - 1, dp);
  } else {
    ans = expand((Number(num) * 2024).toString(), times - 1, dp);
  }

  dp.set(`${num}-${times}`, ans);
  return ans;
}

function part1(rawInput: string) {
  const input = parseRawInput(rawInput);

  const dp = new Map<string, number>();
  const ans = input.reduce((t, v) => t + expand(v, 25, dp), 0);

  return ans;
}

function part2(rawInput: string) {
  const input = parseRawInput(rawInput);

  const dp = new Map<string, number>();
  const ans = input.reduce((t, v) => t + expand(v, 75, dp), 0);

  return ans;
}

const testCases: TestCases = {
  part1: [{ input: `125 17`, expectedOutput: 55312 }],
  part2: [{ input: `1`, expectedOutput: 1 }],
};

const solution: Solution = {
  part1,
  part2,
  testCases,
};

export default solution;
