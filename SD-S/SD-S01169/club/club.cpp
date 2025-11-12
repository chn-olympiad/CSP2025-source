#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int c[3],a[N][3],ans,n,s[N],cnt,t;
int read() {
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x;
}
int main() {
    freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		for(int i=1;i<=n;i++) {
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			for(int j=0;j<3;j++) {
				if(a[i][j]>=a[i][(j+1)%3]&&a[i][j]>=a[i][(j+2)%3]) {
					c[j]++;
					ans+=a[i][j];
					break;
				}
			}
		}
		for(int i=0;i<3;i++) {
			if(c[i]>n/2) {
				for(int j=1;j<=n;j++) {
					if(a[j][i]>=a[j][(i+1)%3]&&a[j][i]>=a[j][(i+2)%3]) s[++cnt]=a[j][i]-max(a[j][(i+1)%3],a[j][(i+2)%3]);
				}
				sort(s+1,s+c[i]+1);
				for(int j=1;j<=c[i]-n/2;j++) ans-=s[j];
				break;
			}
		}
		printf("%d\n",ans);
		cnt=ans=c[0]=c[1]=c[2]=0;
	}
	return 0;
}

