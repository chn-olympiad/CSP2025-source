//SN-J00199  吴禹泽  陕西延安中学
#include<iostream>
#include<cstring>
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int n, k;
int a[500005];
int vis[500005];  //vis[i]表示一个从i开始长度为vis[i] 的区间 

inline bool check(int mid) {
	memset(vis, -1, sizeof(vis));
	int ans = 0;
//	printf("\n当前check mid = %d\n", mid);
	for(int i=1; i<=n; i++) {  //所有长度 
//		printf("\n当前枚举长度为 %d 的区间\n", i);
		for(int j=1; j+i-1<=n; j++) {  //区间起点 
//			printf("\n当前枚举起点为 %d 的区间\n", j);
			if(vis[j] != -1) {
				j += vis[j];
//				printf("撞到之前的区间，不合法。\n");
				continue;
			}
			int t = a[j];
			for(int k1=j+1; k1<=j+i-1; k1++) {
				if(vis[k1] != -1) {
					j += vis[k1];
//					printf("撞到之前的区间，不合法。\n");
					break;
				}
				t ^= a[k1];
			} 
			if(t == k) {
//				printf("找到一个区间 [%d, %d] ，异或和为 %d\n", j, j+i-1, t);
				ans++;
				vis[j] = i-1;
				vis[j+i-1] = 0;
			}
		}
		
		if(ans >= mid){
			return 1;
//			printf("----------退出----------\n\n"); 
		}
	}
//	cout<<'\n'<<"ans="<<ans<<'\n';
	return 0;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	fastio;
	
	
	cin>>n>>k;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	
	int l = 0, r = n;
	while(l < r){
		int mid = l + r + 1 >> 1;
//		cout<<l<<' '<<r<<' '<<mid<<'\n';
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	cout<<l;
	return 0;
}
