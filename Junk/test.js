class Node {
    constructor(key, priority) {
        this.key = key;
        this.priority = priority;
        this.left = null;
        this.right = null;
    }
}

class PriorityQueueBST {
    constructor() {
        this.root = null;
    }

    _insert(root, key, priority) {
        if (root === null) {
            return new Node(key, priority);
        }

        if (priority < root.priority) {
            root.left = this._insert(root.left, key, priority);
        } else {
            root.right = this._insert(root.right, key, priority);
        }

        return root;
    }

    _findMin(root) {
        let current = root;
        while (current.left !== null) {
            current = current.left;
        }
        return current;
    }

    _deleteMin(root) {
        if (root.left === null) {
            return root.right;
        }
        root.left = this._deleteMin(root.left);
        return root;
    }

    _display(root) {
        if (root) {
            this._display(root.left);
            console.log(`Key: ${root.key}, Priority: ${root.priority}`);
            this._display(root.right);
        }
    }

    insert(key, priority) {
        this.root = this._insert(this.root, key, priority);
    }

    deleteMin() {
        if (this.root === null) {
            return -1; // Indicates an empty priority queue
        }

        const minNode = this._findMin(this.root);
        const minKey = minNode.key;
        this.root = this._deleteMin(this.root);
        return minKey;
    }

    display() {
        this._display(this.root);
    }
}

// Example usage
const pq = new PriorityQueueBST();
pq.insert(5, 10);
pq.insert(3, 5);
pq.insert(7, 8);
pq.insert(2, 15);

console.log("Priority Queue:");
pq.display();

console.log("\nDequeue elements based on priority:");
while (true) {
    const key = pq.deleteMin();
    if (key !== -1) {
        console.log(`Dequeued: ${key}`);
    } else {
        break;
    }
}
