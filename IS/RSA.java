import java.util.*;
import java.math.*;

public class RSA{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter Message Length: ");
        int m = sc.nextInt();
        
        System.out.print("Enter Value of p: ");
        int p =sc.nextInt();
        
        System.out.print("Enter Value of q: ");
        int q = sc.nextInt();
        
        int n = p*q;
        int phiN = (p-1)*(q-1);

        int e = 1;
        for(int i = 2; i<phiN; i++){
            if(gcd(i,phiN) == 1){
                e = i;
                break;
            }
        }
        System.out.println("The value of e : "+e);
        
        int d = 0;
        int j=0;
        while(true){
            if((e*j)%phiN == 1){
                d = j;
                break;
            }
            j++;
        }
        System.out.println("The value of d : "+d);

        double c = Math.pow(m,e)%n;

        BigInteger N = BigInteger.valueOf(n);
        BigInteger C = BigDecimal.valueOf(c).toBigInteger();
        System.out.println("Encrypted message is : "+C);
        BigInteger M = C.pow(d).mod(N);
        System.out.println("Decrypted message is : "+M);

    }

    static int gcd(int n1, int n2){
        if(n1 == 0){
            return n2;
        }
        return gcd(n2%n1, n1);
    }
}