#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
const int N = 2e5;
int t, n;
int s[N][3], r1[N], r2[N], r3[N];

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--)
	{
		cin >> n;
		int half = n/2;
		ll ans = 0;
		int cnt1=0, cnt2=0, cnt3=0;
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=3; j++){
				scanf("%d", &s[i][j]);
			}
			int a = s[i][1], b=s[i][2], c=s[i][3];
			if(a >= max(b, c)){
				r1[cnt1++] = a - max(b,c);
				ans += a;
			}
			else if(b >= max(a,c)){
				r2[cnt2++] = b - max(a, c);
				ans += b;
			}
			else{
				r3[cnt3++] = c- max(a, b);
				ans += c;
			}
		}
		sort(r1, r1+cnt1);
		sort(r2, r2+cnt2);
		sort(r3, r3+cnt3);
		if(cnt1 > half){
			for(int i=0; i<=cnt1-half-1; i++) ans -= r1[i];
		}
		if(cnt2 > half){
			for(int i=0; i<=cnt2-half-1; i++) ans -= r2[i];
		}
		if(cnt3 > half){
			for(int i=0; i<=cnt3-half-1; i++) ans -= r3[i];
		}
		cout << ans << endl;
	}
	return 0;
}
