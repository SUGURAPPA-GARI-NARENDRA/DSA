import java.util.*;
public class TwoSum {
    int[] Twosum(int []nums,int target){
        for(int i=0;i<nums.length;i++){
            for(int j=i+1;j<nums.length;j++){
                int sum = nums[i]+nums[j];
                if(sum==target){
                    System.out.println(i+","+j);
                    return new int[]{i,j};
                }
            }
        }
        return new int[]{-1-1};
    }
}
class main{
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
         int i;
        System.out.println("Enter the size :: ");
        int n = sc.nextInt();
        System.out.println("Enter the Target Element :: ");
        int target = sc.nextInt();
        int nums[] = new int[n];
        System.out.println("Enter the Elements :: ");
        for(i=0;i<n;i++){
            nums[i]=sc.nextInt();
        }
        TwoSum obj = new TwoSum();
        System.out.print(obj.Twosum(nums,target));
    }
}