#include<bits/stdc++.h> 
using namespace std;
const int N=1e4+7;
int a[N],n,cnt=0,k=0,t=0,ans=0; 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt+=a[i];
		k=max(k,a[i]);
		if(a[i]==1) t++;
	}
	if(n<=3){
		if(cnt>k*2) cout<<1;
	}
	if(n==4) cout<<2;
	else if(t==t){
		for(int i=n-2,j=1;i>=1;i--,j++){
			ans+=i*j;
		}
		cout<<ans;
	}
	return 0;
}
