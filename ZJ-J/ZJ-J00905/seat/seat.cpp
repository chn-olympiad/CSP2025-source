#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
    int n, m, ans;
    cin>>n>>m;
    int a[n][m];
    vector<int> s(n*m);
    for(int i=0; i<n*m; i++){
        cin>>s[i];
    } int r=s[0];
    sort(s.begin(), s.end(), greater<int>());
    for(int i=0; i<n*m; i++){
        if(s[i]==r) ans=i+1;
    }
    int t1=(ans)/n, t2=(ans)%n;
    if(ans<n){
        cout<<1<<" "<<ans;
        return 0;
    }
    if(t2==0){
        if(t1%2==0) cout<<t1<<" "<<1;
        else cout<<t1<<" "<<n;
    }else{
        if(t1%2==0) cout<<1+t1<<" "<<t2;
        else cout<<1+t1<<" "<<n+1-t2;
    }
}
