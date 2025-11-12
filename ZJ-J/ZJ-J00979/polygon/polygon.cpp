#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
const int mod=998244353;
int ans=0;
inline void dfs(int x,int s,int p,int sum,int last){
	if(x>n+1) return;
	if(s>=3&&2*p<sum&&last!=0){
		ans++;
		ans%=mod;
	}
	dfs(x+1,s+1,max(a[x],p),sum+a[x],1);
	dfs(x+1,s,p,sum,0);
}
inline long long jie(long long p){
	int sum=1;
	for(int i=2;i<=p;i++){
		sum*=i;
		sum%=mod;
	}
	return sum;
}
inline long long C(long long n,long long m){
	return jie(m)/jie(m-n)/jie(n);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	int p=0;
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		if(a[i]>p) p=a[i];
	}
	if(n<3) {
		cout<<0;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	else if(p==1){
		long long ans=0;
		for(int i=3;i<=n-1;i++){
			if(i>=n/2)
				ans+=C(n-i,n);
			else ans+=C(i,n);
			//cout<<C(i,n)<<endl;
			ans%=mod;
		}
		ans+=1;
		ans%=mod;
		printf("%lld",ans);
	}
	else{
		dfs(1,0,0,0,0);
		printf("%d",ans);
	}	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

