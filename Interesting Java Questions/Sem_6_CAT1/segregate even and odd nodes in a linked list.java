public class LinkedList {
    // Node structure
    static class Node {
        int data;
        Node next;

        Node(int d) {
            data = d;
            next = null;
        }
    }

    Node head;
    Node evenHead;
    Node oddHead;

    // Function to insert a new node at the beginning of the linked list
    void push(int newData) {
        Node newNode = new Node(newData);
        newNode.next = head;
        head = newNode;
    }

    // Function to segregate even and odd nodes
    void segregateEvenOdd() {
        Node current = head;
        while (current != null) {
            Node nextNode = current.next;
            if (current.data % 2 == 0) {
                // Insert even node into even linked list
                current.next = evenHead;
                evenHead = current;
            } else {
                // Insert odd node into odd linked list
                current.next = oddHead;
                oddHead = current;
            }
            current = nextNode;
        }

        // Merge even and odd lists
        if (evenHead != null) {
            head = evenHead;
            Node temp = evenHead;
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = oddHead;
        } else {
            head = oddHead;
        }
    }

    // Function to print the linked list
    void printList() {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    // Main method for testing
    public static void main(String[] args) {
        LinkedList list = new LinkedList();
        list.push(1);
        list.push(2);
        list.push(3);
        list.push(4);
        list.push(5);
        list.push(6);

        System.out.println("Original linked list:");
        list.printList();

        list.segregateEvenOdd();

        System.out.println("Linked list after segregating even and odd nodes:");
        list.printList();
    }
}
