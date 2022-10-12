public class QuickSort {

    static void quickSort(int arr[], int i, int j){
        if(i<j){
            int p = partition(arr, i, j);
            quickSort(arr, i, p-1);
            quickSort(arr, p+1, j);
        }
    }

    static int partition(int arr[],int q, int r){
        int pivot=arr[r];
        
        int m=(q-1);

        for(int n=q;n<r;n++){
            if(arr[n] < pivot){
                m++;
                swap(arr, m, n);
            }
        }
        swap(arr, m+1, r);
        return m+1;
    }

    static void swap(int arr[], int s, int t){
        int temp;
        temp = arr[s];
        arr[s] = arr[t];
        arr[t] = temp;
    }

    public static void main(String[] args){
        int[] arr = {2,8,7,1,3,5,6,4};
        quickSort(arr,0,arr.length-1);

        for(int x = 0; x<arr.length; x++){
            System.out.print(arr[x] + " ");
        }
        System.out.println(" ");
     }

}
