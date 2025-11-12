#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5005,M=998244353;
int n,a[N],maxn,ans;
int f[N];
void add(int x){
	int r=min(maxn+x,N-1);
	if(maxn==0){
		for(int i=1;i<x;i++) f[i]=1;
	}
	else{
		if(x>=maxn){
			for(int j=r-1;j>maxn;j--) f[j]=f[j-x];
			for(int j=maxn;j<x;j++) f[j]=f[0]+1;
		}
		if(maxn>x){
			for(int j=r-1;j>x;j--) f[j]=f[j-x];
		}
		for(int j=0;j<x;j++){
			f[j]=f[j]*2+1;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		ans+=f[a[i]];
		ans%=M;
		add(a[i]);
		maxn+=a[i];
	}
	cout<<ans<<endl;
	return 0;
}
