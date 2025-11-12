#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int a[N],b[N],c[N],aa[N],bb[N],cc[N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n,na=0,nb=0,nc=0,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i]){
				ans+=a[i];
				na++;
				if(b[i]>=c[i]){
					aa[na]=a[i]-b[i];
				}
				else{
					aa[na]=a[i]-c[i];
				}
			}
			else if(b[i]>=a[i]&&b[i]>=c[i]){
				ans+=b[i];
				nb++;
				if(a[i]>=c[i]){
					bb[nb]=b[i]-a[i];
				}
				else{
					bb[nb]=b[i]-c[i];
				}
			}
			else{
				ans+=c[i];
				nc++;
				if(a[i]>=b[i]){
					cc[nc]=c[i]-a[i];
				}
				else{
					cc[nc]=c[i]-b[i];
				}
			}
	//		cout<<T<<" "<<na<<" "<<nb<<" "<<nc<<"&&\n";
		}
		if(na>n/2){
			sort(aa+1,aa+na+1);
			for(int i=1;i<=na-n/2;i++){
				ans-=aa[i];
			}
		}
		else if(nb>n/2){
			sort(bb+1,bb+nb+1);
			for(int i=1;i<=nb-n/2;i++){
				ans-=bb[i];
			}
		}
		else if(nc>n/2){
			sort(cc+1,cc+nc+1);
			for(int i=1;i<=nc-n/2;i++){
				ans-=cc[i];
			//	cout<<cc[i]<<"**\n";
			}
		}
		cout<<ans<<"\n";
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
