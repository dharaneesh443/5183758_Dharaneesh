import java.util.*;
public class Solution {
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        int[] arr=new int[5];
        for(int i=0;i<5;i++){
            arr[i]=sc.nextInt();
        }
        int min=arr[0];
        int max=arr[0];
        long sum=0;
        for(int i=0;i<5;i++){
            sum+=arr[i];
            if(arr[i]<min)
            min=arr[i];
            if(arr[i]>max)
            max=arr[i];
        }
        long minSum= sum-max;
        long maxSum= sum-min;
        System.out.println(minSum + " " + maxSum);
    }
}