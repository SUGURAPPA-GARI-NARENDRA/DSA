import java.util.*;
class Solution{
    public int Largest(int a[]){
       int larger = a[0];
       int i;
       for(i=1;i<a.length;i++){
            if(a[i]>larger){
                larger = a[i];
       }
    }
    return larger;
}
}
public class LargestElement{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int i,j;
        System.out.println("Enter the size :: ");
        int n = sc.nextInt();
        //int target = sc.nextInt();
        int a[] = new int[n];
        for(i=0;i<n;i++){
            a[i]=sc.nextInt();
        }
        Solution obj = new Solution();
        System.out.println(obj.Largest(a));
        
    }
}