#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
pair<int,int> a[N][4];
pair<int,int> t[4];
int b[N],tot;
int n,ans;
bool cmp(pair<int,int> x,pair<int,int> y){
	return x.first>y.first;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>a[i][j].first,a[i][j].second=j;
		for(int i=1;i<=3;i++)
			t[i].first=0,t[i].second=i;
		for(int i=1;i<=n;i++){
			sort(a[i]+1,a[i]+4,cmp);
			t[a[i][1].second].first++;
			ans+=a[i][1].first;
		}
		sort(t+1,t+4,cmp);
		tot=0;
		for(int i=1;i<=n;i++)
			if(t[1].second==a[i][1].second)
				b[++tot]=a[i][1].first-a[i][2].first;
		sort(b+1,b+1+tot);
		tot=0;
		while(t[1].first>n/2)
			ans-=b[++tot],t[1].first--;
		cout<<ans<<'\n';
	}
	return 0;
}
