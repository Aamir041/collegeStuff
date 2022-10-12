public class MergeSort{

    static void merge(int arr[],int left,int mid,int right){

        int lenSubarr1 = mid - left + 1;
        int lenSubarr2 = right - mid;

        int subArr1[] = new int[lenSubarr1];
        int subArr2[] = new int[lenSubarr2];

        // creating sub arrays 
        for(int i=0;i<lenSubarr1;++i)
            subArr1[i] = arr[left+i];
        
        for(int j=0;j<lenSubarr2;++j)
            subArr2[j]=arr[mid+1+j];
        
        // tracker for sub arrrays
        int tckr1,tckr2;
        tckr1=tckr2=0;

        // tracker for main array
        int arrTckr = left;

        // sorting
        while(tckr1<lenSubarr1 && tckr2<lenSubarr2){
            if(subArr1[tckr1] < subArr2[tckr2]){
                arr[arrTckr] = subArr1[tckr1];
                tckr1++;
            }
            else{
                arr[arrTckr] = subArr2[tckr2];
                tckr2++;
            }
            arrTckr++;
        }

        // if any one sub array if fully traversed

        while(tckr1<lenSubarr1){
            arr[arrTckr] = subArr1[tckr1];
            tckr1++;
            arrTckr++;
        }

        while(tckr2<lenSubarr2){
            arr[arrTckr] = subArr2[tckr2];
            tckr2++;
            arrTckr++;
        }
        
    }

    static void sort(int arr[], int left, int right){
        if(left < right){
            int mid = (left+right)/2;
            sort(arr,left,mid);
            sort(arr,mid+1,right);

            merge(arr,left,mid,right);
        }
    }

    static void printArray(int arr[]){
        for(int i=0;i<arr.length;i++){
            System.out.print(arr[i]+" ");
        }
        System.out.println();
    }
    public static void main(String args[]){
        int[] arr = {45,28,37,88,57,22,66,76};
        
        System.out.println("Unsorted Array");
        printArray(arr);

        sort(arr, 0, arr.length-1);

        System.out.println("Sorted Array");
        printArray(arr);

    }
}