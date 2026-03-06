import java.util.*;
public class MoveZeors {
    void MoveZeorsToLast(int nums[]){
        int last =0;
        for(int i =0;i<nums.length;i++){
        if(nums[i]!=0){
         int temp = nums[i];
         nums[i]=nums[last];
         nums[last]=temp;
         last++;
        }
        }
    }
}
class main{
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
         int i;
        System.out.println("Enter the size :: ");
        int n = sc.nextInt();
        //int target = sc.nextInt();
        int nums[] = new int[n];
        System.out.println("Enter the Elements :: ");
        for(i=0;i<n;i++){
            nums[i]=sc.nextInt();
        }
        MoveZeors obj= new MoveZeors();
        obj.MoveZeorsToLast(nums);

        System.out.println("Array after moving zeros to last:");
        for (int num : nums) {
            System.out.print(num + " ");
    }
sc.close();
}
}
