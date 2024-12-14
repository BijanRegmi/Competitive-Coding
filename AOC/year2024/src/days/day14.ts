import { Solution, TestCases } from "../types";
type ParseResult = string[];

function parseRawInput(rawInput: string): ParseResult {
  return rawInput.split("\n");
}

function nums(s: string) {
  return Array.from(s.matchAll(/(-?\d+)/g)).map((m) => Number(m[0]));
}

const C = 101;
const R = 103;

function part1(rawInput: string) {
  const input = parseRawInput(rawInput);
  let qpp = 0,
    qpn = 0,
    qnn = 0,
    qnp = 0;

  for (let robot of input) {
    const [px, py, vx, vy] = nums(robot);
    const t = 100;
    let sx = (px + t * vx) % C;
    let sy = (py + t * vy) % R;
    if (sx < 0) sx += C;
    if (sy < 0) sy += R;

    const nx = sx - (C - 1) / 2;
    const ny = -(sy - (R - 1) / 2);

    if (nx > 0 && ny > 0) qpp++;
    else if (nx > 0 && ny < 0) qpn++;
    else if (nx < 0 && ny < 0) qnn++;
    else if (nx < 0 && ny > 0) qnp++;
  }

  return qpp * qpn * qnn * qnp;
}

function part2(rawInput: string) {
  const input = parseRawInput(rawInput);

  let minSafetyFactor = Infinity;
  let minT = 0;

  let t = 0;
  while (t < R * C) {
    let qpp = 0,
      qpn = 0,
      qnn = 0,
      qnp = 0;

    for (let robot of input) {
      const [px, py, vx, vy] = nums(robot);
      let sx = (px + t * vx) % C;
      let sy = (py + t * vy) % R;
      if (sx < 0) sx += C;
      if (sy < 0) sy += R;

      const nx = sx - (C - 1) / 2;
      const ny = -(sy - (R - 1) / 2);

      if (nx > 0 && ny > 0) qpp++;
      else if (nx > 0 && ny < 0) qpn++;
      else if (nx < 0 && ny < 0) qnn++;
      else if (nx < 0 && ny > 0) qnp++;
    }

    const safetyFactor = qpp * qpn * qnn * qnp;
    if (safetyFactor < minSafetyFactor) {
      minSafetyFactor = safetyFactor;
      minT = t;
    }

    t++;
  }

  return minT;
}

const testCases: TestCases = {
  part1: [
    {
      input: `p=0,4 v=3,-3
p=6,3 v=-1,-3
p=10,3 v=-1,2
p=2,0 v=2,-1
p=0,0 v=1,3
p=3,0 v=-2,-2
p=7,6 v=-1,-3
p=3,0 v=-1,-2
p=9,3 v=2,3
p=7,3 v=-1,2
p=2,4 v=2,-3
p=9,5 v=-3,-3`,
      expectedOutput: 12,
    },
    // { input: `p=2,4 v=2,-3`, expectedOutput: 1 },
  ],
  part2: [{ input: `1`, expectedOutput: 1 }],
};

const solution: Solution = {
  part1,
  part2,
  testCases,
};

export default solution;
