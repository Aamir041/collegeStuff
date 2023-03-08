import java.util.Arrays;
import java.util.Scanner;

public class RailFence {
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Dept: ");
        int depth = sc.nextInt();

        System.out.print("Enter Plain Text: ");
        String plainText = sc.next();

        char[][] cipherArray = encryptArray(depth, plainText.toLowerCase());
        
        String cipherText = cipher(cipherArray);
        System.out.println("Ciphered Text: "+cipherText);

        String encipherText = decrypt(cipherArray);
        System.out.println("Enciphered Text: "+encipherText);

    }

    static char[][] encryptArray(int depth, String plainText){

        char[][] table = new char[depth][plainText.length()];
        
        for(int i = 0; i<depth; i++){
            for(int j= 0; j<plainText.length(); j++){
                table[i][j] = '-';
            }
        }

        int row = 0;
        boolean didHitBottom = false;

        for(int i=0; i<plainText.length(); i++){

            table[row][i] = plainText.charAt(i);

            if(didHitBottom == false){
                row++;
            }
            if(didHitBottom == true){
                row--;
            }
            if(row < 0){
                didHitBottom = false;
                row = 1;
            }
            if(row >= depth){
                didHitBottom = true;
                row = row-2;
            }
            
            
        }

        // for debugging purpose REMOVE IT
        // for(int i = 0; i<depth; i++){
        //     System.out.println(Arrays.toString(table[i]));
        // }

        return table;
    }

    static String cipher(char[][] table){
        String cipher = "";
        for(int i=0; i<table.length; i++){

            for(int j=0; j<table[0].length; j++){
                if(table[i][j] != '-'){
                    cipher = cipher + table[i][j];
                }
            }

        }

        return cipher;
    }

    static String decrypt(char[][] table){
        String encipher = "";
        int row = 0;
        boolean didHitBottom = false;

        for(int i=0; i<table[0].length; i++){

            encipher += table[row][i];

            if(didHitBottom == false){
                row++;
            }
            if(didHitBottom == true){
                row--;
            }
            if(row < 0){
                didHitBottom = false;
                row = 1;
            }
            if(row == table.length){
                didHitBottom = true;
                row = row-2;
            }
            
        }

        return encipher;
    }


}
