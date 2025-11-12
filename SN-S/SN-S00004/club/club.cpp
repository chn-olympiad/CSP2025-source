// 丁家淳 SN-S00004 渭南高级中学 
#include<bits/stdc++.h>
using namespace std;

int t,ans,n,v[200002][3];
bool A;

inline void q(int c1,int c2,int c3,int r,int w,int x){
	if(r == n + 1){
		ans = max(ans,w);
		return;
	}
	if(c1 + 1 <= x)
		q(c1+1,c2,c3,r + 1,w + v[r][1],x);
	if(c2 + 1 <= x)
		q(c1,c2+1,c3,r + 1,w + v[r][2],x);
	if(c3 + 1 <= x)
		q(c1,c2,c3+1,r + 1,w + v[r][3],x);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans = 0;
		scanf("%d",&n);
		int x = n / 2;
		for(int i = 1;i <= n;i++){
			scanf("%d%d%d",&v[i][1],&v[i][2],&v[i][3]);
			if(v[i][2] != 0 || v[i][3] != 0)
				A = 1;
		}
		if(A = 0){
			for(int i = 1;i <= n;i++){
				for(int j = i;j <= n;j++){
					if(v[j][1] >= v[i][1])
					swap(v[j][1],v[i][1]);
				}
			}
			for(int i = 1;i <= x;i++){
				ans += v[i][1];
			}
			printf("%d\n",ans);
			continue;
		}
		q(0,0,0,1,0,x);
		printf("%d\n",ans);
	}
	return 0;
}
