import { Solution, TestCases } from "../types";
type ParseResult = { a: number; b: number; c: number; program: number[] };

function nums(s: string) {
  return Array.from(s.matchAll(/(\d+)/g)).map((m) => Number(m[0]));
}

function parseRawInput(rawInput: string): ParseResult {
  const [registers, program] = rawInput.split("\n\n");

  const [a, b, c] = registers.split("\n").map(nums);
  const instructions = nums(program);

  return {
    a: a[0],
    b: b[0],
    c: c[0],
    program: instructions,
  };
}

function part1(rawInput: string) {
  const { a, b, c, program } = parseRawInput(rawInput);

  let reg_a = a;
  let reg_b = b;
  let reg_c = c;
  let ip = 0;
  const stdout = [];

  const combo = (op: number) => {
    if (op <= 3) return op;
    if (op === 4) return reg_a;
    if (op === 5) return reg_b;
    if (op === 6) return reg_c;
    console.warn("Op 7 encountered");
    return -1;
  };

  while (ip < program.length) {
    const opcode = program[ip];
    const operand = program[ip + 1];

    switch (opcode) {
      case 0:
        // adv
        reg_a = Math.floor(
          (reg_a / 2 ** combo(operand)) % Number.MAX_SAFE_INTEGER,
        );
        ip += 2;
        break;
      case 1:
        // bxl
        reg_b = reg_b ^ operand;
        ip += 2;
        break;
      case 2:
        // bst
        reg_b = combo(operand) % 8;
        ip += 2;
        break;
      case 3:
        // jnz
        if (reg_a === 0) ip += 2;
        else ip = operand;
        break;
      case 4:
        // bxc
        reg_b = reg_b ^ reg_c;
        ip += 2;
        break;
      case 5:
        // out
        stdout.push(combo(operand) % 8);
        ip += 2;
        break;
      case 6:
        // bdv
        reg_b = Math.floor(
          (reg_a / 2 ** combo(operand)) % Number.MAX_SAFE_INTEGER,
        );
        ip += 2;
        break;
      case 7:
        // cdv
        reg_c = Math.floor(
          (reg_a / 2 ** combo(operand)) % Number.MAX_SAFE_INTEGER,
        );
        ip += 2;
        break;
    }
  }

  return stdout.join(",");
}

function part2(rawInput: string) {
}

const testCases: TestCases = {
  part1: [
    {
      input: `Register A: 729
Register B: 0
Register C: 0

Program: 0,1,5,4,3,0`,
      expectedOutput: "4,6,3,5,6,3,5,2,1,0",
    },
  ],
  part2: [
    {
      input: `Register A: 2024
Register B: 0
Register C: 0

Program: 0,3,5,4,3,0`,
      expectedOutput: 117440,
    },
  ],
};

const solution: Solution = {
  part1,
  part2,
  testCases,
};

export default solution;
