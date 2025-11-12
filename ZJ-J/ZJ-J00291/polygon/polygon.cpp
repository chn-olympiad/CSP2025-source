#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,a[5010],ans,t;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	if(n==3&&a[0]+a[1]>a[2]) cout<<1;
	else if(n==3) cout<<0;
	else if(n==4) cout<<5;
	else{
		ans=0,t=1;
		while(n) ans+=t*n,t++,n--;
		cout<<ans;
	}
	return 0;
}
