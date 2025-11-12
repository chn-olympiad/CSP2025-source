#include <bits/stdc++.h>
#define i64 long long
using namespace std;

const int N = 5e3+10;
const i64 MOD = 998224353;
int n;
i64 a[N];
i64 ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int S=0;S<(1<<(n+1));S++){
		i64 sum=0,mx=0,cnt=0;
		for(int i=0;i<=20;i++){
			if(S&(1<<i)) cnt++,sum+=a[i],mx=max(mx,a[i]);
		}if(cnt<3) continue;
		if(sum>mx*2) ans=(ans+1)%MOD;
	}cout<<ans/2<<endl;
	return 0;
}
