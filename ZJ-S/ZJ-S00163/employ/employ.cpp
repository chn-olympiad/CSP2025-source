#include<bits/stdc++.h>
using namespace std;
const int N=510;
int n,m,c[N],a[N],ans;
string s;
namespace pts1 {
	void solve() {
		do {
			int now=0;
			for(int i=1; i<=n; ++i) {
				if(s[i-1]=='0')now++;
				else {
					if(c[a[i]]<=now)now++;
				}
			}
			if(n-now>=m)ans++;
		} while(next_permutation(a+1,a+n+1));
		printf("%d",ans);
	}
}
//namespace pts2 {
//	int nd[N],cc[N],ans,cnt[N];
//	void solve() {
//		for(int i=1; i<=n; ++i)cc[c[i]]++;
//		for(int i=0; i<(1<<n); ++i) {
//			int f=0,res=1;
//			for(int j=1; j<=n; ++j) {
//				if(i&(1<<(j-1))&&s[j-1]=='0') {
//					f=1;
//					break;
//				}
//			}
//			if(f)continue;
//			for(int j=1; j<=n+1; ++j)cnt[j]=cc[j],nd[j]=0;
//			for(int j=1; j<=n; ++j) {
//				if(!(i&(1<<j-1)))f++,nd[j]=f;
//				else nd[j]=f+1;
//			}
//			if(n-f<m)continue;
//			int now=n+1,op=0;
//			for(int j=n; j>=1; --j) {
//				if(!(i&(1<<j-1))&&s[j-1]=='0') {
//					op++;
//					continue;
//				}
//				if(!(i&(1<<j-1))) {
//					for(int w=1;w<=nd[j];++w){
//						
//					}
//				} else {
//					while(now>nd[j])cnt[now-1]+=cnt[now],now--;
//					res*=cnt[now];
//					cnt[now]--;
//				}
//			}
//			while(f)res*=f,f--;
//			ans+=res;
//		}
//		printf("%d",ans);
//	}
//}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1; i<=n; ++i)a[i]=i,scanf("%d",&c[i]);
	if(n<=10) {
		pts1::solve();
//	} else if(n<=18) {
//	pts2::solve();
	}

}
