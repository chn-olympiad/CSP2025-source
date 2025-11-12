#include<bits/stdc++.h>
#define int long long

using namespace std;
const int N=1e5+5;
int n,a[N][4];
int st[N],ans;
int cnt1,cnt2,cnt3;
bool cmp(int x,int y) {
	return x>y;
}
void solve() {
	cin>>n;
	ans=0,cnt1=0,cnt2=0,cnt3=0;
	for(int i=1;i<=n;++i)cin>>a[i][1]>>a[i][2]>>a[i][3];
	for(int i=1;i<=n;++i) {
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) {
			st[i]=1;
			cnt1++;
			ans+=a[i][1];
		}
		else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) {
			st[i]=2;
			cnt2++;
			ans+=a[i][2];
		}
		else {
			st[i]=3;
			cnt3++;
			ans+=a[i][3];
		}
	}
	if(cnt1>(n>>1)) {
		vector<int>val;
		for(int i=1;i<=n;++i) {
			if(st[i]!=1)continue;
			val.push_back(max(a[i][2],a[i][3])-a[i][1]);
		}
		sort(val.begin(),val.end(),cmp);
		for(int i=(n>>1);i<cnt1;++i)ans+=val[i-(n>>1)];
	}
	else if(cnt2>(n>>1)) {
//		cout<<"?????????\n";
		vector<int>val;
		for(int i=1;i<=n;++i) {
			if(st[i]!=2)continue;
			val.push_back(max(a[i][1],a[i][3])-a[i][2]);
		}
		sort(val.begin(),val.end(),cmp);
		for(int i=(n>>1);i<cnt2;++i)ans+=val[i-(n>>1)];
	}
	else if(cnt3>(n>>1)) {
		vector<int>val;
		for(int i=1;i<=n;++i) {
			if(st[i]!=3)continue;
			val.push_back(max(a[i][1],a[i][2])-a[i][3]);
		}
		sort(val.begin(),val.end(),cmp);
		for(int i=(n>>1);i<cnt3;++i)ans+=val[i-(n>>1)];
	}
	cout<<ans<<"\n";
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int _ = 1;
	cin >> _;
	while(_--)solve();
	return 0;
}
