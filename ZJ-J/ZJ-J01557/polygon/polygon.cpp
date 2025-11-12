#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n;
long long a[50005];
long long c[50005];
long long op;
bool vis[50005];
void dg(int step,int fin,int last_id){
	if(step==fin){
		long long maxx=0;
		for(int i=1;i<=step;i++){
			maxx=max(maxx,c[i]);
		}
		int cnt=0;
		for(int i=1;i<=step;i++){
			cnt+=c[i];
		}
		if(cnt>maxx*2){
			op++;
			op%=mod;
		}
		return ;
	}
	for(int i=last_id+1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		c[step+1]=a[i];
		dg(step+1,fin,i);
		vis[i]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		dg(0,i,0);
	}
	cout<<op;
}

