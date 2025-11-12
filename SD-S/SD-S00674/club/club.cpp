#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node {
	int a[4];
	int k;
} jb[114514];
bool cmp1(node x,node y) {
	return x.a[2]>y.a[2];
}
bool cmp2(node x,node y) {
	return x.a[3]>y.a[3];
}
int ans,x[114514];
int waya = 1,wayb = 1;
int maxn;
int _,n,m;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&_);
	while(_--) {
		waya = 1,wayb = 1;
		for(int i = 1; i <= 100000; i++) {
			jb[i].a[1] = 0,jb[i].a[2] = 0,jb[i].a[3] = 0;
			jb[i].k = 1;
			x[i] = 0;
		}
		scanf("%d",&n);
		ans = 0;
		m = n/2;
		for(int i = 1; i <= n; i++) {
			int y,z;
			scanf("%d%d%d",&x[i],&y,&z);
			jb[i].a[3] = z-x[i];
			jb[i].a[2] = y-x[i];
			jb[i].a[1] = x[i];
			ans += x[i];
			if(z) waya = 0;
			if(y&&z) wayb = 0;
		}
		if(ans == 0) waya = 0,wayb = 0;
		sort(jb+1,jb+1+n,cmp1);
		if(waya) {
			if(wayb) {
				ans = 0;
				sort(x+1,x+1+n);
				for(int i = m+1; i <= n; i++) ans += x[i];
			} else {
				for(int i = 1; i <= m; i++) {
					ans+=jb[i].a[2];
				}
			}
		} else {
			int i;
			int numa = n,numb = 0,numc = 0;
			for(i = 1; i <= m; i++) {
				ans+=jb[i].a[2];
				numa--;
				numb++;
				jb[i].k = 2;
			}
			sort(jb+1,jb+1+n,cmp2);
			for(i = 1; i <= n; i++) {
				if(numc<m){
					if(jb[i].k == 1&&jb[i].a[3]>0){
						numc++,numa--;
						ans+=jb[i].a[3];
						jb[i].k = 3;
					}else if(jb[i].k == 2&&jb[i].a[3]>0&&jb[i].a[3]>jb[i].a[2]){
						numc++,numb--;
						ans+=jb[i].a[3]-jb[i].a[2];
						jb[i].k = 3;
					}
				}else{
					break;
				}
			}
		}
		printf("%d\n",ans);
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
