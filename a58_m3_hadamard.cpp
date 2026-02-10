#include <iostream>
#include <vector>

using namespace std;



vector<int> solve(int n, const vector<int>& v) {
    int half = n/2;
    if (n == 1) {
        return v;
    }
    vector<int> top_half(half),bottom_half(half);
    for(int i =0;i<half;i++){
        top_half[i] = v[i];
        bottom_half[i] = v[half+i];
    }
    vector<int> A = solve(half,top_half);
    vector<int> B = solve(half,bottom_half);
    vector<int> ans(n);
    for(int i = 0;i<half;i++){
        ans[i] = A[i] + B[i];
        ans[i+half] = A[i] -B[i];
    }
    return ans;


}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i =0;i<n;i++){
        cin >> v[i];
    }

    vector<int> ans = solve(n,v);
    for(int i:ans){
        cout << i << " ";
    }
    
}