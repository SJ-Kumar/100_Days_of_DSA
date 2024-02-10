class Node {
    int data;
    Node next;
    Node prev;

    Node(int data) {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}

public class PriorityQueue {
    Node head;
    Node tail;

    PriorityQueue() {
        head = null;
        tail = null;
    }

    void enqueue(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
            tail = newNode;
        } else {
            Node current = head;
            while (current != null && current.data < data) {
                current = current.next;
            }
            if (current == null) {
                tail.next = newNode;
                newNode.prev = tail;
                tail = newNode;
            } else {
                if (current.prev == null) {
                    newNode.next = head;
                    head.prev = newNode;
                    head = newNode;
                } else {
                    current.prev.next = newNode;
                    newNode.prev = current.prev;
                    newNode.next = current;
                    current.prev = newNode;
                }
            }
        }
    }

    int dequeue() {
        if (head == null) {
            System.out.println("Queue is empty");
            return -1;
        }
        int data = head.data;
        head = head.next;
        if (head != null) {
            head.prev = null;
        }
        return data;
    }

    void printQueue() {
        Node current = head;
        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        PriorityQueue pq = new PriorityQueue();
        pq.enqueue(5);
        pq.enqueue(2);
        pq.enqueue(7);
        pq.enqueue(1);

        pq.printQueue();

        System.out.println("Dequeue: " + pq.dequeue());
        System.out.println("Dequeue: " + pq.dequeue());

        pq.printQueue();
    }
}
