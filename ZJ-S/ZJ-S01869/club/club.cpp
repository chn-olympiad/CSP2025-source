#include <bits/stdc++.h>
using namespace std;

const int N=1000011;
int T,n,cnt[3],a[N][3],sel[N],tmp[N],top;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);

	cin>>T;

	while (T--){
		cin>>n;
		for (int i=1;i<=n;++i) for (int j=0;j<3;++j) cin>>a[i][j];
		long long ans=0;
		for (int i=0;i<3;++i) cnt[i]=0;
		top=0;
		for (int i=1;i<=n;++i){
			int j=0;
			if (a[i][1]>a[i][j]) j=1;
			if (a[i][2]>a[i][j]) j=2;
			sel[i]=j;
			ans+=a[i][j];
			++cnt[j];
		}
		int err=-1;
		for (int i=0;i<3;++i) if (cnt[i]>n/2) err=i;
		if (err==-1) cout<<ans<<'\n';
		else{
			top=0;
			for (int i=1;i<=n;++i) if (sel[i]==err){
				tmp[++top]=a[i][err]-max(a[i][(err+1)%3],a[i][(err+2)%3]);
			}
			sort(tmp+1,tmp+top+1);
			for (int i=1;i<=cnt[err]-n/2;++i) ans-=tmp[i];
			cout<<ans<<'\n';
		}
	}

	return 0;
}