#include<bits/stdc++.h>
using namespace std;
int c,b;
long long n,k,a[500005],vis[500005],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	cin>>a[1];
	for(int i=2;i<=n;i++){
		long long h;
		cin>>h;
		a[i]=h|a[i-1];
	}
	if(n==1&&k==0&&a[1]==1){
		cout<<0;
		return 0;
	}
	if(n==2&&k==1){
		if(a[1]==0){
			ans++;
			if(a[2]==0) ans++;
			cout<<ans;
		}
		else if(a[1]|a[2]==0) cout<<1; 
		else if((a[1]!=0&&a[2]==0)||(a[1]==0&&a[2]!=1)) cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(((a[i]|a[i-1])|a[j])==k){
				int f=1;
				for(int e=i;e<=j;e++){
					if(vis[e]){
						f=0;
						break;
					}
				}
				if(f){
					for(int e=i;e<=j;e++) vis[e]=1;
					ans++;
				}
				
			}
		}
	}
	cout<<ans;
	/*cin>>c>>b;
	int x=c|b;
	cout<<x;*/
	return 0;
}
