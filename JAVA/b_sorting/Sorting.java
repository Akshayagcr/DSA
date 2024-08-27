package b_sorting;

import java.util.*;

public class Sorting {

    private static void printArray(int[] arr){
        for(int ele : arr){
            System.out.print(ele + " ");
        }
    }

    private static void selectionSort(int[] arr){
        // Select minimums
        int temp;
        for(int i = 0; i < arr.length - 1; i++){
            int min = i;
            for(int j = i; j < arr.length; j++){
                if(arr[j] < arr[min]){
                    min = j;
                }
            }
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }

    private static void bubbleSort(int[] arr){
        // push maximum to last by adjacent swapping
        int temp;
        for(int i = arr.length - 2; i >= 0; i--){
            for(int j = 0; j <= i; j++){
                if(arr[j] > arr[j + 1]){
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    private static void insertionSort(int[] arr){
        // Takes an element and places it in correct order
        int key, j;
        for(int i = 1; i < arr.length; i++){
            key = arr[i];
            j = i - 1;
            while(j >= 0 && arr[j] > key){
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    private static void mergeSort(int[] arr, int start, int end){
        if(start < end){
            int mid = (start + end) / 2;
            mergeSort(arr, start, mid);
            mergeSort(arr, mid + 1, end);
            merge(arr, start, mid, end);
        }
    }

    private static void merge(int[] arr, int start, int mid, int end){
        int n1 = (mid - start + 1) + 1;
        int n2 = (end - mid) + 1;
        int left[] = new int[n1];
        int right[] = new int[n2];
        left[n1 - 1] = right[n2 - 1] = Integer.MAX_VALUE;
        int i = 0;
        for(int j = start; j <= mid; j++){
            left[i] = arr[j];
            i++;
        }
        i = 0;
        for(int j = mid + 1; j <= end; j++){
            right[i] = arr[j];
            i++;
        }
        i = 0;
        int j = 0;
        for(int k = start; k <= end; k++){
            if(left[i] <= right[j]){
                arr[k] = left[i];
                i++;
            } else {
                arr[k] = right[j];
                j++;
            }
        }
    }

    private static void quickSort(int[] arr, int start, int end){
        if(start < end){
            int partition = partition(arr, start, end);
            quickSort(arr, start, partition - 1);
            quickSort(arr, partition + 1, end);
        }
    }

    private static int partition(int[] arr, int start, int end){
        int i = start, temp;
        for(int j = start + 1; j <= end; j++){
            if(arr[j] <= arr[start]){
                i++;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;
        return i;
    }

    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i = 0; i < n; i++){
            arr[i] = sc.nextInt();
        }

        // selectionSort(arr);
        // bubbleSort(arr);
        // insertionSort(arr);
        // mergeSort(arr, 0, arr.length - 1);
        quickSort(arr, 0, arr.length - 1);
        printArray(arr);
    }
}
