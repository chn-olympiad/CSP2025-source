#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e6 + 10;

/*
cant give the proof
but ,have a try
*/

ll T;
ll n ,f[N];
struct Syca { //1e5 Sycamore_TYs come to the club!!!
	ll a ,b ,c;
}ns[N];
ll ms[N][4];

struct Syca2 {
	ll a ,b ,bel; //a : max   b : 2nd max  bel : belong ???
}ns2[N];
bool cmp5(Syca2 a ,Syca2 b) {
	return (a.b - a.a) > (b.b - b.a);
}

struct zy {
	ll idx ,val;
} cnt[5];
bool cmp4(zy a ,zy b) {
	return a.val < b.val;
}

int main() {
	freopen("club.in" ,"r" ,stdin);
	freopen("club.out" ,"w" ,stdout);
	scanf("%lld" ,&T);
	for (;T--;) {
		scanf("%lld" ,&n);
		for(int i=1 ;i<=n ;i++) {
			scanf("%lld %lld %lld" ,&ns[i].a ,&ns[i].b ,&ns[i].c);
		}
		//cout<<tmp<<endl;
		//printf("%lld\n" ,ans);
		// work d
		cnt[1].val = cnt[2].val = cnt[3].val = 0;
		cnt[1].idx = 1 ,cnt[2].idx = 2 ,cnt[3].idx = 3;
		ll flag = 0;
		ll tmp = 0;
		for (int i=1 ;i<=n ;i++) {
			ms[i][1] = ns[i].a;
			ms[i][2] = ns[i].b;
			ms[i][3] = ns[i].c;
		}
		for (int i=1 ;i<=n ;i++) {
			if (flag) {
				break;
			}
			ll maxx = max(ns[i].a ,max(ns[i].b ,ns[i].c));
			//tmp+=maxx;
			sort(cnt+1 ,cnt+4 ,cmp4);
			for (int j=1 ;j<=3 ;j++) {
				//cout<<ms[i][cnt[j].idx]<<" "<<maxx<<endl;
				if (ms[i][cnt[j].idx] == maxx) {
					tmp += maxx;
					cnt[j].val ++;
					ns2[i].bel = cnt[j].idx;
					ns2[i].a = maxx;
					if (cnt[j].idx == 1) {
						ns2[i].b = max(ns[i].b ,ns[i].c);
					}
					if (cnt[j].idx == 2) {
						ns2[i].b = max(ns[i].a ,ns[i].c);
					}
					if (cnt[j].idx == 3) {
						ns2[i].b = max(ns[i].b ,ns[i].a);
					}
					break;
				}
			}
			//cout<<endl;
		}
		sort(cnt+1 ,cnt+4 ,cmp4);
		ll del = cnt[3].val;
		//if (T == 1) printf("%lld\n" ,tmp);
		if (del > n/2) {
			del -= n/2;
			sort(ns2+1 ,ns2+1+n ,cmp5);
			//if (T == 1) printf("%lld\n" ,del);
			for (int i=1 ;i<=n ;i++) {
				if (ns2[i].bel == cnt[3].idx) {
					tmp += (ns2[i].b - ns2[i].a);
					del--;
				}
				if (del <= 0) {
					break;
				}
			}
		}
		printf("%lld\n" ,tmp);
	}
	
	return 0;
}
/*
1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
*/
