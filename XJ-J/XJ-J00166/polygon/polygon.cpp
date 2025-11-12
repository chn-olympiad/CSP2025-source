#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int c[5010];
int n,a[5010];
int C(int a,int b){
	int c=1,d=1;
	for(int i=0;i<b;i++){
		c*=a-i;c%=N;
	}
	for(int i=b;i>1;i++){
		d*=i;d%=N;
	}
	return c/d;
}
int dfs(int maxn,int sum,int k,int t){
	if(k==0){
		if(sum>maxn*2){
			return 1;
		}
		return 0;
	}
	if(t>k){
		return 0;
	}
	int summ=0;
	for(int i=t+1;i<=n;i++){
		summ+=dfs(max(maxn,a[i]),sum+a[i],k-1,i);
		summ%=N;
	}
	return summ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	int t=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=a[i-1]&&i!=1) t=1;
	}
	if(!t){
		int sum=0;
		for(int i=3;i<=n;i++){
			int ii=i;
			if(ii*2>n){
				ii=n-ii;
			}
			if(c[ii]==0){
				c[ii]=C(n,ii);
			}
			sum+=c[ii];
			sum%=N;
		}
		printf("%d",sum);
	}else {
		int sum=0;
		for(int i=3;i<=n;i++){
			sum+=dfs(0,0,i,0);
			sum%=N;
		}
		printf("%d",sum);
	}
	return 0;
}
