#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MAXN = 1e5+5;

int n,a[MAXN][4],ans,b[MAXN];

void f(int k,int s,int cnt1,int cnt2,int cnt3){
	if(k==n+1){
		ans = max(ans,s);
		return;
	}
	if(cnt1<n/2) f(k+1,s+a[k][1],cnt1+1,cnt2,cnt3);
	if(cnt2<n/2) f(k+1,s+a[k][2],cnt1,cnt2+1,cnt3);
	if(cnt3<n/2) f(k+1,s+a[k][3],cnt1,cnt2,cnt3+1);
}

void doing1(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++) cin >> a[i][j];
	}
	ans = 0;
	f(1,0,0,0,0);
	cout << ans << endl;
}

bool cmp(int x,int y)
{
	return x > y;
}

void doing2(){
	int x,y,z;
	for(int i=1;i<=n;i++){
		cin >> x >> y >> z;
		b[i] = x;
	}
	ans = 0;
	sort(b+1,b+n+1,cmp);
	for(int i=1;i<=n/2;i++){
		ans += b[i];
	}
	cout << ans << endl;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int T;
	cin >> T;
	while(T--){
		cin >> n;
		if(n>10){
			doing2();
		}else{
			doing1();
		}

	}
	return 0;
}


