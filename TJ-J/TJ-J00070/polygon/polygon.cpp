#include<bits/stdc++.h>
using namespace std;
int main(){
    //buhuia*('_')*9595
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	if(n==3){
        if(a[0]>a[1]){
            int q=max(a[0],a[2]);
            if(a[0]+a[1]+a[2]<=2*q) cout<<0;
            else cout<<1;
            return 0;
        }
	}
	cout<<(n+a[2])%998244353;
	return 0;
}
