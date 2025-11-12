#include <bits/stdc++.h>
#define ED cerr<<'\n';
#define TS cerr<<"I AK IOI\n";
#define cr(x) cerr<<x<<'\n';
#define cr2(x,y) cerr<<x<<" "<<y<<'\n';
#define cr3(x,y,z) cerr<<x<<" "<<y<<" "<<z<<'\n';
#define cr4(x,y,z,w) cerr<<x<<" "<<y<<" "<<z<<" "<<w<<'\n';
#define pr(a,l,r) for(int iii=l;iii<=r;++iii) cerr<<a[iii]<<" ";ED
#define pii pair<int,int>
#define fi first
#define se second 
#define ll long long
#define ull unsigned long long
using namespace std;
const int N=2e5+5,mod=1e9+7,INF=2e9;
int T,n,m,k;
int a[3][N],b[N];

int work() {
	int res=0;
	for(int i=1;i<=n;++i) {
		res+=a[0][i];
		b[i]=max(a[1][i],a[2][i])-a[0][i];
	}
	sort(b+1,b+1+n,greater<int>());
	for(int i=1;i<=n/2;++i) {
		res+=b[i];
	}
	return res;
}

void sol() {
	scanf("%d",&n);
	int Ans=0,ans=0,c[3]={0,0,0};
	for(int i=1;i<=n;++i) {
		scanf("%d%d%d",&a[0][i],&a[1][i],&a[2][i]);
		if(a[0][i]>=a[1][i]&&a[0][i]>=a[2][i]) {
			ans+=a[0][i],++c[0];
		}
		else if(a[1][i]>=a[0][i]&&a[1][i]>=a[2][i]) {
			ans+=a[1][i],++c[1];
		}
		else {
			ans+=a[2][i],++c[2];
		}
	}
	if(c[0]<n/2&&c[1]<n/2&&c[2]<n/2) {
		Ans=max(Ans,ans);
	}
	Ans=max(Ans,work()),swap(a[0],a[1]);
	Ans=max(Ans,work()),swap(a[0],a[2]);
	Ans=max(Ans,work());
	printf("%d\n",Ans);
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		sol();
	}
	return 0;
} 
