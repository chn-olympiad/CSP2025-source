#include<bits/stdc++.h>
using namespace std;
int n;
long long a[5005],q[5005],maxn=0,ans=0;

void work(int l,int r){
	maxn=0;
	for(int i=l;i<=r;i++)
		maxn=max(maxn,a[i]);
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		q[i]=q[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			work(i,j);
			if(q[j]-q[i-1]-maxn>maxn)
				ans=(ans+i)%998244353ll;
		}
	}
	printf("%lld",ans);
	return 0;
}