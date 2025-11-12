#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],s[500005],ans=0;
void dfs(long long x,long long cnt){
	long long minV=5000000;
	for(long long i=x;i<=n;i++){
		for(long long j=i;j<=n;j++){
			long long p=s[j]^s[i-1];
			if(p==k){
				minV=min(minV,j);	
				break;
			}
		}
	}
	if(minV==5000000){
		ans=max(ans,cnt);
		return ;
	}
	dfs(minV+1,cnt+1);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]^a[i];	
	}
	if(k<=1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1) cnt++;
		}
		if(k==1)cout<<cnt;
		else cout<<cnt/2;
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
