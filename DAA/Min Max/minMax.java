
public class minMax {
    static int min, max;

    static void rMinMax(int arr[],int i,int j){
        
        int max1;
        int min1;

        if(i == j){
            min = arr[i];
            max = arr[j];
        }
        else if (i == j-1){
            if(arr[i] > arr[j-1]){
                max = arr[i];
                min = arr[j];
            }
            else{
                max = arr[j];
                min = arr[i];
            }
        }
        else{
            int mid = (i + j)/2;
            rMinMax(arr, i, mid);
            max1=max; min1=min;
            rMinMax(arr, mid+1, j);
            if(max1 > max1){
                max=max1;
            }
            if(min1<min){
                min=min1;
            }
            
        }
    }

    public static void main(String[] args){
        int[] arr = {22, 13, -5, -8, 15, 60, 17, 31, 47};
        rMinMax(arr,0, arr.length-1);

        System.out.println("Maximum value: "+max+" Minimum value: "+min);
    }

}
