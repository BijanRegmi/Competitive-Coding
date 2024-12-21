import { Solution, TestCases } from "../types";
import { Dir, dirs, PriorityQueue } from "../utils";
type ParseResult = string[][];

function parseRawInput(rawInput: string): ParseResult {
  return rawInput.split("\n").map((s) => s.split(""));
}

function part1(rawInput: string) {
  const input = parseRawInput(rawInput);

  const sy = input.findIndex((l) => l.includes("S"));
  const sx = input[sy].findIndex((l) => l.includes("S"));
  const ey = input.findIndex((l) => l.includes("E"));
  const ex = input[ey].findIndex((l) => l.includes("E"));

  const R = input.length;
  const C = input[0].length;

  const pq = new PriorityQueue<[number, number, Dir]>("min");
  const dist: { [cord: string]: number } = {};
  for (let y = 0; y < R; y++) {
    for (let x = 0; x < C; x++) {
      if (input[y][x] === "#") continue;
      for (let d of Object.keys(dirs)) {
        dist[`${x}-${y}:${d}`] = Infinity;
      }
    }
  }
  dist[`${sx}-${sy}:r`] = 0;
  pq.enqueue([sx, sy, "r"], 0);

  while (pq.size) {
    let { node: u, priority: ud } = pq.dequeue()!;

    const [x, y, d] = u;

    if (x === ex && y === ey) break;

    for (let nd of Object.keys(dirs) as Dir[]) {
      const [dx, dy] = dirs[nd];
      const nx = x + dx;
      const ny = y + dy;

      if (input[ny][nx] === "#") continue;

      let cost = ud;
      if (d === "d") {
        if (nd === "d") cost += 1;
        else if (nd === "u") cost += Infinity;
        else cost += 1001;
      } else if (d === "u") {
        if (nd === "u") cost += 1;
        else if (nd === "d") cost += Infinity;
        else cost += 1001;
      } else if (d === "l") {
        if (nd === "l") cost += 1;
        else if (nd === "r") cost += Infinity;
        else cost += 1001;
      } else if (d === "r") {
        if (nd === "r") cost += 1;
        else if (nd === "l") cost += Infinity;
        else cost += 1001;
      }

      const ns = `${nx}-${ny}:${nd}`;
      if (cost < dist[ns]) {
        dist[ns] = cost;
        pq.enqueue([nx, ny, nd], cost);
      }
    }
  }

  return Math.min(
    dist[`${ex}-${ey}:l`],
    dist[`${ex}-${ey}:r`],
    dist[`${ex}-${ey}:u`],
    dist[`${ex}-${ey}:d`],
  );
}

