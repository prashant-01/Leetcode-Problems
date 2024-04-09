class Node {
    public : 
        int d;
        int i;
    Node(int d , int i){
            this->d = d;
            this->i = i;
        }
    };
class Compare {
    public:
    bool operator()(Node* a , Node* b){
        return a->d < b->d;
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        priority_queue< Node* , vector<Node*> , Compare >maxHeap;
        for(int i=0 ; i<k ; i++){
            Node* newNode = new Node((points[i][0] * points[i][0]) + (points[i][1] * points[i][1]) , i);
            maxHeap.push(newNode);
        }
            
        for(int i=k ; i<points.size() ; i++){
            int d = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);
            Node* top = maxHeap.top();
            if(d < top->d){
                maxHeap.pop();
                Node* newNode = new Node(d , i);
                cout << newNode->d << " ";
                maxHeap.push(newNode);
            }
        }

        while(!maxHeap.empty()){
            Node* top = maxHeap.top();
            vector<int>a = { points[top->i][0] , points[top->i][1] };
            ans.push_back(a);
            maxHeap.pop();
        }
        return ans;
    }
};