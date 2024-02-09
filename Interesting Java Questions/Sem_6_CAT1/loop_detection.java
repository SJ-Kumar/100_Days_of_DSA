import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        LinkedList list = new LinkedList();

        System.out.print("Enter the number of elements in the linked list: ");
        int n = scanner.nextInt();

        System.out.println("Enter the elements:");
        for (int i = 0; i < n; i++) {
            int data = s.nextInt();
            list.push(data);
        }

        // Detect loop and print result
        list.detectLoopAndPrint();

        s.close();
    }

    public static class LinkedList {
        // 1. Node structure
        static class Node {
            int data;
            Node next;

            Node(int d) {
                data = d;
                next = null;
            }
        }

        // 2. push operation
        Node head;

        void push(int newData) {
            Node newNode = new Node(newData);
            newNode.next = head;
            head = newNode;
        }

        // 3. detect loop
        void detectLoopAndPrint() {
            Node slow = head, fast = head;
            while (slow != null && fast != null && fast.next != null) {
                slow = slow.next;
                fast = fast.next.next;
                if (slow == fast) {
                    System.out.println("Loop found");
                    return;
                }
            }
            System.out.println("Loop not found");
        }
    }
}
