import java.util.Arrays;

public class RailFence {
    public static void main(String[] args) {
        
        char[][] cipherArray = encryptArray(5, "aamirsaudagar");
        
        String cipherText = cipher(cipherArray);
        System.out.println(cipherText);

        String encipherText = decrypt(cipherArray);
        System.out.println(encipherText);

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
