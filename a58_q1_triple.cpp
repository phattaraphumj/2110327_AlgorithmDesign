#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    int q;
    cin >> N >> M;
    vector<int> v(N);
    for(int i =0;i<N;i++){
        cin >> v[i];
    }
    for(int i =0;i<M;i++){
        cin >> q;
        bool found = false;
        for(int j = 0;j<N-2;j++){
            int left = j+1;
            int right = N-1;
            while(left<right){
                int sum = v[j] + v[left] + v[right];
                if(sum == q){
                    found = true;
                    break;
                }
                if(sum>q)right--;
                if(sum<q)left++;
            }
            if(found)break;
        }
        if(found)cout << "YES";
        else cout << "NO";
        cout << "\n";
    }

}