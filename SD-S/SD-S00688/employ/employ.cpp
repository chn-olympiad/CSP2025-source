#include <iostream>
#include <algorithm>
#define SUBMITMODE 1
#define DEBU__G_ 0
#define DEBUG DEBU__G_&&!SUBMITMODE
#define MOD 998244353
using namespace std;
const int kxy=503;
int n,m,c[kxy];
bool s[kxy],specA=1;
int main() {
	if(SUBMITMODE) {
		freopen("employ.in","r",stdin);
		freopen("employ.out","w",stdout);
	}
	//ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i) {
		char ipt;
		cin>>ipt;
		if(ipt=='0') {
			specA=0;
		}
		s[i]=((ipt=='1')?1:0);
	}
	for(int i=1;i<=n;++i) {
		cin>>c[i];
	}
	/*if(specA) {
		for(int i=1;i<=n;++i) {
			if(c[i]<i) {
				int minsupported=MOD;
				for(int j=i+1;j<=n;++j) {
					if(c[j]>=i && minsuppoered>j) {
						minsupported=j;
					}
				}
				if(minsupported!=MOD) {
					swap(c[j],c[minsupported]);
				} else {
					break;
				}
			}
		}
	}*/
	
	sort(c+1,c+1+n);
	int slvs=0;
	while(1) {
		bool res=next_permutation(c+1,c+1+n);
		if(!res) {
			break;
		}
		int upgradable=0,cntfailed=0;
		for(int i=1;i<=n;++i) {
			if(cntfailed<c[i]) {
				++upgradable;
			} else {
				++cntfailed;
			}
		}
		if(upgradable>=m) {
			++slvs;
		}
	}
	cout<<slvs;
	return 0;
}
