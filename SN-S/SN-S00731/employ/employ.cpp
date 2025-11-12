#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[510];
bool vis[510];
long long ans=0;
void pailie(int time,int ok,int ci,bool vis[]){
	bool jl=1;
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			jl=0;
			if(c[i]>time&&s[ci]=='1'){
				vis[i]=1;
				pailie(time,ok+1,ci+1,vis);
				vis[i]=0;
			}else{
				vis[i]=1;
				pailie(time+1,ok,ci+1,vis);
				vis[i]=0;
			}
		}
	}
	if(ok>=m){
		ans++;
		ans%=998244353;
		return;
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	pailie(0,0,0,vis);
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
