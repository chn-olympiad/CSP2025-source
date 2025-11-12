#include<bits/stdc++.h>
using namespace std;
int n, TT;
long long ans;
struct st{
	int x, y, z;
};

st a[100010];
//bool cmp(st x, st y){
//	return x.x - x.y > y.x - y.y;
//}
//bool cmp2(pair<int, int> x, pair<int, int> y){
//	return x.first > y.first;
//}
//int cur, i, cnt, rpos, lpos;
//pair<int, int> ater[100010];
//bool removed[100010];
long long cnts[3];
int ncnt[3];
// shen me gui a wo cao
// suan le, wo shi lai pian fen de QwQ
void generatet(){
	cnts[0] = 0;
	cnts[1] = 0;
	cnts[2] = 0;
	ncnt[0] = 0;
	ncnt[1] = 0;
	ncnt[2] = 0;
	for (int i = 1;i <= n;i ++){
		if (max(max(a[i].x, a[i].y), a[i].z) == a[i].x){
			if (ncnt[0] == n / 2){
				if (max(a[i].y, a[i].z) == a[i].y){
					cnts[1] += a[i].y;
					ncnt[1] ++;
				}
				else{
					cnts[2] += a[i].z;
					ncnt[2] ++;
				}
			}
			else{
				cnts[0] += a[i].x;
				ncnt[0] ++;
			}
			
		}
		else{
			if (max(max(a[i].x, a[i].y), a[i].z) == a[i].y){
				if (ncnt[1] == n / 2){
					if (max(a[i].x, a[i].z) == a[i].x){
						cnts[0] += a[i].x;
						ncnt[0] ++;
					}
					else{
						cnts[2] += a[i].z;
						ncnt[2] ++;
					}
				}
				else{
					cnts[1] += a[i].y;
					ncnt[1] ++;
				}
				
			}
			else{
				if (ncnt[2] == n / 2){
					if (max(a[i].y, a[i].x) == a[i].x){
						cnts[0] += a[i].x;
						ncnt[0] ++;
					}
					else{
						cnts[1] += a[i].y;
						ncnt[1] ++;
					}
				}
				else{
					cnts[2] += a[i].z;
					ncnt[2] ++;
				}
				
			}
		}
	}
	ans = max(ans, cnts[0] + cnts[1] + cnts[2]);
	return;
}
// wo mei zhao le
bool cmp1(st x, st y){
	return x.x > y.y;
}
bool cmp2(st x, st y){
	return x.x < y.y;
}
bool cmp3(st x, st y){
	return x.y > y.z;
}
bool cmp4(st x, st y){
	return x.y < y.z;
}
bool cmp5(st x, st y){
	return x.z > y.x;
}
bool cmp66(st x, st y){
	return x.z < y.x;
}
bool cmp7(st x, st y){
	return x.x - x.y > y.x - y.y;
}
bool cmp8(st x, st y){
	return x.x - x.y < y.x - y.y;
}
bool cmp9(st x, st y){
	return x.y - x.z > y.y - y.z;
}
bool cmp10(st x, st y){
	return x.y - x.z < y.y - y.z;
}
bool cmp11(st x, st y){
	return x.z - x.x > y.z - y.x;
}
bool cmp12(st x, st y){
	return x.z - x.x < y.z - y.x;
}
bool cmp91(st x, st y){
	return x.x + x.y + x.z > y.x + y.y + y.z;
}
bool cmp69(st x, st y){
	return x.x + x.y + x.z < y.x + y.y + y.z;
}
// sha bi xue xiao zhou ri zao shang shang ke
// ji le
// zhe zen me zuo a
long long dfscur;
int cntsss[3];
void dfs(int x){
	if (x > n){
		ans = max(ans, dfscur);
		return ;
	}
	if (cntsss[0] < n / 2){
		dfscur += a[x].x;
		cntsss[0] ++;
		dfs(x + 1);
		cntsss[0] --;
		dfscur -= a[x].x;
	}
	if (cntsss[1] < n / 2){
		dfscur += a[x].y;
		cntsss[1] ++;
		dfs(x + 1);
		cntsss[1] --;
		dfscur -= a[x].y;
	}
	if (cntsss[2] < n / 2){
		dfscur += a[x].z;
		cntsss[2] ++;
		dfs(x + 1);
		cntsss[2] --;
		dfscur -= a[x].z;
	}
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d", &TT);
	while (TT --){
		scanf("%d", &n);
		ans = 0;
//		cout<<n;
 		for (int i = 1;i <= n;i ++){
			scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
		}
		if (n <= 10){
			dfs(1);
		}
		else{
			generatet();
			for (int i = 1;i <= 10;i ++){
				sort(a + 1, a + n + 1, cmp1);
				generatet();
				sort(a + 1, a + n + 1, cmp2);
				generatet();
				sort(a + 1, a + n + 1, cmp3);
				generatet();
				sort(a + 1, a + n + 1, cmp4);
				generatet();
				sort(a + 1, a + n + 1, cmp5);
				generatet();
		//		sort(a + 1, a + n + 1, cmp66);
		//		generatet();
				sort(a + 1, a + n + 1, cmp7);
				generatet();
				sort(a + 1, a + n + 1, cmp8);
				generatet();
				sort(a + 1, a + n + 1, cmp9);
				generatet();
				sort(a + 1, a + n + 1, cmp10);
				generatet();
				sort(a + 1, a + n + 1, cmp11);
				generatet();
				sort(a + 1, a + n + 1, cmp12);
				generatet();
				sort(a + 1, a + n + 1, cmp91);
				generatet();
				sort(a + 1, a + n + 1, cmp69);
				generatet();
				next_permutation(a + 1, a + n + 1, cmp91);
			}
		}
		printf("%lld\n", ans);
//		sort(a + 1, a + n + 1, cmp);
//		cur = 0;	
//		for (i = 1;i <= n;i ++){
//			if (a[i].x > a[i].y){
//				ater[i].first = a[i].x;
//				ater[i].second = i;
//				cur ++;
//			}
//			else{
//				ater[i].first = a[i].y;
//				ater[i].second = i;
//			}
//		}
//		sort(ater + 1, ater + 1 + cur, cmp2);
//		sort(ater + cur + 2, ater + 1 + n, cmp2);
//		rpos = n;
//		lpos = cur;
//		cnt = 0;
//		if (cur != n / 2){
//			if (cur < n / 2){
//				for (i = n;i >= n / 2 + cur;i --){
//					ater[i].first = 0;
//					cnt ++;
//				}
//				rpos = i;
//			}
//			else{
//				for (i = cur;i > n / 2;i --){
//					ater[i].first = 0;
//					cnt ++;
//				}
//				lpos = i;
//			}
//		}
//		while (cnt < n / 2){
//			if ((ater[lpos].first >= 0 && ater[rpos].first >= 0) || rpos <= cur || lpos < 1) break;
//			if (ater[lpos].first >= 0 && ater[rpos].first < 0) {
//				ater[rpos].first = 0;
//				rpos --;
//				cnt ++;
//			}
//			else {
//				if (ater[lpos].first < 0 && ater[rpos].first >= 0){
//					ater[lpos].first = 0;
//					lpos --;
//					cnt ++;
//				}
//				else{
//					if (ater[lpos].first > ater[rpos].first){
//						ater[rpos].first = 0;
//						rpos --;
//						cnt ++;
//					}
//					else{
//						ater[lpos].first = 0;
//						lpos --;
//						cnt ++;
//					}
//				}
//			}
//		}
//		if (cnt < n / 2){
//			while (cnt < n / 2 && ater[rpos].first < 0 && rpos > cur){
//				ater[rpos].first = 0;
//				rpos --;
//				cnt ++;
//			}
//			while (cnt < n / 2 && ater[lpos].first < 0 && lpos > 0){
//				ater[lpos].first = 0;
//				lpos --;
//				cnt ++;
//			}
//		}
//		for (int i = 1;i <= n;i ++){
//			ans += ater[i].first;
//		}
		
	}
	return 0;
}
// 

// 4 2 1
// 3 2 4
// 5 3 4
// 3 5 1
//max

// 6 3 5
// 5 6 7
// 8 7 9
// 8 6 4
// min
