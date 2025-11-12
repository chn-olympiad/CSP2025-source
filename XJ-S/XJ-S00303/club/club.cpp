#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100005;
bool vis[maxn];
int a[maxn][10];
struct Poeple {
	int max_id,maxx;
	int mix_id,mixx;
} p[maxn];
int t1[maxn],t2[maxn],t3[maxn];
bool cmp(int x,int y) {
	return p[x].maxx>p[y].maxx;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T,n;
	cin >> T;
	while(T--) {
		int tot1=0,tot2=0,tot3=0;
		cin >> n;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=3; j++) {
				cin >> a[i][j];
			}
		}
		for(int i=1; i<=n; i++) {
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) {
				t1[++tot1]=i;
				p[i].max_id=1;
				p[i].maxx=a[i][1]-max(a[i][2],a[i][3]);
				p[i].mixx=max(a[i][2],a[i][3])-min(a[i][2],a[i][3]);
				if(a[i][2]>a[i][3]) {
					p[i].mix_id=2;
				} else {
					p[i].mix_id=3;
				}
			} else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) {
				t2[++tot2]=i;
				p[i].max_id=2;
				p[i].maxx=a[i][2]-max(a[i][1],a[i][3]);
				p[i].mixx=max(a[i][1],a[i][3])-min(a[i][1],a[i][3]);
				if(a[i][1]>a[i][3]) {
					p[i].mix_id=1;
				} else {
					p[i].mix_id=3;
				}
			} else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]) {
				t3[++tot3]=i;
				p[i].max_id=3;
				p[i].maxx=a[i][3]-max(a[i][2],a[i][1]);
				p[i].mixx=max(a[i][2],a[i][1])-min(a[i][2],a[i][1]);
				if(a[i][2]>a[i][1]) {
					p[i].mix_id=2;
				} else {
					p[i].mix_id=1;
				}
			}
		}
//		for(int i=1;i<=n;i++)
//		{
//			cout << p[i].max_id << ' ' << p[i].maxx << '\n';
//		}
		sort(t1+1,t1+tot1+1,cmp);
		sort(t2+1,t2+tot2+1,cmp);
		sort(t3+1,t3+tot3+1,cmp);
		int ans=0;
		for(int i=1; i<=tot1; i++) {
			if(i>n/2) {
				ans+=a[t1[i]][p[t1[i]].mix_id];
				continue;
			}
			ans+=a[t1[i]][p[t1[i]].max_id];
		}
//		cout << ans << '\n'; 
		for(int i=1; i<=tot2; i++) {
			if(i>n/2) {
				ans+=a[t2[i]][p[t2[i]].mix_id];
				continue;
			}
			ans+=a[t2[i]][p[t2[i]].max_id];
		}
//		cout << ans << '\n';
		for(int i=1; i<=tot3; i++) {
			if(i>n/2) {
				ans+=a[t3[i]][p[t3[i]].mix_id];
				continue;
			}
			ans+=a[t3[i]][p[t3[i]].max_id];
		}
		cout << ans << '\n';
	}
	fclose(stdin);
	fclose(stdout);
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
