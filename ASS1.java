public class ASS1 {



    
    
    //Merge Sort
    public static void merge(int arr[],int si, int mid, int ei){
        int temp[] = new int[ei-si+1];
        int i = si;
        int j = mid+1;
        int k =0;

        while(i<= mid && j<= ei){
            if(arr[i] < arr[j]){
                temp[k] = arr[i];
                i++;
            }else{
                temp[k] = arr[j];
                j++;
            }
            k++;
        }

        while(i<=mid){
            temp[k++] = arr[i++];
        }
        while (j<=ei) {
            temp[k++] = arr[j++];
        }
        //Copy temp to original
        for(k=0,i=si;k<temp.length;k++,i++){
            arr[i] = temp[k];
        }
    }

    public static void mergeSort(int arr[], int si, int ei){
        if(si >= ei){
            return;
        }
        int mid = si + (ei -si) / 2;
        mergeSort(arr, si, mid);
        mergeSort(arr, mid+1, ei);

        merge(arr,si,mid,ei);
    }

    //Quick Sort
    public static void quickSort(int arr[],int si, int ei){
        if(si >= ei){
            return;
        }
        int pIdx = partition(arr, si, ei);
        quickSort(arr, si, pIdx-1);
        quickSort(arr, pIdx+1, ei);
    }

    public static int partition(int arr[], int si, int ei){
        int pivot = arr[ei];
        int i = si -1;

        for(int j =si;j< ei;j++){
            if(arr[j] <= pivot){ //Need to Change
                i++;
                //Swap
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
        i++;
        //Swap
        int temp = pivot;
        arr[ei] = arr[i];
        arr[i] = temp;
        return i;
    }


    //Bubble Sort
    public static void bubbleSort(int arr[]){
        for(int i = 0;i < arr.length-1;i++){
            for(int j = 0;j< arr.length-1-i;j++){
                if(arr[j] > arr[j+1]){
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    }


    public static void main(String[] args) {
        int arr[] = {5, 3, 6, 2, 9, 1};
        bubbleSort(arr);
        for(int i =0;i< arr.length;i++){
            System.out.print(arr[i]+ " ");
        }
        System.out.println();

    }
}
