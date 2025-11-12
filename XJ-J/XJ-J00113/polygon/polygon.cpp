#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N],sum=0,m=3,ans=0,mi=N,mx=-1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		sum+=a[i];
		mi=min(mi,a[i]);
	}
	for(int i=1;i<=n;i++){
		mx=max(mx,a[i]);
	}
	ans=sum-mi-mx;
	if(ans+mi>mx){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
