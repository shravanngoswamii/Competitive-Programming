# Define a struct for PriorityQueueNode
struct PriorityQueueNode
    data::Any
    priority::Int
    next::Union{PriorityQueueNode, Nothing}
end

# Define a struct for PriorityQueue
struct PriorityQueue
    front::Union{PriorityQueueNode, Nothing}
end

# Constructor for PriorityQueueNode
function PriorityQueueNode(value, pr)
    PriorityQueueNode(value, pr, nothing)
end

# Constructor for PriorityQueue
function PriorityQueue()
    PriorityQueue(nothing)
end

# Method to check if Priority Queue is Empty
function isEmpty(pq::PriorityQueue)
    return isnothing(pq.front)
end

# Method to add items to Priority Queue
function push(pq::PriorityQueue, value, priority)
    if isEmpty(pq)
        pq.front = PriorityQueueNode(value, priority)
        return 1
    else
        if pq.front.priority < priority
            newNode = PriorityQueueNode(value, priority)
            newNode.next = pq.front
            pq.front = newNode
            return 1
        else
            temp = pq.front
            while !isnothing(temp.next)
                if priority >= temp.next.priority
                    break
                end
                temp = temp.next
            end

            newNode = PriorityQueueNode(value, priority)
            newNode.next = temp.next
            temp.next = newNode
            return 1
        end
    end
end

# Method to remove the highest priority item from the Priority Queue
function pop(pq::PriorityQueue)
    if isEmpty(pq)
        return
    else
        pq.front = pq.front.next
        return 1
    end
end

# Method to return the highest priority node value without removing it
function peek(pq::PriorityQueue)
    if isEmpty(pq)
        return
    else
        return pq.front.data
    end
end

# Method to traverse through Priority Queue
function traverse(pq::PriorityQueue)
    if isEmpty(pq)
        return "Queue is Empty!"
    else
        temp = pq.front
        while !isnothing(temp)
            print(temp.data, " ")
            temp = temp.next
        end
    end
end

# Driver code
if abspath(PROGRAM_FILE) == @__FILE__
    # Creating an instance of Priority Queue, and adding values
    pq = PriorityQueue()
    push(pq, 4, 1)
    push(pq, 5, 2)
    push(pq, 6, 3)
    push(pq, 7, 0)

    # Traversing through Priority Queue
    traverse(pq)

    # Removing the highest Priority item from the priority queue
    pop(pq)
end
