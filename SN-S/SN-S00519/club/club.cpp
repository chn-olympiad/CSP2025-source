#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10,inf=1e9;
int a[N][3],n,b[N];
int num[10];
int ans=0;
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--){
		memset(num,0,sizeof(num));
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			int w=max(a[i][0],max(a[i][1],a[i][2]));
			ans+=w;
			if(a[i][0]==w)num[0]++,b[i]=0;
			else if(a[i][1]==w)num[1]++,b[i]=1;
			else num[2]++,b[i]=2;
		}
		if(num[0]<=n/2&&num[1]<=n/2&&num[2]<=n/2){
			cout<<ans<<"\n";
			continue;
		}
		int p=0;if(num[1]>num[p])p=1;if(num[2]>num[p])p=2;
		int c=num[p]-n/2;
		priority_queue<int>q;
		for(int i=1;i<=n;i++){
			if(b[i]!=p)continue;
			int w=-inf;
			for(int j=0;j<=2;j++)if(j!=p)w=max(w,a[i][j]-a[i][p]);
			q.push(w);
		}
		while(c--){
			ans+=q.top();q.pop();
		}
		cout<<ans<<"\n";
	}
	return 0;
}
