class Node {
    public :
    string s;
    int freq;
    Node(string s , int freq){
        this->s = s;
        this->freq = freq;
    }
};
class Compare {
    public:
    bool operator()(Node* a , Node* b){
        return a->freq == b->freq ? a->s > b->s : a->freq < b->freq;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string>ans;
        unordered_map<string , int>mp;
        unordered_map<string , int>::iterator itr , itr1;
        priority_queue<Node* , vector<Node*> , Compare>minHeap;

        for(const auto& word : words)mp[word]++;
        for(const auto& entry : mp){
            Node* newNode = new Node(entry.first , entry.second);
            minHeap.push(newNode);
        }
        while(!minHeap.empty() && k-- > 0){
            Node* top = minHeap.top();
            ans.push_back(top->s);
            minHeap.pop();
        }
        return ans;
    }
};