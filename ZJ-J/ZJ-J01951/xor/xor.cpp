//TLE or RE 65pts
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n,k,a[N],ans,t;
int g[2005][2005],f[2005];
bool f1=1,f2=1;
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) f1=f2=0;
		else if(a[i]==0) f1=0;
	}
	if(f1&&k==0) cout<<n/2<<'\n';
	else if(f2&&k<=1){
		if(k==1){
			for(int i=1;i<=n;i++) ans+=a[i];
			cout<<ans<<'\n';
		}else{
			for(int i=1;i<=n;i++){
				if(a[i]==1&&a[i+1]==1) ans++,i++;
				else if(a[i]==0) ans++;
			}
			cout<<ans<<'\n';
		}
	}else{
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
				g[i][j]=g[i][j-1]^a[j];
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				if(i>j) cout<<"  ";
//				else cout<<g[i][j]<<" \n"[j==n];
//			}
//		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				if(g[j][i]==k){
					f[i]=max(f[i],f[j-1]+1);
				}
			}
			f[i]=max(f[i],f[i-1]);
		}
		cout<<f[n]<<'\n';
	}
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int _=1;
//	cin>>_;
	while(_--) solve();
	return 0;
}

