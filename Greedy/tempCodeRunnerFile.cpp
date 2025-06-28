class Solution {
public:
    int candy(vector<int>& ratings) {

        vector<int> c(ratings.size(),1);
        
        for(int i=0;i<ratings.size()-1;i++){
            if(ratings[i]<ratings[i+1]){
                c[i+1]=c[i]+1;
            }
            
        }

        for(int i=ratings.size()-2;i>=0;i++){
            if(ratings[i]>ratings[i+1]){
                c[i]=max(c[i],c[i+1]+1);
            }
        }
        
        return accumulate(c.begin(),c.end(),0);

    }
};

// For testing
int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> ratings1 = {1, 0, 2};
    cout << "Test Case 1: " << sol.candy(ratings1) << endl; // Expected: 5
    
    // Test Case 2
    vector<int> ratings2 = {1, 2, 2};
    cout << "Test Case 2: " << sol.candy(ratings2) << endl; // Expected: 4
    
    // Test Case 3
    vector<int> ratings3 = {1, 3, 2, 2, 1};
    cout << "Test Case 3: " << sol.candy(ratings3) << endl; // Expected: 7
    
    return 0;
} 