import { Solution, TestCases } from "../types";

type Dir = "<" | ">" | "v" | "^";

type ParseResult = { map: string[][]; actions: Dir[] };

function parseRawInput(rawInput: string, p2: boolean = false): ParseResult {
  if (p2)
    rawInput = rawInput
      .replaceAll("#", "##")
      .replaceAll("O", "[]")
      .replaceAll(".", "..")
      .replaceAll("@", "@.");

  const [map, actions] = rawInput.split("\n\n");
  return {
    map: map.split("\n").map((l) => l.split("")),
    actions: actions.replaceAll("\n", "").split("") as Dir[],
  };
}

function getNx(x: number, y: number, d: Dir): [number, number] {
  switch (d) {
    case "<":
      return [x - 1, y];
    case ">":
      return [x + 1, y];
    case "v":
      return [x, y + 1];
    case "^":
      return [x, y - 1];
  }
}

function part1(rawInput: string) {
  const input = parseRawInput(rawInput);
  const { map, actions } = input;

  const R = map.length;
  const C = map[0].length;

  let py = map.findIndex((m) => m.includes("@"));
  let px = map[py].indexOf("@");

  function move(x: number, y: number, d: Dir): boolean {
    const [nx, ny] = getNx(x, y, d);
    if (nx < 0 || nx >= C || ny < 0 || ny >= R) return false;

    if (map[ny][nx] === "#") return false;
    if (map[ny][nx] === "." || move(nx, ny, d)) {
      map[ny][nx] = map[y][x];
      map[y][x] = ".";
      return true;
    }

    return false;
  }

  for (let dir of actions) {
    if (move(px, py, dir)) {
      const [nx, ny] = getNx(px, py, dir);
      py = ny;
      px = nx;
    }
  }

  let ans = 0;
  for (let y = 0; y < R; y++) {
    for (let x = 0; x < C; x++) {
      if (map[y][x] === "O") {
        ans += y * 100 + x;
      }
    }
  }

  return ans;
}

function part2(rawInput: string) {
  const input = parseRawInput(rawInput, true);
  const { map, actions } = input;

  const R = map.length;
  const C = map[0].length;

  let py = map.findIndex((m) => m.includes("@"));
  let px = map[py].indexOf("@");

  function canMove(x: number, y: number, d: Dir): boolean {
    if (x < 0 || x >= C || y < 0 || y >= R) return false;

    const [nx1, ny1] = getNx(x, y, d);
    if (map[ny1][nx1] === ".") return true;
    if (map[ny1][nx1] === "#") return false;

    if (d === "<" || d === ">") return canMove(nx1, ny1, d);

    const nx2 = map[ny1][nx1] === "]" ? nx1 - 1 : nx1 + 1,
      ny2 = ny1;
    return canMove(nx1, ny1, d) && canMove(nx2, ny2, d);
  }

  function move(x: number, y: number, d: Dir): boolean {
    if (x < 0 || x >= C || y < 0 || y >= R) return false;

    const [nx1, ny1] = getNx(x, y, d);
    if (map[ny1][nx1] === ".") return true;
    if (map[ny1][nx1] === "#") return false;

    if (d === "<" || d === ">") {
      if (move(nx1, ny1, d)) {
        const [nnx1, nny1] = getNx(nx1, ny1, d);
        map[nny1][nnx1] = map[ny1][nx1];
        map[ny1][nx1] = ".";

        return true;
      }
      return false;
    }

    const nx2 = map[ny1][nx1] === "]" ? nx1 - 1 : nx1 + 1,
      ny2 = ny1;

    if (move(nx1, ny1, d) && move(nx2, ny2, d)) {
      const [nnx1, nny1] = getNx(nx1, ny1, d);
      map[nny1][nnx1] = map[ny1][nx1];
      map[ny1][nx1] = ".";

      const [nnx2, nny2] = getNx(nx2, ny2, d);
      map[nny2][nnx2] = map[ny2][nx2];
      map[ny2][nx2] = ".";
      return true;
    }
    return false;
  }

  for (let dir of actions) {
    if (!canMove(px, py, dir)) continue;
    if (!move(px, py, dir)) continue;

    const [nx, ny] = getNx(px, py, dir);
    map[ny][nx] = map[py][px];
    map[py][px] = ".";
    py = ny;
    px = nx;
  }

  let ans = 0;
  for (let y = 0; y < R; y++) {
    for (let x = 0; x < C; x++) {
      if (map[y][x] === "[") {
        ans += y * 100 + x;
      }
    }
  }

  return ans;
}

