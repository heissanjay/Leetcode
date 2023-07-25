class Solution {
    public int peakIndexInMountainArray(int[] arr) {
        int s = 0;
        int e = arr.length;
        
        while ( s <= e ) {
            int m = s + (e - s) / 2;
            
            if (arr[m] < arr[m+1]){
                s = m + 1;
            } else if ( arr[m] > arr[m+1] && arr[m-1] < arr[m]) {
                return m;
            } else {
                e = m - 1;
            }
        }
        return s;
    }
}