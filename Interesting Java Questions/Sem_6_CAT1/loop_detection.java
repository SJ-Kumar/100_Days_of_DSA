class Main {
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
