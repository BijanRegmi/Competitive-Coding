import { Solution, TestCases } from "../types";
type ParseResult = {
  ax: number;
  ay: number;
  bx: number;
  by: number;
  px: number;
  py: number;
}[];

function nums(s: string) {
  return Array.from(s.matchAll(/(\d+)/g)).map((m) => Number(m[0]));
}

function parseRawInput(rawInput: string): ParseResult {
  return rawInput.split("\n\n").map((block) => {
    const [a, b, p] = block.split("\n");
    const [ax, ay] = nums(a);
    const [bx, by] = nums(b);
    const [px, py] = nums(p);

    return { ax, ay, bx, by, px, py };
  });
}

function part1(rawInput: string) {
  const input = parseRawInput(rawInput);

  let ans = 0;
  // ax*m + bx*n = px
  // ay*m + by*n = py
  for (let machine of input) {
    const a = machine.ax;
    const b = machine.bx;
    const c = machine.ay;
    const d = machine.by;

    const determinant = a * d - b * c;
    const I00 = (1 / determinant) * d;
    const I01 = (1 / determinant) * -b;
    const I10 = (1 / determinant) * -c;
    const I11 = (1 / determinant) * a;

    const m = I00 * machine.px + I01 * machine.py;
    const n = I10 * machine.px + I11 * machine.py;

    if (
      Math.abs(m - Math.round(m)) < 1e-3 &&
      Math.abs(n - Math.round(n)) < 1e-3
    ) {
      ans += Math.round(m) * 3 + Math.round(n);
    }
  }

  return ans;
}

function part2(rawInput: string) {
  const input = parseRawInput(rawInput);

  let ans = 0;
  for (let machine of input) {
    machine.px += 10000000000000;
    machine.py += 10000000000000;

    const a = machine.ax;
    const b = machine.bx;
    const c = machine.ay;
    const d = machine.by;

    const determinant = a * d - b * c;
    const I00 = (1 / determinant) * d;
    const I01 = (1 / determinant) * -b;
    const I10 = (1 / determinant) * -c;
    const I11 = (1 / determinant) * a;

    const m = I00 * machine.px + I01 * machine.py;
    const n = I10 * machine.px + I11 * machine.py;

    if (
      Math.abs(m - Math.round(m)) < 1e-3 &&
      Math.abs(n - Math.round(n)) < 1e-3
    ) {
      ans += Math.round(m) * 3 + Math.round(n);
    }
  }

  return ans;
}

const testCases: TestCases = {
  part1: [
    {
      input: `Button A: X+94, Y+34
Button B: X+22, Y+67
Prize: X=8400, Y=5400

Button A: X+26, Y+66
Button B: X+67, Y+21
Prize: X=12748, Y=12176

Button A: X+17, Y+86
Button B: X+84, Y+37
Prize: X=7870, Y=6450

Button A: X+69, Y+23
Button B: X+27, Y+71
Prize: X=18641, Y=10279`,
      expectedOutput: 480,
    },
  ],
  part2: [
    {
      input: `Button A: X+94, Y+34
Button B: X+22, Y+67
Prize: X=8400, Y=5400

Button A: X+26, Y+66
Button B: X+67, Y+21
Prize: X=12748, Y=12176

Button A: X+17, Y+86
Button B: X+84, Y+37
Prize: X=7870, Y=6450

Button A: X+69, Y+23
Button B: X+27, Y+71
Prize: X=18641, Y=10279`,
      expectedOutput: 875318608908,
    },
  ],
};

const solution: Solution = {
  part1,
  part2,
  testCases,
};

export default solution;
