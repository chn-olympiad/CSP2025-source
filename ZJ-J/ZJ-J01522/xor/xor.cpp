#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5*1e5+5;
int n,k,a[N],ans,b[N],f;

signed main(){
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0&&a[i]!=1) f=1;
	}
	if(!k) cout<<n;
	else if(k==1&&!f){
		a[0]=3,a[n+1]=3;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				if(!a[i-1]&&!b[i-1]){
					ans++;
					b[i-1]++;
				}
				else if(!a[i+1]&&!b[i+1]){
					ans++;
					b[i+1]++;
				}
			}
		}
		cout<<ans;
	}
	else{
		for(int l=1;l<=n;l++){
			for(int r=l;r<=n;r++){
				int f=0;
				for(int i=l;i<=r;i++){
					if(b[i]==1){
						f=1;
						break;
					}
				}
				if(!f){
					int sum=a[l];
					if(l!=r){
						for(int i=l+1;i<=r;i++)
							sum^=a[i];
					}
					if(sum==k){
						for(int i=l;i<=r;i++) b[i]=1;
						ans++;
					}
				}
			}
		}
		cout<<ans;
	}
	return 0;
}