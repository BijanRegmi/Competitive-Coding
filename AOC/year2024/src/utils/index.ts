export * from "./priorityQueue";

export type Dir = "l" | "r" | "u" | "d";
export const dirs: { [key in Dir]: [number, number] } = {
  l: [-1, 0],
  r: [1, 0],
  u: [0, -1],
  d: [0, 1],
} as const;
