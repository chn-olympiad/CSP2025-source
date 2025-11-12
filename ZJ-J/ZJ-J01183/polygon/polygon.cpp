#include<bits/stdc++.h>
using namespace std;
int n;
int v[5005];
bool r[5005];
int ans;
int ccc(int n){
	long long aans=1;
	for(int j=1;j<=n;j++){
		aans*=2;
		aans%=998244353;
	}
	long long cnttt=n*n+n+2;
	cnttt/=2;
	aans-=cnttt;
	aans%=998244353;
	return aans;
}
void dfs(int maxx,int cnt,int x){
	for(int i=x+1;i<=n;i++){
		if(r[i])continue;
		int maxxx=max(maxx,v[i]);
		int cntt=cnt+v[i];
		if(cntt>2*maxxx){
			r[i]=true;
			ans++;
			ans%=998244353;
			dfs(maxxx,cntt,i);
			r[i]=false;
		}
		else{
			r[i]=true;
			dfs(maxxx,cntt,i);
			r[i]=false;
		}
	}
	return ;
}
int main(){
	int maxxxx=-1;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	memset(r,false,sizeof(r));
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>v[i];
		if(v[i]>maxxxx){
			maxxxx=v[i];
		}
	}
	if(maxxxx==1){
		cout<<ccc(n)<<endl;
		return 0;
	}
	for(int i=1;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			r[i]=true,r[j]=true;
			dfs(max(v[i],v[j]),v[i]+v[j],j);
			r[i]=false,r[j]=false;
		}
	}
	cout<<ans<<endl;
	return 0;
}
