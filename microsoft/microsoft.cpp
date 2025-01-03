#include<iostream>
using namespace std;
//question 1 - circle rectangle overlap
bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int closestx=max(x1,min(xCenter,x2));
        int closesty=max(y1,min(yCenter,y2));
        int sq_distance=(xCenter-closestx)*(xCenter-closestx) + (yCenter-closesty)*(yCenter-closesty);
        return sq_distance<=(radius*radius);
    }

//question 2 - in a circle of friends , find winner
int solve(int n,int k){
    if(n==1) return 0;
 return (solve(n-1,k)+k)%n;
}
    int findTheWinner(int n, int k) {
 int winner =solve(n,k)+1;
 return winner;
    }

//question 3 - count incremovable subarrays 
int incremovableSubarrayCount(vector<int>& nums) {
      int currentIndex = 0; 
        int size = nums.size(); 

        while (currentIndex + 1 < size && nums[currentIndex] < nums[currentIndex + 1]) {
            ++currentIndex;
        }

        if (currentIndex == size - 1) {

            return size * (size + 1) / 2;
        }

        int result = currentIndex + 2; 

        for (int backwardIndex = size - 1; backwardIndex > 0; --backwardIndex) {

            while (currentIndex >= 0 && nums[currentIndex] >= nums[backwardIndex]) {
                --currentIndex;
            }
       
            result += currentIndex + 2;
         
            if (nums[backwardIndex - 1] >= nums[backwardIndex]) {
                break;
            }
        }

        return result;
    }


int main(){
    cout<<"solving question for company one";
    return 0;
}