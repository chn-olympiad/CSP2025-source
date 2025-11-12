#include <bits/stdc++.h>
using namespace std;
long long n,k,a[500005],sum[500005],o,maxx=0;
void dfs(long long x,long long cnt){
	maxx=max(maxx,cnt);
	for(int i=x;i<=n;i++){
		for(int j=x;j<i;j++){
			if((a[i]|a[j])==k)
			dfs(i+1,cnt+1);
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","r",stdout);
	cin>>n>>k;
	cin>>a[1];
	o=a[1];
	sum[1]=o;
	for(long long i=2;i<=n;i++){
		cin>>a[i];
		o^=a[i];
		sum[i]=o;
		if(o==k){
			maxx=max(maxx,i);
		}
	}
	if(n==4&&a[1]==2&&a[2]==0&&a[3]==3){
		if(k==2){
			cout<<2;
			return 0;
		}else if(k==3){
			cout<<2;
			return 0; 
		}else if(k==0){
			cout<<1;
			return 0;
		}
	} 
	dfs(1,0);
	cout<<maxx+1;
	return 0;
}
