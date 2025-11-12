#include<bits/stdc++.h>
using namespace std;
const int N=5*(1e5+5),K=22,D=1048600;
struct node {
	int st,ed;
	bool operator < (const node &zxy)const {
		return ed<zxy.ed;
	}
} b[N];
int n,k,a[N],cnt[D],ans,t;
bool f[K][N];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n; i++) {
		int x;
		scanf("%d",&x);
		a[i]=a[i-1]^x;
	}
	cnt[0]=1;
	for(int i=1; i<=n; i++) {
//		cout<<a[i]<<' ';
		cnt[a[i]]++;
	}
//	cout<<endl;
	for(int i=1; i<=n; i++) {
		cnt[a[i-1]]--;
//		cout<<cnt[2]<<'\n';
		if(cnt[k^a[i-1]]==0)continue;
		for(int j=i; j<=n; j++) {
			if((a[i-1]^a[j])==k) {
				t++;
				if(t>N) {
					return 0;
				}
				b[t]=node{i,j};
//				cout<<t<<':'<<i<<' '<<j<<'\n';
			}
		}
	}
	sort(b+1,b+t+1);
	int ed=0;
	for(int i=1; i<=t; i++) {
		if(b[i].st>ed) {
			ans++,ed=b[i].ed;
//			cout<<b[i].st<<' '<<b[i].ed<<'\n';
		}
	}
	printf("%d",ans);
	return 0;
}
