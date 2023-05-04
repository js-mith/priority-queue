#include<vector>

class priorityqueue {
    vector<int> pq;

    public:
    priorityqueue(){

    }

    bool isempty(){
        return pq.size() == 0;
    }

    // retrun the size of priorityqueue - no of element present

    int getsize(){
        return pq.size();
    }

    int getmin(){
        if(isempty()){
            return 0;
        }

        return pq[0];
    }

    void insert(int element){
        pq.push_back(element);
        int childindex = pq.size() -1;
        while(childindex > 0){
            int parentindex = (childindex - 1)/2;
            if(pq[childindex] < pq[parentindex]){
                int temp = pq[childindex];
                pq[childindex] = pq[parentindex];
                pq[parentindex] = temp;
            }
            else{
                break;
            }
            childindex = parentindex;
        }
    }

    int removemin(){
        int ans = pq[0];
        pq[0] = pq[pq.size() -1];
        pq.pop_back();
        // down heapify

        int parentindex = 0;
        int leftchildindex = 2 * parentindex + 1;
        int rightchildindex = 2 * parentindex + 2;

        while(leftchildindex < pq.size()){
            int minindex = parentindex;
            if(pq[minindex] > pq[leftchildindex]){
                minindex = leftchildindex;
            }

            if(rightchildindex < pq.size() && pq[rightchildindex] < pq[minindex]){
                minindex = rightchildindex;
            }
            if(minindex == parentindex){
                break;
            }
            int temp = pq[minindex];
            pq[minindex] = pq[parentindex];
            pq[parentindex] = temp;

            parentindex = minindex;
            leftchildindex = 2 * parentindex + 1;
            rightchildindex = 2 * parentindex + 2;
        }
        return ans;
    }
};