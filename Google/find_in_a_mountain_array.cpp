class Solution {
public:
    int findPeak(MountainArray &arr, int length) {
        int start = 0;
        int end = length - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;
            if (arr.get(mid) < arr.get(mid + 1)) {
                start = mid + 1;
            } else {
                
                end = mid;
            }
        }
        return start; 
    }

    int binarySearch(MountainArray &arr, int start, int end, int target, bool ascending) {
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int value = arr.get(mid);

            if (value == target) {
                return mid;
            }

            if (ascending) {
                if (value < target) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            } else {
                if (value > target) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1; 
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int length = mountainArr.length();
        int peak = findPeak(mountainArr, length);

        
        int index = binarySearch(mountainArr, 0, peak, target, true);
        if (index != -1) {
            return index;
        }

        return binarySearch(mountainArr, peak + 1, length - 1, target, false);
    }
};
