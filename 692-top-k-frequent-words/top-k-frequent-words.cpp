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
        for(const auto& word : words)mp[word]++;
        // for(int i=0 ; i<words.size() ; i++)mp[words[i]]++;
        priority_queue<Node* , vector<Node*> , Compare>minHeap;
        for(const auto& entry : mp){
            Node* newNode = new Node(entry.first , entry.second);
            minHeap.push(newNode);
        }
        // for(itr = mp.begin() ; itr != mp.end() ; itr++){
        //     if(k > 0){
        //         Node* newNode = new Node(itr->first , itr->second);
        //         minHeap.push(newNode);
        //         k--;
        //     }
        //     else break;
        // }
        // for(itr1 = itr ; itr1 != mp.end() ; itr1++){
        //     Node* top = minHeap.top();
        //     cout << top->freq << " ";
        //     if(itr1->second > top->freq){
        //         minHeap.pop();
        //         Node* newNode = new Node(itr1->first , itr1->second);
        //         minHeap.push(newNode);
        //     }
        //     else if(itr1->second == top->freq){
        //         if( itr->first < top->s ){
        //             minHeap.pop();
        //             Node* newNode = new Node(itr1->first , itr1->second);
        //             minHeap.push(newNode);
        //         }
        //     }
        // }
        while(!minHeap.empty() && k-- > 0){
            Node* top = minHeap.top();
            ans.push_back(top->s);
            minHeap.pop();
        }
        return ans;
    }
};