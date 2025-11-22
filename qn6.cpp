#include <iostream>
#include <vector>
using namespace std;

vector<int> heapv;

void pushPQ(int x) {
    heapv.push_back(x);
    int i = heapv.size()-1;
    while(i>0 && heapv[(i-1)/2] < heapv[i]) {
        int t = heapv[i];
        heapv[i] = heapv[(i-1)/2];
        heapv[(i-1)/2] = t;
        i = (i-1)/2;
    }
}

int popPQ() {
    int x = heapv[0];
    heapv[0] = heapv.back();
    heapv.pop_back();
    int i=0,n=heapv.size();
    while(1) {
        int l=2*i+1,r=2*i+2,largest=i;
        if(l<n && heapv[l]>heapv[largest]) largest=l;
        if(r<n && heapv[r]>heapv[largest]) largest=r;
        if(largest==i) break;
        int t = heapv[i];
        heapv[i] = heapv[largest];
        heapv[largest] = t;
        i = largest;
    }
    return x;
}

int topPQ() {
    return heapv[0];
}

int main() {
    pushPQ(50);
    pushPQ(20);
    pushPQ(80);
    cout << topPQ() << endl;
    cout << popPQ() << endl;
    cout << topPQ() << endl;
}
