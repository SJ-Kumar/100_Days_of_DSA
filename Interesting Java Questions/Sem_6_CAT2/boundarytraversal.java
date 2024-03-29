//Time Complexity: 
//		O(n) where n is the number of nodes.
//Space Complexity: 
//		O(h) where h is the height of the tree (O(n) in the worst case, O(log n) in a balanced tree).

import java.util.Scanner;

class TreeNode {
    int val;
    TreeNode left, right;

    public TreeNode(int value) {
        val = value;
        left = right = null;
    }
}

class Main {

    private static void printLeaves(TreeNode root) {
        if (root != null) {
            printLeaves(root.left);
            if (root.left == null && root.right == null) System.out.print(root.val + " ");
            printLeaves(root.right);
        }
    }

    public static void boundaryTraversal(TreeNode root) {
        if (root != null) {
            System.out.print(root.val + " ");
            printLeaves(root.left);
            printLeaves(root.right);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter the value for the root node: ");
        int rootValue = scanner.nextInt();
        TreeNode root = new TreeNode(rootValue);
        
        System.out.println("Enter the left child value for the root node (or -1 if none): ");
        int leftChildValue = scanner.nextInt();
        if (leftChildValue != -1) {
            root.left = new TreeNode(leftChildValue);
        }
        
        System.out.println("Enter the right child value for the root node (or -1 if none): ");
        int rightChildValue = scanner.nextInt();
        if (rightChildValue != -1) {
            root.right = new TreeNode(rightChildValue);
        }

        // Calling the boundaryTraversal function
        boundaryTraversal(root);
    }
}
