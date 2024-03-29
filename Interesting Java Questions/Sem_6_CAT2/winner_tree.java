/*
(Qs)
 Suppose you are given an array representing the scores of players in a competition.
  Each player is represented by an index in the array, and their corresponding score is the value at that index. 
   Write a Java program  that finds the index of the player with the highest score. . 
   Test your program with the following array of player scores: {3, 7, 1, 9, 4, 2, 8, 5}
*/
/*
class Main {
    public static void main(String[] args) {
        int[] scores = {3, 7, 1, 9, 4, 2, 8, 5};
        findHighestScoreIndex(scores);
    }
    
    public static void findHighestScoreIndex(int[] scores) {
        int maxIndex = 0;
        int minIndex=0;
        int maxScore = scores[0];
        int minScore = Integer.MAX_VALUE;
        
        for (int i = 1; i < scores.length; i++) {
            if (scores[i] > maxScore) {
                maxScore = scores[i];
                maxIndex = i;
            }
        }
        for(int i=1;i<scores.length;i++){
            if(scores[i]<minScore){
                minScore=scores[i];
                minIndex=i;
            }
        }
        System.out.println(maxIndex);
        System.out.println(maxScore);
        
        System.out.println(minIndex);
        System.out.println(minScore);
    }
}
*/

//Using Winner Tree

public class WinnerTree {
    private int[] tree;
    private int[] players;
    private int numPlayers;

    public WinnerTree(int[] players) {
        this.players = players;
        this.numPlayers = players.length;
        int treeSize = 2 * numPlayers - 1;
        this.tree = new int[treeSize];
        buildWinnerTree();
    }

    private void buildWinnerTree() {
        for (int i = numPlayers - 1; i < tree.length; i++) {
            tree[i] = i - (numPlayers - 1);
        }
        for (int i = numPlayers - 2; i >= 0; i--) {
            tree[i] = players[tree[2 * i + 1]] < players[tree[2 * i + 2]] ? tree[2 * i + 2] : tree[2 * i + 1];
        }
    }

    public int getWinnerIndex() {
        return tree[0];
    }

    public static void main(String[] args) {
        int[] players = {3, 7, 1, 9, 4, 2, 8, 5};
        WinnerTree winnerTree = new WinnerTree(players);
        System.out.println("Index of the player with the highest score: " + winnerTree.getWinnerIndex());
    }
}
