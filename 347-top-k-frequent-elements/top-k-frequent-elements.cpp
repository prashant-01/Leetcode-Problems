class Node {
    public :
    int num;
    int freq;
    Node(int num , int freq){
        this->num = num;
        this->freq = freq;
    }
};
class Compare {
    public:
    bool operator()(Node* a , Node* b){
        return a->freq > b->freq;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int , int>mp;
        unordered_map<int , int>::iterator itr , itr1;
        for(int i=0 ; i<nums.size() ; i++)mp[nums[i]]++;
        priority_queue<Node* , vector<Node*> , Compare>minHeap;
        for(itr = mp.begin() ; itr != mp.end() ; itr++){
            if(k > 0){
                Node* newNode = new Node(itr->first , itr->second);
                minHeap.push(newNode);
                k--;
            }
            else break;
        }
        for(itr1 = itr ; itr1 != mp.end() ; itr1++){
            Node* top = minHeap.top();
            cout << top->freq << " ";
            if(itr1->second > top->freq){
                minHeap.pop();
                Node* newNode = new Node(itr1->first , itr1->second);
                minHeap.push(newNode);
            }
        }
        while(!minHeap.empty()){
            Node* top = minHeap.top();
            ans.push_back(top->num);
            minHeap.pop();
        }
        return ans;
    }
};