const testCases: TestCases = {
  part1: [
    {
      input: `##########
#..O..O.O#
#......O.#
#.OO..O.O#
#..O@..O.#
#O#..O...#
#O..O..O.#
#.OO.O.OO#
#....O...#
##########

<vv>^<v^>v>^vv^v>v<>v^v<v<^vv<<<^><<><>>v<vvv<>^v^>^<<<><<v<<<v^vv^v>^
vvv<<^>^v^^><<>>><>^<<><^vv^^<>vvv<>><^^v>^>vv<>v<<<<v<^v>^<^^>>>^<v<v
><>vv>v^v^<>><>>>><^^>vv>v<^^^>>v^v^<^^>v^^>v^<^v>v<>>v^v^<v>v^^<^^vv<
<<v<^>>^^^^>>>v^<>vvv^><v<<<>^^^vv^<vvv>^>v<^^^^v<>^>vvvv><>>v^<<^^^^^
^><^><>>><>^^<<^^v>>><^<v>^<vv>>v>>>^v><>^v><<<<v>>v<v<v>vvv>^<><<>^><
^>><>^v<><^vvv<^^<><v<<<<<><^v<<<><<<^^<v<^^^><^>>^<v^><<<^>>^v<v^v<v^
>^>>^v>vv>^<<^v<>><<><<v<<v><>v<^vv<<<>^^v^>^^>>><<^v>>v^v><^^>>^<>vv^
<><^^>^^^<><vvvvv^v<v<<>^v<v>v<<^><<><<><<<^^<<<^<<>><<><^^^>^^<>^>v<>
^^>vv<^v^v<vv>^<><v<^v>^^^>>>^^vvv^>vvv<>>>^<^>>>>>^<<^v>^vvv<>^<><<v>
v^^>>><<^^<>>^v^<v^vv<>v^<<>^<^v^v><^<<<><<^<v><v<>vv>>v><v^<vv<>v^<<^`,
      expectedOutput: 10092,
    },
    {
      input: `########
#..O.O.#
##@.O..#
#...O..#
#.#.O..#
#...O..#
#......#
########

<^^>>>vv<v>>v<<`,
      expectedOutput: 2028,
    },
  ],
  part2: [
    {
      input: `#######
#.#...#
#.....#
#..OO@#
#..O..#
#.....#
#######

<vv<<^<^`,
      // <vv<<^^<<^^`,
      expectedOutput: 0,
    },
    {
      input: `##########
#..O..O.O#
#......O.#
#.OO..O.O#
#..O@..O.#
#O#..O...#
#O..O..O.#
#.OO.O.OO#
#....O...#
##########

<vv>^<v^>v>^vv^v>v<>v^v<v<^vv<<<^><<><>>v<vvv<>^v^>^<<<><<v<<<v^vv^v>^
vvv<<^>^v^^><<>>><>^<<><^vv^^<>vvv<>><^^v>^>vv<>v<<<<v<^v>^<^^>>>^<v<v
><>vv>v^v^<>><>>>><^^>vv>v<^^^>>v^v^<^^>v^^>v^<^v>v<>>v^v^<v>v^^<^^vv<
<<v<^>>^^^^>>>v^<>vvv^><v<<<>^^^vv^<vvv>^>v<^^^^v<>^>vvvv><>>v^<<^^^^^
^><^><>>><>^^<<^^v>>><^<v>^<vv>>v>>>^v><>^v><<<<v>>v<v<v>vvv>^<><<>^><
^>><>^v<><^vvv<^^<><v<<<<<><^v<<<><<<^^<v<^^^><^>>^<v^><<<^>>^v<v^v<v^
>^>>^v>vv>^<<^v<>><<><<v<<v><>v<^vv<<<>^^v^>^^>>><<^v>>v^v><^^>>^<>vv^
<><^^>^^^<><vvvvv^v<v<<>^v<v>v<<^><<><<><<<^^<<<^<<>><<><^^^>^^<>^>v<>
^^>vv<^v^v<vv>^<><v<^v>^^^>>>^^vvv^>vvv<>>>^<^>>>>>^<<^v>^vvv<>^<><<v>
v^^>>><<^^<>>^v^<v^vv<>v^<<>^<^v^v><^<<<><<^<v><v<>vv>>v><v^<vv<>v^<<^`,
      expectedOutput: 9021,
    },
  ],
};

const solution: Solution = {
  part1,
  part2,
  testCases,
};

export default solution;
