export class PriorityQueue<T> {
  values: { node: T; priority: number }[] = [];
  type: "min" | "max" = "min";
  constructor(type?: "min" | "max") {
    if (type) this.type = type;
  }

  enqueue(node: T, priority: number) {
    let flag = false;
    for (let i = 0; i < this.values.length; i++) {
      if (this.values[i].priority < priority) {
        this.values.splice(i, 0, { node, priority });
        flag = true;
        break;
      }
    }
    if (!flag) {
      this.values.push({ node, priority });
    }
  }

  dequeue() {
    return this.type === "min" ? this.values.pop() : this.values.shift();
  }

  get size() {
    return this.values.length;
  }
}
