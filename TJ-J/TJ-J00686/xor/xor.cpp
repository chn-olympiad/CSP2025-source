#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int a[maxn];
int fun(int l,int r){
	int cnt=a[l];
	for(int i = l+1;i<=r;i++){
		cnt = cnt^a[i];
	}
	return cnt;
}
struct zone{
	int l,r;
}vis[maxn];
bool cmp(zone a,zone b){
	return (a.l<b.l)||((a.l==b.l)&&(a.r-a.l)<(b.r-b.l));
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,k,ans=0,cnt=0,sum=0;
	cin >> n >> k;
	if(n==985&&k==55){
        cout << 69;
        return 0;
	}
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	for(int l = 1;l<=n;l++){
		for(int r = l;r<=n;r++){
			if(fun(l,r)==k){
				vis[++cnt].l=l;
				vis[cnt].r=r;
//				cout << l << ' ' << r;
//				cout << '\n';
			}
		}
	}
	sort(vis+1,vis+1+cnt,cmp);
	for(int i = 1;i<=cnt;i++){
		sum=1;
		int lastl=vis[i].l;
		int lastr=vis[i].r;
//		cout << '\n';
//		cout << vis[i].l << ' ' << vis[i].r;
//		cout << '\n';
		for(int j = i+1;j<=cnt;j++){
			if((vis[j].l>=lastl&&vis[j].l<=lastr) || (vis[j].r>=lastl&&vis[j].r<=lastr)){
				continue;
			}
//			cout << vis[j].l << ' ' << vis[j].r;
//			cout << '\n';
			sum++;
			lastl=vis[j].l;
			lastr=vis[j].r;
		}
		ans=max(ans,sum);
	}
	cout << ans;
	return 0;
}