function part2(rawInput: string) {
  const input = parseRawInput(rawInput);

  const sy = input.findIndex((l) => l.includes("S"));
  const sx = input[sy].findIndex((l) => l.includes("S"));
  const ey = input.findIndex((l) => l.includes("E"));
  const ex = input[ey].findIndex((l) => l.includes("E"));

  const R = input.length;
  const C = input[0].length;

  const pq = new PriorityQueue<[number, number, Dir]>("min");
  const dist: { [cord: string]: number } = {};
  const prev: { [cord: string]: string[] } = {};
  for (let y = 0; y < R; y++) {
    for (let x = 0; x < C; x++) {
      if (input[y][x] === "#") continue;
      for (let d of Object.keys(dirs)) {
        const s = `${x}-${y}:${d}`;
        dist[s] = Infinity;
      }
    }
  }
  dist[`${sx}-${sy}:r`] = 0;
  pq.enqueue([sx, sy, "r"], 0);

  while (pq.size) {
    let { node: u, priority: ud } = pq.dequeue()!;

    const [x, y, d] = u;

    for (let nd of Object.keys(dirs) as Dir[]) {
      const [dx, dy] = dirs[nd];
      const nx = x + dx;
      const ny = y + dy;

      if (input[ny][nx] === "#") continue;

      let cost = ud;
      if (d === "d") {
        if (nd === "d") cost += 1;
        else if (nd === "u") cost += Infinity;
        else cost += 1001;
      } else if (d === "u") {
        if (nd === "u") cost += 1;
        else if (nd === "d") cost += Infinity;
        else cost += 1001;
      } else if (d === "l") {
        if (nd === "l") cost += 1;
        else if (nd === "r") cost += Infinity;
        else cost += 1001;
      } else if (d === "r") {
        if (nd === "r") cost += 1;
        else if (nd === "l") cost += Infinity;
        else cost += 1001;
      }

      const ns = `${nx}-${ny}:${nd}`;
      if (cost < dist[ns]) {
        dist[ns] = cost;
        prev[ns] = [`${x}-${y}:${d}`];
        pq.enqueue([nx, ny, nd], cost);
      } else if (cost === dist[ns] && cost !== Infinity) {
        prev[ns].push(`${x}-${y}:${d}`);
      }
    }
  }

  let min = Infinity;
  let minDir: Dir[] = [];
  for (let dir of Object.keys(dirs) as Dir[]) {
    const cost = dist[`${ex}-${ey}:${dir}`];
    if (cost < min) {
      min = cost;
      minDir = [dir];
    } else if (cost === min) {
      minDir.push(dir);
    }
  }

  let queue: string[] = minDir.map((d) => `${ex}-${ey}:${d}`);
  const visited = new Set<string>();
  const visitedCoord = new Set<string>();

  while (queue.length !== 0) {
    const v = queue.shift();
    if (v && !visited.has(v)) {
      visited.add(v);
      visitedCoord.add(v.split(":")[0]);

      const prevCoords = prev[v];
      prevCoords?.forEach((p) => {
        if (p && !visited.has(p)) {
          queue.push(p);
        }
      });
    }
  }

  return visitedCoord.size;
}

const testCases: TestCases = {
  part1: [
    {
      input: `###############
#.....#......E#
#.###.#.#.#.#.#
#S..#.....#...#
###############`,
      expectedOutput: 6018,
    },
    {
      input: `###############
#.......#....E#
#.#.###.#.###.#
#.....#.#...#.#
#.###.#####.#.#
#.#.#.......#.#
#.#.#####.###.#
#...........#.#
###.#.#####.#.#
#...#.....#.#.#
#.#.#.###.#.#.#
#.....#...#.#.#
#.###.#.#.#.#.#
#S..#.....#...#
###############`,
      expectedOutput: 7036,
    },
    {
      input: `#################
#...#...#...#..E#
#.#.#.#.#.#.#.#.#
#.#.#.#...#...#.#
#.#.#.#.###.#.#.#
#...#.#.#.....#.#
#.#.#.#.#.#####.#
#.#...#.#.#.....#
#.#.#####.#.###.#
#.#.#.......#...#
#.#.###.#####.###
#.#.#...#.....#.#
#.#.#.#####.###.#
#.#.#.........#.#
#.#.#.#########.#
#S#.............#
#################`,
      expectedOutput: 11048,
    },
  ],
  part2: [
    {
      input: `###############
#.....#......E#
#.###.#.#.#.#.#
#S..#.....#...#
###############`,
      expectedOutput: 22,
    },
    {
      input: `###############
#.......#....E#
#.#.###.#.###.#
#.....#.#...#.#
#.###.#####.#.#
#.#.#.......#.#
#.#.#####.###.#
#...........#.#
###.#.#####.#.#
#...#.....#.#.#
#.#.#.###.#.#.#
#.....#...#.#.#
#.###.#.#.#.#.#
#S..#.....#...#
###############`,
      expectedOutput: 45,
    },
    {
      input: `#################
#...#...#...#..E#
#.#.#.#.#.#.#.#.#
#.#.#.#...#...#.#
#.#.#.#.###.#.#.#
#...#.#.#.....#.#
#.#.#.#.#.#####.#
#.#...#.#.#.....#
#.#.#####.#.###.#
#.#.#.......#...#
#.#.###.#####.###
#.#.#...#.....#.#
#.#.#.#####.###.#
#.#.#.........#.#
#.#.#.#########.#
#S#.............#
#################`,
      expectedOutput: 64,
    },
  ],
};

const solution: Solution = {
  part1,
  part2,
  testCases,
};

export default solution;
