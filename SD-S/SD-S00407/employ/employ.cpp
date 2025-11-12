#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
const int maxn=510;
const int mod=998244353;
int n,m;
int c[maxn];
bool vis[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	char ch;
    	cin>>ch;
    	if(ch=='1'){
    		vis[i]=1;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(m==n){
		if(!vis[1]){
			
		}
		for(int i=1;i<=n;i++){
			if(c[i]==0){
				cout<<0;
				return 0;
			}
		}
	}
	if(m==1){
		int cnt=0,ans=1;
		for(int i=1;i<=n;i++){
			if(c[i]==0){
				cnt++;
			}
		}
		for(int i=n;i>=1;i--){
			ans=(ans*(i%mod))%mod;
		}
		int res=1;
		for(int i=cnt;i>=1;i--){
			res=(res*(i%mod))%mod;
		}
		ans=abs(ans-res)%mod;
		cout<<ans;
		return 0;
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
