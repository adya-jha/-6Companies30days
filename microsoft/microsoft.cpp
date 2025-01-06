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

//question4 - image smoother 
vector<vector<int>> directions {
{-1,-1},{-1,0},{-1,1},
{0,-1},{0,0},{0,1},
{1,-1},{1,0},{1,1}
};
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m=img.size(); //i
        int n=img[0].size(); //j
        vector<vector<int>> results(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int sum=0;
                int count=0;
                for(auto &it:directions){ 
                int i_=i+it[0];
                int j_=j+it[1];
                if(i_>=0 && i_<m && j_>=0 && j_<n){
                    sum+=img[i_][j_];
                    count++;
                }
                }
                results[i][j]=sum/count;
                }
            }
            return results;
        }

//question 5- minimum moves to equal element array
  int minMoves2(vector<int>& nums) {
       int n=nums.size();
       sort(nums.begin(),nums.end());
       int mid=n/2;
       int median=nums[n/2];
       int sum=0;
for(auto &it:nums){
 sum+=abs(it-median);
}
    return sum;
}
//question 6 - wiggle sort 
void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        sort(nums.begin(),nums.end());
        int i=1;
        int j=n-1;
        while(i<n && j>=0){
            ans[i]=nums[j];
            i=i+2;
            j=j-1;
        }
        i=0;
        while(i<n && j>=0){
            ans[i]=nums[j];
            i=i+2;
            j--;   
    }
    for(int k=0;k<n;k++){
        nums[k]=ans[k];
    }
    }
    //question 7 - bulls and cows
    string getHint(string secret, string guess) {
        int bulls=0,cows=0;
        unordered_map<char,int> map1,map2;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]) bulls++;
            else{
                map1[secret[i]]++;
                map2[guess[i]]++;
            }
        }
        for(auto it: map1){
            if(map2.find(it.first)!=map2.end()){
                cows+=min(it.second,map2[it.first]);
            }
        }
        string ans=to_string(bulls)+"A"+to_string(cows)+"B";
return ans;
    }

//question 7 - random point in non overlapin g rectangles
    vector<int> prefixSums;         
vector<vector<int>> rectangles;
   class Solution {
public:
Solution(vector<vector<int>>& rects) {
rectangles = rects; 
int numRectangles = rectangles.size();
prefixSums.resize(numRectangles + 1, 0);

for (int i = 0; i < numRectangles; ++i) {
prefixSums[i + 1] = prefixSums[i] + 
 (rectangles[i][2] - rectangles[i][0] + 1) * 
 (rectangles[i][3] - rectangles[i][1] + 1);
      }
srand(static_cast<unsigned int>(time(nullptr)));
}
  
    vector<int> pick() {
        int target = 1 + rand() % prefixSums.back();
    

int idx = static_cast<int>(lower_bound(prefixSums.begin(), prefixSums.end(), target) - prefixSums.begin()) - 1;
     auto& rect = rectangles[idx];

    int x = rect[0] + rand() % (rect[2] - rect[0] + 1);
      int y = rect[1] + rand() % (rect[3] - rect[1] + 1);
    
      return {x, y};
        
    }
   };

//question 8 - city with smallest number of neighbours at threshold distance 
int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
       vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }
        
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], weight = edge[2];
            dist[u][v] = weight;
            dist[v][u] = weight;
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        int countcity = n; // Initialize to max possible
        int cityNo = -1;   // Result city index

        for (int city = 0; city < n; city++) {
            int count = 0;
            for (int adjcity = 0; adjcity < n; adjcity++) {
                if (dist[city][adjcity] <= distanceThreshold) {
                    count++;
                }
            }
            
          
            if (count < countcity || (count == countcity && city > cityNo)) {
                countcity = count;
                cityNo = city;
            }
        }

        return cityNo;
    }

    

int main(){
    cout<<"solving question for company one";
    return 0;
}