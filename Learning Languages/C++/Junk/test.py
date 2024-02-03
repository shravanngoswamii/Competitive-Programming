class Node:
    def __init__(self, key, priority):
        self.key = key
        self.priority = priority
        self.left = None
        self.right = None

class PriorityQueueBST:
    def __init__(self):
        self.root = None

    def insert(self, key, priority):
        self.root = self._insert(self.root, key, priority)

    def _insert(self, root, key, priority):
        if root is None:
            return Node(key, priority)

        if priority < root.priority:
            root.left = self._insert(root.left, key, priority)
        else:
            root.right = self._insert(root.right, key, priority)

        return root

    def delete_min(self):
        if self.root is None:
            return None

        min_node = self._find_min(self.root)
        self.root = self._delete_min(self.root)
        return min_node.key

    def _find_min(self, root):
        current = root
        while current.left is not None:
            current = current.left
        return current

    def _delete_min(self, root):
        if root.left is None:
            return root.right
        root.left = self._delete_min(root.left)
        return root

    def display(self):
        self._display(self.root)

    def _display(self, root):
        if root:
            self._display(root.left)
            print(f"Key: {root.key}, Priority: {root.priority}")
            self._display(root.right)

# Example:
pq = PriorityQueueBST()
pq.insert(5, 10)
pq.insert(3, 5)
pq.insert(7, 8)
pq.insert(2, 15)

print("Priority Queue:")
pq.display()

print("\nDequeue elements based on priority:")
while True:
    key = pq.delete_min()
    if key is not None:
        print(f"Dequeued: {key}")
    else:
        break
