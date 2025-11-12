#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long a[5010],vis[5010];
void check(){
	long long sum=0,cnt=0,maxx=-1;
	for(long long i=1;i<=n;i++){
		if(vis[i]==1){
			sum+=a[i];
			maxx=max(maxx,a[i]);
			cnt++;
		}
	}
	if(cnt>=3 && sum>(2*maxx))	ans=(ans+1)%998244353;
	return ;
}
void dbx(long long now){
	if(now>=n+1)	return ;
	dbx(now+1);
	vis[now]=1;
	dbx(now+1);
	check();
	vis[now]=0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)	cin>>a[i];
	dbx(1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

