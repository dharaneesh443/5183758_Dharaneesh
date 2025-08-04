import java.util.*;
public class Solution {
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[] arr=new int[n];
        int positives=0;
        int negatives=0;
        int zeros=0;
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        for(int i=0;i<n;i++){
            if(arr[i]>0){
                positives++;
            }
            else if(arr[i]<0){
                negatives++;
            }
            else{
                zeros++;
            }
        }
        System.out.printf("%.6f\n",(double)positives/n);
        System.out.printf("%.6f\n",(double)negatives/n);
         System.out.printf("%.6f\n",(double)zeros/n);
    }
}