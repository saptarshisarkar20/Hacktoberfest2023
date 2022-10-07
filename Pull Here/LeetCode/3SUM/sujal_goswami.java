public class sujal_goswami {
    public List<List<Integer>> threeSum(int[] nums) {

       int left, right, i, sum;
       List<List<Integer>> rt = new ArrayList<List<Integer>>();
       if(nums.length<3) return rt;
       Arrays.sort(nums);
       for(i = 0; i < nums.length-2 ; i++){
           sum = 0 - nums[i];left = i+1;right = nums.length-1;
           while(left<right){
               if(nums[left]+nums[right] == sum ){
                   rt.add(Arrays.asList(nums[i],nums[left],nums[right]));
                   while(left<right && nums[left]==nums[1+left]) left++;
                   while(left<right && nums[right]==nums[right-1]) right--;
                   left++;right--;
               } 
               else if(nums[left]+nums[right] < sum){
                   left++;
               }
               else{
                   right--;
               }
           }

           while(i < nums.length-2 && nums[i] == nums[i+1]) i++;
       }
       return rt;
    }
}