#include<bits/stdc++.h>
#define int long long
#define inf (int)0x3f3f3f3f3f3f3f3f
#define sup (int)0xc0c0c0c0c0c0c0c0
#define pro (string)"seat"

using namespace std;
const int e=1e2+10;

int n,m,cnt,ans;
int a[e],b[e][e];

void file_read();

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	file_read();
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	ans=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	
	for(int j=1;j<=m;j++){
		if(j%2==1)
			for(int i=1;i<=n;i++){
				cnt++;
				
				if(a[cnt]==ans){
					cout<<j<<' '<<i<<'\n';
					return 0;
				}
			}
		else
			for(int i=n;i>0;i--){
				cnt++;
				
				if(a[cnt]==ans){
					cout<<j<<' '<<i<<'\n';
					return 0;
				}
			}
	}

	return 0;
}

void file_read(){
	#ifdef pro
	freopen((pro+".in").c_str(),"r",stdin);
	freopen((pro+".out").c_str(),"w",stdout);
	#endif

	return;
}

