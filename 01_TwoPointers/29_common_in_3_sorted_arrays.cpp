// URL: https://www.geeksforgeeks.org/problems/common-elements1132/1

class Solution {
  public:

    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3) {
        
        int firstIndex = 0;
        int secondIndex = 0;
        int thirdIndex = 0;
        int n1 = arr1.size();
        int n2 = arr2.size();
        int n3 = arr3.size();
        vector <int> ans;
        
        while(firstIndex < n1 && secondIndex < n2 && thirdIndex < n3) {
            
            if(arr1[firstIndex] == arr2[secondIndex] && arr2[secondIndex] == arr3[thirdIndex]) {
                if(ans.empty() || ans.back() != arr1[firstIndex]) {
                    ans.push_back(arr1[firstIndex]);
                }
                firstIndex += 1;
                secondIndex += 1;
                thirdIndex += 1;
            }
            else if(arr1[firstIndex] < arr2[secondIndex] || arr1[firstIndex] < arr3[thirdIndex]) {
                firstIndex += 1;   
            }
            else if (arr2[secondIndex] < arr1[firstIndex] || arr2[secondIndex] < arr3[thirdIndex]) {
                secondIndex += 1;
            }
            else if (arr3[thirdIndex] < arr1[firstIndex] || arr3[thirdIndex] < arr2[secondIndex]) {
                thirdIndex += 1;
            }
        }
        
        return ans;
    }
};
