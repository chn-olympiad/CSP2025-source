#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,ans;
int a[500005];
int sum[500005];
int vis[500005];
int f[500005];
int p[10005][10005];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]^a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j+i<=n;j++){
			if(sum[j-1]^sum[j+i]==k){
				f[j]=1;
				p[j][i+j]=1;
			}
		}
	}
	for(int i=1;i<=n;i++)if(a[i]==k){vis[i]=1;ans++;}
	for(int i=1;i<=n;){
		if(vis[i]==0&&f[i]){
			int j;
			for(j=i+1;j<=n+1;j++)if(vis[j]==1)break;
			for(int o=i;o<j;o++){
				int t=0;
				for(int u=o+1;u<j;u++){
					if(p[o][u]){
						ans++;
						i=u+1;
						t=1;
						break;
					}
				}
				if(t)break;
				else i++;
			}
		}else i++;
	}
	cout<<ans;
	return 0;
}

