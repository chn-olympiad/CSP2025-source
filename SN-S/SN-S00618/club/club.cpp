#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int T,n;
int a1_,a2_,a3_;
struct node {
	int id;
	int a1,a2,a3;
}a[100005],b[100005],c[100005];
bool f1[100005],f2[100005],f3[100005];
bool cmp1(node x,node y) { return x.a1 > y.a1; }
bool cmp2(node x,node y) { return x.a2 > y.a2; }
bool cmp3(node x,node y) { return x.a3 > y.a3; }
int main() {	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--) {
		int ans = 0;
		queue<int> q;
		cin >> n;
		for(int i = 1;i<=n;i++) {
			cin >> a1_ >> a2_ >> a3_;
			a[i].id = i,b[i].id = i,c[i].id = i;
			a[i].a1 = a1_,a[i].a2 = a2_,a[i].a3 = a3_;
			b[i].a1 = a1_,b[i].a2 = a2_,b[i].a3 = a3_;
			c[i].a1 = a1_,c[i].a2 = a2_,c[i].a3 = a3_;
		}
		sort(a + 1,a + n + 1,cmp1);	
		int k1 = n / 2 + 1;
		for(int i = 1;i<=n / 2;i++) {
			ans += a[i].a1;
			f1[a[i].id] = 1;
		}
		sort(b + 1,b + n + 1,cmp2);
		int sum1 = 0;
		for(int i = 1;i<=n && sum1 < n / 2;i++) {
			if(f1[b[i].id]) {
				if(b[i].a1 < b[i].a2) {
					ans-=b[i].a1; f1[b[i].id] = 0;
					ans+=b[i].a2; f2[b[i].id] = 1;
					sum1++;
				} else q.push(i);
			} else ans+=b[i].a2,f2[b[i].id] = 1,sum1++;
		}
		sort(c + 1,c + n + 1,cmp3);
		int sum2 = 0;
		for(int i = 1;i<=n && sum2 < n / 2;i++) {
			if(f1[c[i].id]) {
				if(c[i].a1 < c[i].a3) {
					ans-=c[i].a1; f1[c[i].id] = 0;
					ans+=c[i].a3; f3[c[i].id] = 1;
					sum2++;
				}
			} else if(f2[c[i].id]) {
				if(c[i].a2 < c[i].a3) {
					ans-=c[i].a2; f2[c[i].id] = 0;
					ans+=c[i].a3; f3[c[i].id] = 1;
					sum2++;
				}
			} else ans+=c[i].a3,f3[c[i].id] = 1,sum2++;
		}
		cout << ans << "\n";
	}
	return 0;
} 
/*
3
4
4 2 1 
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/

