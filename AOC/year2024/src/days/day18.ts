import { PriorityQueue, Dir, dirs } from "../utils";
import { Solution, TestCases } from "../types";
type ParseResult = string[];

function parseRawInput(rawInput: string): ParseResult {
  return rawInput.split("\n");
}

function part1(rawInput: string) {
  const isTest = process.env.TEST_MODE === "t";

  const input = parseRawInput(rawInput);
  input.splice(isTest ? 12 : 1024);

  const n = isTest ? 6 : 70;
  const sx = 0,
    sy = 0;
  const ex = n,
    ey = n;
  const R = n + 1,
    C = n + 1;

  const pq = new PriorityQueue<[number, number]>("min");
  const dist: { [cord: string]: number } = {};
  for (let y = 0; y < R; y++) {
    for (let x = 0; x < C; x++) {
      dist[`${x}-${y}`] = Infinity;
    }
  }
  dist[`${sx}-${sy}`] = 0;
  pq.enqueue([sx, sy], 0);

  while (pq.size) {
    let { node: u, priority: ud } = pq.dequeue()!;

    const [x, y] = u;

    if (x === ex && y === ey) break;

    for (let nd of Object.keys(dirs) as Dir[]) {
      const [dx, dy] = dirs[nd];
      const nx = x + dx;
      const ny = y + dy;

      if (nx < 0 || nx > R || ny < 0 || ny > C || input.includes(`${nx},${ny}`))
        continue;

      let cost = ud + 1;

      const ns = `${nx}-${ny}`;
      if (cost < dist[ns]) {
        dist[ns] = cost;
        pq.enqueue([nx, ny], cost);
      }
    }
  }

  return dist[`${ex}-${ey}`];
}

function part2(rawInput: string) {
  const originput = parseRawInput(rawInput);
  const isTest = process.env.TEST_MODE === "t";

  let start = 0,
    end = originput.length - 1;
  while (start < end) {
    const mid = Math.floor((start + end) / 2);
    const input = [...originput];
    input.splice(mid);

    const n = isTest ? 6 : 70;
    const sx = 0,
      sy = 0;
    const ex = n,
      ey = n;
    const R = n + 1,
      C = n + 1;

    const pq = new PriorityQueue<[number, number]>("min");
    const dist: { [cord: string]: number } = {};
    for (let y = 0; y < R; y++) {
      for (let x = 0; x < C; x++) {
        dist[`${x}-${y}`] = Infinity;
      }
    }
    dist[`${sx}-${sy}`] = 0;
    pq.enqueue([sx, sy], 0);

    while (pq.size) {
      let { node: u, priority: ud } = pq.dequeue()!;

      const [x, y] = u;

      if (x === ex && y === ey) break;

      for (let nd of Object.keys(dirs) as Dir[]) {
        const [dx, dy] = dirs[nd];
        const nx = x + dx;
        const ny = y + dy;

        if (
          nx < 0 ||
          nx > R ||
          ny < 0 ||
          ny > C ||
          input.includes(`${nx},${ny}`)
        )
          continue;

        let cost = ud + 1;

        const ns = `${nx}-${ny}`;
        if (cost < dist[ns]) {
          dist[ns] = cost;
          pq.enqueue([nx, ny], cost);
        }
      }
    }

    if (dist[`${ex}-${ey}`] === Infinity) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }

  return originput[start];
}

const testCases: TestCases = {
  part1: [
    {
      input: `5,4
4,2
4,5
3,0
2,1
6,3
2,4
1,5
0,6
3,3
2,6
5,1
1,2
5,5
2,5
6,5
1,4
0,4
6,4
1,1
6,1
1,0
0,5
1,6
2,0`,
      expectedOutput: 22,
    },
  ],
  part2: [
    {
      input: `5,4
4,2
4,5
3,0
2,1
6,3
2,4
1,5
0,6
3,3
2,6
5,1
1,2
5,5
2,5
6,5
1,4
0,4
6,4
1,1
6,1
1,0
0,5
1,6
2,0`,
      expectedOutput: "6,1",
    },
  ],
};

const solution: Solution = {
  part1,
  part2,
  testCases,
};

export default solution;
