import java.util.Scanner;

public class ShiftCipher{
    static String encrypt(String str, int k){
        String newStr = "";

        for(int i=0; i<str.length(); i++){
            int number=0;
            if(str.charAt(i)+k > 122){
                number = str.charAt(i) - 26 + k;
            }
            else{
                number =  str.charAt(i)+k;
            }
            newStr = newStr + String.valueOf(Character.toChars(number));
        }
        return newStr;
    }

    static String decrypt(String str, int k){
        String newStr = "";
        
        for(int i=0;i<str.length(); i++){
            int number = 0;
            if(str.charAt(i)-k<97){

                number = str.charAt(i)+26-k;
            }
            else{
                number = str.charAt(i)-k;
            }
            newStr = newStr + String.valueOf(Character.toChars(number));
        }

        return newStr;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        int k = sc.nextInt();
        String encryptedText = encrypt(str, k);
        System.out.println("Encrypt: " + encryptedText);
        System.out.println("Decrypt: " + decrypt(encryptedText, k));

    }
}