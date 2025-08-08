#include <stdio.h>
int Uniqueelement(int arr[],int n){
    int result=0;
    for(int i=0;i<n;i++){
        result^=arr[i];
    }
    return result;
}
int main(){
 int n;
 scanf("%d",&n);
 int arr[n];
 for (int i=0;i<n;i++) {
    scanf("%d",&arr[i]);
 }   
 printf("%d\n",Uniqueelement(arr, n));
 return 0;
}