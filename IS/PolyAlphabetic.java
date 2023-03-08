import java.util.Scanner;

public class PolyAlphabetic {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter plain text: ");
        String plainText = sc.next();
        
        String keyWord = generateKeyWord(plainText.toLowerCase());
        System.out.println(keyWord);

        String cipherText = encrypt(keyWord, plainText.toLowerCase());
        System.out.println("Cipher Text: "+cipherText);

        String encipherText = decipher(keyWord, cipherText);
        System.out.println("Encipher Text: " +encipherText);

    }

    static String encrypt(String keyWord, String plainText){
        String res = "";

        char[][] vignereTable = new char[26][26];

        for(int i=0; i<26; i++){
            for(int j=0; j<26; j++){
                if(97+i+j <= 122){
                    vignereTable[i][j] = (char)(97+i+j);
                }
                else{
                    vignereTable[i][j] = (char)(97+i+j-26);
                }
            }   
        }

        int n = keyWord.length();

        for(int i=0; i<n; i++){
            res = res + vignereTable[keyWord.charAt(i) - 'a'][plainText.charAt(i) - 'a'];
        }

        return res;
    }

    static String generateKeyWord(String plaintText){
        
        int plainTextLen = plaintText.length();
        
        String key = "key";
        
        String keyWord = "";

        int j = 0;
        for(int i=0; i<plainTextLen; i++){
            if(j >= key.length()){
                j = 0;
            }
            keyWord = keyWord + key.charAt(j);
            j++;
        }

        return keyWord;
    }

    static String decipher(String keyWord, String cipher){

        String enchiper = "";

        char[][] vignereTable = new char[26][26];

        for(int i=0; i<26; i++){
            for(int j=0; j<26; j++){
                if(97+i+j <= 122){
                    vignereTable[i][j] = (char)(97+i+j);
                }
                else{
                    vignereTable[i][j] = (char)(97+i+j-26);
                }
            }   
        }

        for(int i=0; i<cipher.length(); i++){
            
            for(int j=0; j<26; j++){

                if(vignereTable[keyWord.charAt(i)-'a'][j] == cipher.charAt(i)){
                    enchiper = enchiper + vignereTable[0][j];
                }

            }

        }

        return enchiper;
    }

}
