#include <bits/stdc++.h>
using namespace std;

//fast read?
const int B=1<<20;
char buf[B],*p1=buf,*p2=buf;
#define gc (p1==p2 && (p2=(p1=buf)+fread(buf,1,B,stdin)), *p1++)

void read(int &x) {
//	scanf("%d",&x);
	char ch=gc; x=0;
	while(!isdigit(ch)) ch=gc;
	while(isdigit(ch)) x=(x<<1)+(x<<3)+ch-48,ch=gc;
}

const int N=100005;
int T,n,a[N][3],cnt[3],ans,k;
int cs[N];
int oo[N],cc;

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	read(T);
	while(T--) {
		memset(cnt,0,sizeof cnt),ans=cc=0;
		read(n); k=n/2;
		for(int i=1;i<=n;i++) {
			int mx = 0;
			for(int j=0;j<3;j++) {
				read(a[i][j]);
				if(a[i][j]>a[i][mx]) mx=j;
			}
			cnt[mx]++,ans+=a[i][mx];
			cs[i]=mx;
		}
//		printf("cs:");for(int i=1;i<=n;i++)
//			printf("%d ",cs[i]); printf("\n");
//		printf("cnt: ");for(int i=0;i<3;i++)
//			printf("%d ",cnt[i]); printf("\n");
		if(cnt[0]<=k && cnt[1]<=k && cnt[2]<=k) {
			printf("%d\n",ans);
			continue;
		}
		int mx = 0;
		for(int i:{1,2}) if(cnt[i]>cnt[mx]) mx=i;
		int tmp = cnt[mx]-k;
		for(int i=1;i<=n;i++) {
			if(cs[i]==mx) {
				int o = INT_MIN;
				for(int j=0;j<3;j++)if(j!=mx){
					o = max(o,a[i][j]-a[i][mx]);
				}
				oo[cc++]=o;
			}
		}
		sort(oo,oo+cc,greater<int>{});
		for(int i=0;i<tmp;i++) ans+=oo[i];
		printf("%d\n",ans);
	}
	
	return 0;
}
/*
可以网络流过去 
moni feiyong liu!
*/
