#include<bits/stdc++.h>
#define int long long
using namespace std;

int t,ans,n,c[5];
struct node{int s,id;}b[4];
struct nod{int f,ff,s,ss,cz;}a[100005];

bool cmp(node a,node b){
	return a.s > b.s;
}
bool cmp1(nod a,nod b){
	return a.cz > b.cz;
}
void solve(){
	ans=0;memset(c,0,sizeof(c));
	cin >> n;
	int d = n/2;
	for(int i = 1;i <= n;i++){
		cin >> b[1].s >> b[2].s >> b[3].s;
		b[1].id=1,b[2].id=2,b[3].id=3;
		sort(b+1,b+3+1,cmp);
		a[i].f = b[1].id,a[i].ff=b[1].s,a[i].s=b[2].id,a[i].ss=b[2].s,a[i].cz=b[1].s-b[2].s;
	}
	sort(a+1,a+n+1,cmp1);
	for(int i = 1;i <= n;i++){
		int x = a[i].f,y=a[i].s;
		if(c[x]>=d){c[y]++;ans+=a[i].ss;}
		else {c[x]++,ans+=a[i].ff;}
	}
	cout << ans << "\n";
}

signed main(){
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
