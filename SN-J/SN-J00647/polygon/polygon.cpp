#include<bits/stdc++.h>
using namespace std;
int a[1005];
int n,ans=0,maxn=-1,sum=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool g=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0) g=0;
	}
	if(g){
		int uy=1;
		for(int i=n;i>=1;i--){
			uy*=i;
		}
		cout<<uy;
		return 0;
	}
	for(int i=1;i<=(1<<n);i++){
		int m=i;
		for(int j=1;j<=n;j++){
			if((m&1)==1){
				sum+=a[j];
				maxn=max(maxn,a[j]);
			}
			m=(m>>1);
		}
		if(sum>maxn*2){
			ans++;
		}
		sum=0;
		maxn=-1;
	}
	cout<<ans-1;
	return 0;
}

