#include<bits/stdc++.h>
using namespace std;
#define i64 long long
const int N=1e5+5;
int T=1;
int n,ans;
int a[N][5];
int cnt[5],id[N];
int b[N],s;
void solve(){
	ans=0;
	s=0;
	for(int i=1;i<=3;i++) cnt[i]=0;
	cin>>n;
	for(int i=1,ma;i<=n;i++){
		ma=-1;
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
			if(a[i][j]>ma) ma=a[i][j],id[i]=j;
		}
		cnt[id[i]]++;
		ans+=ma;
	}
	for(int j=1;j<=3;j++){
		if(cnt[j]>n/2){
			for(int i=1;i<=n;i++){
				if(id[i]!=j) continue;
				b[++s]=1e9;
				for(int k=1;k<=3;k++) if(k!=j) b[s]=min(b[s],a[i][j]-a[i][k]);
			}
			sort(b+1,b+1+s);
			for(int i=1;i<=cnt[j]-n/2;i++) ans-=b[i];
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	while(T--) solve();
	return 0;
} 