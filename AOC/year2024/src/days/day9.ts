import { Solution, TestCases } from "../types";
type ParseResult = { count: number; idx: number; file: boolean }[];

function parseRawInput(rawInput: string): ParseResult {
  return rawInput.split("").map((n, i) => ({
    count: Number(n),
    idx: Math.floor(i / 2),
    file: i % 2 === 0,
  }));
}

function part1(rawInput: string) {
  const input = parseRawInput(rawInput);

  let nums: number[] = [];
  for (let i = 0; i < input.length; i++) {
    nums.push(
      ...Array.from({ length: input[i].count }).map((_) =>
        input[i].file ? input[i].idx : -1,
      ),
    );
  }

  let l = 0,
    r = nums.length - 1;

  while (l < r) {
    if (nums[l] !== -1) {
      l++;
      continue; // Skip until empty space found in left
    }

    while (nums[r] === -1) r--; // Skip until file found in right

    // Swap empty space and file block
    nums[l] = nums[r];
    nums[r] = -1;

    l++;
    r--;
  }

  return nums.reduce((t, v, i) => t + (v === -1 ? 0 : v * i), 0);
}

function part2(rawInput: string) {
  const input = parseRawInput(rawInput);

  let nums: number[] = [];
  for (let i = 0; i < input.length; i++) {
    nums.push(
      ...Array.from({ length: input[i].count }).map((_) =>
        input[i].file ? input[i].idx : -1,
      ),
    );
  }

  let j = nums.length - 1;

  while (j >= 0) {
    if (nums[j] === -1) {
      j--;
      continue; // Skip until file is found in right
    }

    // Determining start and end of the rightmost file => (r1, r2]
    const r2 = j;
    while (nums[j] !== -1 && nums[r2] === nums[j] && j >= 0) j--;
    if (j < 0) break;
    const r1 = j;
    const r = r2 - r1;

    let i = 0;
    while (i <= r1) {
      if (nums[i] !== -1) {
        i++;
        continue; // Skip until empty space found in left
      }

      // Determining start and end of empty space => [l1, l2)
      const l1 = i;
      while (nums[i] === -1 && i <= r1) i++;
      if (i - 1 > r1) break;
      const l2 = i;
      const l = l2 - l1;

      if (r <= l) {
        // If right file fits in left space
        // Copy the right file segment to left space
        for (let rr = 0; rr < r; rr++) {
          nums[l1 + rr] = nums[r1 + rr + 1];
          nums[r1 + rr + 1] = -1;
        }
        break;
      }
    }
  }

  return nums.reduce((t, v, i) => t + (v === -1 ? 0 : v * i), 0);
}

const testCases: TestCases = {
  part1: [
    { input: `2333133121414131402`, expectedOutput: 1928 },
    { input: `12345`, expectedOutput: 60 },
  ],
  part2: [
    { input: `12345`, expectedOutput: 132 },
    { input: `233`, expectedOutput: 9 },
    { input: `2333133121414131402`, expectedOutput: 2858 },
  ],
};

const solution: Solution = {
  part1,
  part2,
  testCases,
};

export default solution;
