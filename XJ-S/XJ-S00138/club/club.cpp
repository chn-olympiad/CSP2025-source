#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define of(i,a,b) for(int i=b;i>=a;i--)
#define INF INT_MAX
using namespace std;
typedef long long ll;
typedef double db;

void frop() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
}

void IOP() {
	cin.tie(0) ,cout.tie(0);
	ios::sync_with_stdio(0);
}

const int N = 1e5+5;
int T,n;

struct asd {
	int a,b,c;
} a[N];

bool cmp1(asd x,asd y){
	return x.a > y.a;
}

bool cmp2(asd x,asd y){
	return x.b > y.b;
}

void solve() {
	int ans = 0,max1,max2,max3;
	bool xza=0,xzb=0;
	
	cin>>n;
	fo(i,1,n) {
		cin>>a[i].a>>a[i].b>>a[i].c;
		if(a[i].b == a[i].c == 0)xza = 1;
		if(a[i].c == 0)xzb = 1;
	}
	
	sort(a+1,a+n+1,cmp1);
//	for(int i=1;i<=n;i++){
//		printf("第%d a:%d b:%d c:%d 差:%d %d\n",i,a[i].a,a[i].b,a[i].c,a[i].d[1],a[i].d[2]);
//	}
	if(xza){
		for(int i=1;i<=n/2;i++)ans+=a[i].a;
	}else if(xzb){
		for(int i=1;i<=n/2;i++)ans+=a[i].a;
		sort(a+1,a+n+1,cmp2);
		for(int i=1;i<=n/2;i++)ans+=a[i].b;
	}
	
	cout<<ans<<"\n";
}
// 1 4 4 2 1 3 2 4 5 3 4 3 5 1
/*
3 4 4 2 1 3 2 4 5 3 4 3 5 1
4 0 1 0 0 1 0 0 2 0 0 2 0 2 10 9 8 4 0 0
*/
signed main() {
	frop();//必须检查 必须检查 必须检查 必须检查 必须检查 必须检查
	IOP();//注意c风格输入输出 注意c风格输入输出 注意c风格输入输出

	cin>>T;
	while(T--) {
		memset(a,0,sizeof(a));
		solve();
	}

	return 0;
}

