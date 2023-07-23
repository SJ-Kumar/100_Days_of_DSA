import java.util.*;

class Hypen{
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);
        String S=s.nextLine();
        String result=hy(S);
        System.out.println("Original String: "+S);
        System.out.println("Modified String: "+result);
    }
    public static String hy(String w){
        StringBuilder hypens = new StringBuilder();
        StringBuilder remaining = new StringBuilder();
        
        for(int i=0;i<w.length();i++){
            char ch=w.charAt(i);
            if(ch=='-'){
                hypens.append(ch);
            }
            else{
                remaining.append(ch);
            }
        }
        return hypens.append(remaining).toString();
    }
}
