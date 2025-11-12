#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,lt,ans,cnt,sum,a[N];
struct Node {
	int x,y;
}b[N];
bool cmp(Node g,Node h) {
	return g.y<h.y;
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) {
		for (int j=i;j<=n;j++) {
			if (j==i) sum=a[j];
			else sum=sum^a[j];
			if (sum==k) {
				b[++cnt]={i,j};
				break;
			}
		}
	}
	sort(b+1,b+cnt+1,cmp);
	for (int i=1;i<=n;i++) {
		if (b[i].x>lt) {
			ans++;
			lt=b[i].y;
		}
	}
	printf("%d\n",ans);
	return 0;
}