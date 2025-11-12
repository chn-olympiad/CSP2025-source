#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
    int n;
    cin>>n;
    vector<int> stick(n);
    for(int i=0; i<n; i++) cin>>stick[i];
    sort(stick.begin(), stick.end());
    if(n<=3){
        if(stick[0]+stick[1]+stick[2]>(2*stick[2])) cout<<1;
        else cout<<0;
        return 0;
    }
}