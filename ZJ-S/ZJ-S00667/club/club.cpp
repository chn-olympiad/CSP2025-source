#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+3;
const int M=203;
int n,a[3][N];
int d[N][3],cnt[3],ans;
void Main(){
	cin>>n; ans=0;
	memset(cnt,0,sizeof(cnt));
	for (int i=1;i<=n;i++){
		cin>>d[i][0]>>d[i][1]>>d[i][2];
		if (d[i][0]>=d[i][1] && d[i][0]>=d[i][2]){
			a[0][++cnt[0]]=max(d[i][1],d[i][2])-d[i][0];
			ans+=d[i][0];
		}
		else if (d[i][1]>=d[i][2]){
			a[1][++cnt[1]]=max(d[i][0],d[i][2])-d[i][1];
			ans+=d[i][1];
		}
		else{
			a[2][++cnt[2]]=max(d[i][0],d[i][1])-d[i][2];
			ans+=d[i][2];
		}
	}
//	cout<<"sum="<<ans<<"\n";
	int t=-1;
	for (int i=0;i<3;i++){
		if (cnt[i]>n/2) t=i;
	}
	if (~t){
//		cout<<"t="<<t<<"\n";
		sort(a[t]+1,a[t]+cnt[t]+1);
//		for (int i=1;i<=cnt[t];i++) cout<<a[t][i]<<" "; cout<<"\n";
		for (int i=cnt[t];i>n/2;i--) ans+=a[t][i];
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T; cin>>T; while (T--) Main();
	return 0;
}

