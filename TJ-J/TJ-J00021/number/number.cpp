#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    //8:52
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string s;
    cin >> s;
    ll nums[10];
    memset(nums , 0 , sizeof(nums));
    ll len = s.size();
    for(int i = 0;i < len;i++){
        char c = s[i];
        if(c >= '0' && c <= '9'){
            nums[c - '0']++;
        }
    }

    for(int i = 9;i >= 0;i--){
        for(int j = 1;j <= nums[i];j++){
            cout << i;
        }
    }
    return 0;
}
