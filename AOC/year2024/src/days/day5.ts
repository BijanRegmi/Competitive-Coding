import { Solution, TestCases } from "../types";
type ParseResult = { notBeforeMap: Map<number, number[]>; updates: number[][] };

function parseRawInput(rawInput: string): ParseResult {
  const [orders, updates] = rawInput.split("\n\n");

  const result: ParseResult = { notBeforeMap: new Map(), updates: [] };

  orders.split("\n").forEach((order) => {
    const [left, right] = order.split("|").map(Number);

    const existingRightNumbers = result.notBeforeMap.get(left) || [];
    existingRightNumbers.push(right);
    result.notBeforeMap.set(left, existingRightNumbers);
  });

  updates
    .split("\n")
    .forEach((update) => result.updates.push(update.split(",").map(Number)));

  return result;
}

function part1(rawInput: string) {
  const input = parseRawInput(rawInput);
  const { notBeforeMap, updates } = input;

  let ans = 0;

  for (let i = 0; i < updates.length; i++) {
    const pages = updates[i];
    const printedPages = new Set<number>();
    let correct = true;

    for (const page of pages) {
      const notBeforePages = notBeforeMap.get(page) || [];
      if (notBeforePages.some((p) => printedPages.has(p))) {
        correct = false;
        break;
      }
      printedPages.add(page);
    }

    ans += correct ? pages[Math.floor(pages.length / 2)] : 0;
  }

  return ans;
}

function part2(rawInput: string) {
  const input = parseRawInput(rawInput);
  const { notBeforeMap, updates } = input;

  let ans = 0;

  for (let i = 0; i < updates.length; i++) {
    const pages = updates[i];
    const printedPages = new Set<number>();
    let correct = true;

    for (const page of pages) {
      const notBeforePages = notBeforeMap.get(page) || [];
      if (notBeforePages.some((p) => printedPages.has(p))) {
        correct = false;
        break;
      }
      printedPages.add(page);
    }

    if (!correct) {
      const middleIndex = Math.floor(pages.length / 2);
      const middlePage = pages.find((p) => {
        const notBeforePages = notBeforeMap
          .get(p)
          ?.filter((nbp) => pages.includes(nbp));
        if (notBeforePages?.length === middleIndex) return true;
      });
      ans += middlePage || 0;
    }
  }

  return ans;
}

const testCases: TestCases = {
  part1: [
    {
      input: `47|53
97|13
97|61
97|47
75|29
61|13
75|53
29|13
97|29
53|29
61|53
97|53
61|29
47|13
75|47
97|75
47|61
75|61
47|29
75|13
53|13

75,47,61,53,29
97,61,53,29,13
75,29,13
75,97,47,61,53
61,13,29
97,13,75,29,47`,
      expectedOutput: 143,
    },
  ],
  part2: [
    {
      input: `47|53
97|13
97|61
97|47
75|29
61|13
75|53
29|13
97|29
53|29
61|53
97|53
61|29
47|13
75|47
97|75
47|61
75|61
47|29
75|13
53|13

75,47,61,53,29
97,61,53,29,13
75,29,13
75,97,47,61,53
61,13,29
97,13,75,29,47`,
      expectedOutput: 123,
    },
  ],
};

const solution: Solution = {
  part1,
  part2,
  testCases,
};

export default solution;
