import java.util.Scanner;

public class Main {
    public static class LinkedList {
        static class Node {
            int data;
            Node next;
            Node(int d) {
                data = d;
                next = null;
            }
        }
        Node head;
        Node evenHead = null;
        Node oddHead = null;

        void push(int newData) {
            Node newNode = new Node(newData);
            newNode.next = head;
            head = newNode;
        }

        void segregateEvenOdd() {
            Node current = head;
            while (current != null) {
                Node nextNode = current.next;
                if (current.data % 2 == 0) {
                    current.next = evenHead;
                    evenHead = current;
                } else {
                    current.next = oddHead;
                    oddHead = current;
                }
                current = nextNode;
            }
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

        void printList() {
            Node temp = head;
            while (temp != null) {
                System.out.print(temp.data + " ");
                temp = temp.next;
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        LinkedList list = new LinkedList();
        int n = s.nextInt();
        for (int i = 0; i < n; i++) {
            int data = s.nextInt();
            list.push(data);
        }
        list.printList();

        list.segregateEvenOdd();
        list.printList();

        s.close();
    }
}
