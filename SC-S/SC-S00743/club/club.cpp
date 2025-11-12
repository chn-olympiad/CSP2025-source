#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+8;
struct Edge{
	int a;
	int b;
	int c;
}a[N];
struct Node {
	int num;
	int a;
	int b;
	int c;
} dp[N][4];
struct Data {
	int id;
	int num;
}num[4];
int cnt[4];
bool cmp(Edge x,Edge y) {
	int a[4]={0,x.a,x.b,x.c};
	int b[4]={0,y.a,y.b,y.c};
	sort(a+1,a+4);
	sort(b+1,b+4);
	if(a[3]==b[3]) {
		if(a[2]==b[2]) {
			return a[1]>b[1];
		}
		return a[2]>b[2];
	}
	return a[3]>b[3];
}
bool _cmp(Edge x,Edge y) {
	int a[4]={0,x.a,x.b,x.c};
	int b[4]={0,y.a,y.b,y.c};
	sort(a+1,a+4);
	sort(b+1,b+4);
	if(a[3]==b[3]) {
		if(a[2]==b[2]) {
			return a[1]<b[1];
		}
		return a[2]<b[2];
	}
	return a[3]<b[3];
}
bool cmp2(Data a,Data b) {
	if(a.num==b.num){
		return cnt[a.id]<cnt[b.id];
	} 
	return a.num>b.num;
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	int T;
	cin>>T;
	while(T--) {
		memset(dp,0,sizeof dp);
		memset(a,0,sizeof a);
		int n;
		cin>>n;
		int t=n/2;
		for(int i=1; i<=n; ++i) {
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		sort(a+1,a+n+1,cmp);
		int ans1=0;
		memset(cnt,0,sizeof cnt);
		for(int i=1; i<=n; ++i) {
			num[0] = {0,0};
			num[1] = {1,a[i].a};
			num[2] = {2,a[i].b};
			num[3] = {3,a[i].c};
			sort(num+1,num+4,cmp2);
			if(cnt[num[1].id]<t) {
				++cnt[num[1].id];
				ans1+=num[1].num;
				
			} 
			else{
				++cnt[num[2].id];
				ans1+=num[2].num;
			} 
		}
		sort(a+1,a+n+1,_cmp);
		int ans2=0;
		memset(cnt,0,sizeof cnt);
		for(int i=1; i<=n; ++i) {
			num[0] = {0,0};
			num[1] = {1,a[i].a};
			num[2] = {2,a[i].b};
			num[3] = {3,a[i].c};
			sort(num+1,num+4,cmp2);
			if(cnt[num[1].id]<t) {
				++cnt[num[1].id];
				ans2+=num[1].num;
				
			} 
			else{
				++cnt[num[2].id];
				ans2+=num[2].num;
			} 
		}
		cout<<max(ans1,ans2)<<"\n";
	}
	return 0;
}