#include <bits/stdc++.h>
using namespace std;
const int M = 100100;
int a[M][3],iw[M],cnt[3],n;
long long ans;
struct v{int a,b,i;}li[M],h[M];
bool cmp(v a,v b){return a.a - a.b < b.a - b.b;}
bool cmp2(v a,v b){
	return a.a < b.a;
}
void dfs(int i){
	for(int j = 0;j < 3;j ++ ){
		if(cnt[j] > n / 2) return;
	}
	if(i == n + 1){
		long long res = 0;
		for(int i = 1;i <= n;i ++ ) res += a[i][iw[i]];
		ans = max(ans,res);
	}
	for(int j = 0;j < 3;j ++ ){
		iw[i] = j;
		cnt[j] ++ ;
		dfs(i + 1);
		cnt[j] -- ;
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T -- ){
		memset(cnt,0,sizeof(cnt));
		memset(li,0,sizeof(li));
		memset(h,0,sizeof(h));
		ans = 0;
		scanf("%d",&n);
		for(int i = 1;i <= n;i ++ ) scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]),li[i].a = a[i][1]-a[i][0],li[i].b = a[i][2]-a[i][0],li[i].i=i,ans += a[i][0];
		if(n <= 30){
			dfs(1);
			cout << ans << '\n';
		}else{
			sort(li+1,li+n+1,cmp);
			for(int i = 1;i <= n / 2;i ++ ){
				ans += li[i].b;
				h[i].a = li[i].b;
				h[i].b = 1;
				iw[li[i].i] = 2;
			}
			for(int i = n / 2 + 1;i <= n;i ++ ){
				ans += li[i].a;
				h[i].a = li[i].a;
				h[i].b = 0;
				iw[li[i].i] = 1;
			}
			cnt[1]=n/2;cnt[2]=n/2;
			sort(h+1,h+1+n,cmp2);
			for(int i = 1;i <= n / 2;i ++ ){
				if(h[i].a < 0){
					ans -= h[i].a;
					if(h[i].b) cnt[2]--,cnt[0]++;
					else cnt[1]--,cnt[0]++;
					iw[li[i].i] = 0;
				}
			}
			for(int _ =0;_ < 5;_ ++ ){
				for(int i = 1;i <= n;i ++ ){
					for(int j = 0;j <= 2;j ++ ){
						if(j == iw[i]) continue;
						if(a[i][j] > a[i][iw[i]] && cnt[j] != n/2){
							cnt[j] ++ ;
							cnt[iw[i]] --;
							iw[i] = j;
							ans += a[i][j] - a[i][iw[i]];
						}
					}
				}
			}
			cout << ans << '\n';
		}
	}
	return 0;
}

