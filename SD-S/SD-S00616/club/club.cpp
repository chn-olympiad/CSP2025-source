#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,M=2e4+5;
int n,a[N],b[N],c[N],d[N][5],st[N],ans;
void solve(){
	int f=1;
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
		d[i][1]=a[i];
		d[i][2]=b[i];
		d[i][3]=c[i];
		if(b[i]!=0||c[i]!=0) f=0;
	}
	if(n==2){
		for(int i=1;i<=3;i++){
			for(int j=1;j<=3;j++){
				if(i!=j) ans=max(ans,d[1][i]+d[2][j]);
			}
		}
		cout<<ans;
	}else if(f==1){
		sort(a+1,a+1+n,greater<int>());
		for(int i=1;i<=n/2;i++){
			ans+=a[i];
		}
		cout<<ans;
	}else{
		for(int i=1;i<=n;i++){
			ans+=max(a[i],max(b[i],c[i]));
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
} 
