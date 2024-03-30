import java.util.Scanner;

class TreeNode {
    int val;
    TreeNode left, right;

    TreeNode(int value) {
        val = value;
        left = right = null;
    }
}

public class BSTRecovery {
    TreeNode firstElement = null;
    TreeNode secondElement = null;
    TreeNode prevElement = new TreeNode(Integer.MIN_VALUE);

    public TreeNode insert(TreeNode root, int key) {
        if (root == null)
            return new TreeNode(key);
        
        if (root.val < key) {
            root.right = insert(root.right, key);
        } else {
            root.left = insert(root.left, key);
        }
        return root;
    }

    public void recoverTree(TreeNode root) {
        // Inorder traversal to find the misplaced elements
        inorder(root);

        // Swap the values of the two misplaced elements
        int temp = firstElement.val;
        firstElement.val = secondElement.val;
        secondElement.val = temp;
    }

    private void inorder(TreeNode root) {
        if (root == null)
            return;

        // Traverse left subtree
        inorder(root.left);

        // If this node is smaller than the previous node, it's misplaced
        if (firstElement == null && root.val < prevElement.val) {
            firstElement = prevElement;
        }

        if (firstElement != null && root.val < prevElement.val) {
            secondElement = root;
        }

        prevElement = root;

        // Traverse right subtree
        inorder(root.right);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the elements of the tree separated by spaces (use -1 for missing nodes):");
        String[] input = scanner.nextLine().split(" ");
        TreeNode root = null;
        BSTRecovery bstRecovery = new BSTRecovery();
        
        for (String node : input) {
            if (!node.equals("-1")) {
                int value = Integer.parseInt(node);
                root = bstRecovery.insert(root, value);
            }
        }

        bstRecovery.recoverTree(root);

        // Printing the recovered tree
        System.out.println("Recovered BST:");
        inorderTraversal(root);
    }

    private static void inorderTraversal(TreeNode root) {
        if (root == null)
            return;

        inorderTraversal(root.left);
        System.out.print(root.val + " ");
        inorderTraversal(root.right);
    }
}
