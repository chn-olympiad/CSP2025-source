#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N][4],cnt[4],c[N],ch[N];
long long ans=0;
int main(){
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while (T--){
		int n;
		cin>>n;
		ans=0;
		for (int i=1;i<=n;i++){
			c[i]=ch[i]=0;
		}
		for (int j=1;j<=3;j++){
			cnt[j]=0;
		}
		for (int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int mx=max(a[i][1],max(a[i][2],a[i][3])),mx2=0;
			ans+=mx;
			for (int j=1;j<=3;j++){
				if (mx==a[i][j] && ch[i]==0){
					cnt[j]++;
					ch[i]=j;
				}else{
					mx2=max(mx2,a[i][j]);
				}
			}
			c[i]=mx-mx2;
		}
		for (int j=1;j<=3;j++){
			if (cnt[j]>n/2){
				for (int i=1;i<=n;i++){
					if (ch[i]!=j){
						c[i]=INT_MAX;
					}
				}
				sort(c+1,c+n+1);
				for (int i=1;i<=cnt[j]-n/2;i++){
					ans-=c[i];
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
