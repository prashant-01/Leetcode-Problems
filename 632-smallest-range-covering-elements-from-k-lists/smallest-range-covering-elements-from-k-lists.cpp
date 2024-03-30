class Node {
    public:
    int val , i , j;
    Node(int val , int i , int j){
        this->val = val;
        this->i = i;
        this->j = j;
    }
};
class Comparator {
    public:
    bool operator()(Node* a , Node* b){
        return a->val > b->val;
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int>ans;
        int mini = INT_MAX , maxi = INT_MIN , start , end;
        priority_queue<Node* , vector<Node*> , Comparator>minHeap;

        // pushing first element of each list in the minHeap 
        // also calc maxi and mini
        for(int i=0 ; i<nums.size() ; i++){
            int val = nums[i][0];
            mini = min(mini , val);
            maxi = max(maxi , val);
            Node* newNode = new Node(val , i , 0);
            minHeap.push(newNode);
        }

        start = mini , end = maxi;

        // increasing mini to decrease the range 
        // can't decrease maxi further because lists are sorted
        while(1){
            Node* top = minHeap.top();
            minHeap.pop();

            // update mini
            mini = top->val;
            if(maxi-mini < end-start){
                start = mini;
                end = maxi;
            }
            // update maxi
            int row = top->i , col = top->j ;
            if(col + 1 < nums[row].size()){
                maxi = max(maxi , nums[row][col + 1]);
                Node* newNode = new Node(nums[row][col + 1] , row , col + 1);
                minHeap.push(newNode);
            }
            else break;
        }
        ans.push_back(start) , ans.push_back(end);
        return ans;
    }
};