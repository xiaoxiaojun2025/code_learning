import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static BigInteger calculate(int n){
        BigInteger res=BigInteger.ONE;
        if(n<0) return BigInteger.ZERO;
        if(n==0||n==1) return BigInteger.ONE;
        for(int i=1;i<=n;i++){
            res=res.multiply(BigInteger.valueOf(i));
        }
        return res;
    }
    public static BigInteger sum(int n){
        BigInteger res=BigInteger.ZERO;
        if(n<=0) return BigInteger.ZERO;
        if(n==1) return BigInteger.ONE;
        for(int i=1;i<=n;i++){
            res=res.add(calculate(i));
        }
        return res;
    }
    public static void main(String[] args) {
        Scanner n =new Scanner(System.in);
        System.out.println(sum(n.nextInt()));
    }
}