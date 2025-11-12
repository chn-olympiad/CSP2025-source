#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],b[5010];
long long sum;
const long long N=998244353;
void dfs(int t,int f){
	if(t>n+1) return ;
	if(t>3){
		long long s=0,maxn=-1;
		for(int i=1;i<t;i++){
			s+=b[i];
			if(b[i]>maxn) maxn=b[i];
		}
		if(s>maxn*2) sum=(sum+1)%N;
	}
	for(int i=f;i<=n;i++){
		b[t]=a[i];
		dfs(t+1,i+1);
		b[t]=a[i];
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,1);
	cout<<sum;
	return 0;
}

