import fs from "fs";
import path from "path";
import { Solution, Status } from "./types";

function sliceString(input: string): string {
  return input.length > 100 ? `${input.slice(0, 100)}...` : input;
}

function parseTime(ms: number): number {
  return Math.round(ms);
}

async function main() {
  const args = process.argv.slice(2);

  const day = args.shift();

  if (!day) {
    console.error(`Usage: yarn start <day> [-p1] [-p2] [-t]`);
    process.exit(1);
  }

  const p1Flag = args.includes("-p1");
  const p2Flag = args.includes("-p2");
  const partFlagExists = p1Flag || p2Flag;

  const execP1 = partFlagExists ? p1Flag : true;
  const execP2 = partFlagExists ? p2Flag : true;

  const testMode = args.includes("-t");

  const src_file = `./days/day${day}`;

  if (!fs.existsSync(src_file)) {
    console.error(`Source file ${src_file}.ts does not exist`);
    process.exit(1);
  }

  try {
    const module: Solution = await import(src_file).then((r) => r.default);

    const stats: Status[] = [];

    if (testMode) {
      const testCases = module.testCases;
      if (execP1) {
        for (let i = 0; i < testCases.part1.length; i++) {
          const { input, expectedOutput } = testCases.part1[i];
          const now = performance.now();
          const output = module.part1(input);
          const elapesed = performance.now() - now;
          stats.push({
            part: 1,
            case: i + 1,
            input: input.length > 100 ? `${input.slice(0, 100)}...` : input,
            output,
            expectedOutput,
            passed: output === expectedOutput,
            time: parseTime(elapesed),
          });
        }
      }

      if (execP2) {
        for (let i = 0; i < testCases.part2.length; i++) {
          const { input, expectedOutput } = testCases.part2[i];
          const now = performance.now();
          const output = module.part1(input);
          const elapesed = performance.now() - now;
          stats.push({
            part: 2,
            case: i + 1,
            input: input.length > 100 ? `${input.slice(0, 100)}...` : input,
            output,
            expectedOutput,
            passed: output === expectedOutput,
            time: parseTime(elapesed),
          });
        }
      }
    } else {
      const inputFile = path.resolve(__dirname, `./inputs/day${day}.inp`);
      if (!fs.existsSync(inputFile)) {
        console.error(`Input file ${inputFile} does not exist`);
        process.exit(1);
      }
      const inputText = fs.readFileSync(inputFile, "utf8").trim();

      if (execP1) {
        const now = performance.now();
        const answer = module.part1(inputText);
        const elapesed = performance.now() - now;
        stats.push({
          part: 1,
          case: 0,
          input: sliceString(inputText),
          output: answer,
          expectedOutput: "-",
          passed: true,
          time: parseTime(elapesed),
        });
      }

      if (execP2) {
        const now = performance.now();
        const answer = module.part1(inputText);
        const elapesed = performance.now() - now;
        stats.push({
          part: 2,
          case: 0,
          input: sliceString(inputText),
          output: answer,
          expectedOutput: "-",
          passed: true,
          time: parseTime(elapesed),
        });
      }
    }

    const columns = testMode
      ? ["part", "case", "input", "expectedOutput", "output", "passed", "time"]
      : ["part", "input", "output", "time"];

    console.table(stats, columns);
  } catch (err) {
    console.error(err);
  }
}

main();
