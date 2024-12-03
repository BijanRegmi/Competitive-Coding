import { Solution, TestCases } from "../types";
type ParseResult = string[];

const testCases: TestCases = {
  part1: [
    {
      input:
        "xmul(2,4)%&mul[3,7]!@^do_not_mul(5,5)+mul(32,64]then(mul(11,8)mul(8,5))",
      expectedOutput: 161,
    },
  ],
  part2: [
    {
      input:
        "xmul(2,4)&mul[3,7]!^don't()_mul(5,5)+mul(32,64](mul(11,8)undo()?mul(8,5))",
      expectedOutput: 48,
    },
  ],
};

function parseRawInput(rawInput: string): ParseResult {
  return rawInput.split("\n");
}

function part1(rawInput: string) {
  const input = parseRawInput(rawInput);

  let sum = 0;
  const regex = new RegExp(/mul\((\d+),(\d+)\)/g);
  for (let i = 0; i < input.length; i++) {
    const matches = Array.from(input[i].matchAll(regex));
    matches.forEach((m) => (sum += Number(m[1]) * Number(m[2])));
  }

  return sum;
}

function part2(rawInput: string) {
  const input = parseRawInput(rawInput);
  const mulRegex = new RegExp(/mul\((\d+),(\d+)\)/g);
  const doRegex = new RegExp(/do\(\)/g);
  const dontRegex = new RegExp(/don't\(\)/g);

  let sum = 0;
  let enabled = true;

  for (let i = 0; i < input.length; i++) {
    const mulMatches = Array.from(input[i].matchAll(mulRegex));
    const doMatches = Array.from(input[i].matchAll(doRegex));
    const dontMatches = Array.from(input[i].matchAll(dontRegex));

    const occurences: {
      idx: number;
      amt: number;
      instruction: "mul" | "do" | "dont";
    }[] = [];

    occurences.push(
      ...mulMatches.map((m) => ({
        idx: m.index,
        amt: Number(m[1]) * Number(m[2]),
        instruction: "mul" as const,
      })),
    );
    occurences.push(
      ...doMatches.map((m) => ({
        idx: m.index,
        amt: 0,
        instruction: "do" as const,
      })),
    );
    occurences.push(
      ...dontMatches.map((m) => ({
        idx: m.index,
        amt: 0,
        instruction: "dont" as const,
      })),
    );

    occurences.sort((a, b) => a.idx - b.idx);

    for (const oc of occurences) {
      if (oc.instruction === "do") {
        enabled = true;
      } else if (oc.instruction === "dont") {
        enabled = false;
      } else if (oc.instruction === "mul") {
        if (enabled) sum += oc.amt;
      }
    }
  }

  return sum;
}

const solution: Solution = {
  part1,
  part2,
  testCases,
};

export default solution;
