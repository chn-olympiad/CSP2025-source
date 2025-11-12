#include<bits/stdc++.h>
using namespace std;
int n,k,a,b,c,x;
int s[500010];
int vis[500010];
long long ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]==1)a++;
		else if(s[i]==0)b++;
	}
	if(a==n)cout<<a/2;
	else if(a+b==n){
		if(k==1)cout<<a;
		else{
			ans=b;
			for(int i=1;i<=n;i++)if(s[i]==1&&s[i+1]==1)ans++,i++;
			cout<<ans;
		}
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n-i+1;j++){
				if(!vis[j]){
					int xo=s[j];
					for(int l=j+1;l<=j+i-1;l++){
						if(vis[l]){
							xo=-1;
							break;
						}
						xo^=s[l];
					}
					if(xo==k){
						ans++;
						for(int l=j;l<=j+i-1;l++)vis[l]++;
					}
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
