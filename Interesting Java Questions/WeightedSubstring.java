import java.util.*;

class WeightedSubstring{
    public static int dist(String P,String Q,int K,int N){
        HashSet < String > S = new HashSet < String > ();
        for(int i=0;i<N;i++){
            int sum=0;
            String s="";
            for(int j=i;j<N;j++){
                int pos=P.charAt(j)-'a';
                sum+=Q.charAt(pos)-'0';
                s+=P.charAt(j);
                if(sum<K){
                    S.add(s);
                }
                else{
                  break;
                }
            }
        }
        return S.size();
    }
    public static void main(String args[]){
        Scanner s=new Scanner(System.in);
        String P = s.nextLine();
        String Q = s.nextLine();
        int K=s.nextInt();
        int N=P.length();
        System.out.println(dist(P,Q,K,N));
    }
}
