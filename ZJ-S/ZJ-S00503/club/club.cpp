#include <bits/stdc++.h>
using namespace std;

namespace quick_io{
	template<typename T>
	void input(T &x){
		x=0;
		bool f=0;
		char ch=' ';
		while(ch<'0'||ch>'9'){
			if(ch=='-') f=1;
			ch=getchar();
		}
		while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
		if(f) x=-x;
	}
	
	template<typename T>
	void print(T x){
		if(x<0) putchar('-'),x=-x;
		if(x>10) print(x/10);
		putchar(x%10+'0');
	}
}
using namespace quick_io;
#define int long long
const int N=1e5+10;

int a[N][5];
int n;
int d1,d2,d3;

int cnt[4];
vector<int> v;
bool cmp(int A,int B){
	return a[A][d1]+max(a[B][d2],a[B][d3])>max(a[A][d2],a[A][d3])+a[B][d1];
}
void solve(){
	cnt[1]=cnt[2]=cnt[3]=0;
	v.clear();
	input(n);
	for(int i=1;i<=n;i++)
		input(a[i][1]),input(a[i][2]),input(a[i][3]);
	for(int i=1;i<=n;i++){
		int t=max({a[i][1],a[i][2],a[i][3]});
		if(a[i][1]==t) a[i][0]=1,cnt[1]++;
		else if(a[i][2]==t) a[i][0]=2,cnt[2]++;
		else a[i][0]=3,cnt[3]++;
	}
	if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/3){
		int ans=0;
		for(int i=1;i<=n;i++) ans+=a[i][a[i][0]];
		print(ans);
		putchar('\n');
		return;
	}
	if(cnt[1]>n/2) d1=1,d2=2,d3=3;
	else if(cnt[2]>n/2) d1=2,d2=1,d3=3;
	else if(cnt[3]>n/2) d1=3,d2=1,d3=2;
	for(int i=1;i<=n;i++) if(a[i][0]==d1) v.push_back(i);
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();i++) if(i>=n/2) a[v[i]][0]=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i][0]) ans+=a[i][a[i][0]];
		else ans+=max(a[i][d2],a[i][d3]);
	}
	print(ans);
	putchar('\n');
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	input(T);
	while(T--) solve();	
}
