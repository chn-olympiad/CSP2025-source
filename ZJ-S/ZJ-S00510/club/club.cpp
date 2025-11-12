#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100005][6],T,n,maxa[100005],aa,bb,cc,ans,mina[100005];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		cin>>n;
		aa=0,bb=0,cc=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				aa++;
				maxa[i]=a[i][1];
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				bb++;
				maxa[i]=a[i][2];
			}
			else{
				cc++;
				maxa[i]=a[i][3];
			}
		}
//		cout<<aa<<' '<<bb<<' '<<cc<<endl;
		ans=0;
		for(int i=1;i<=n;i++) ans+=maxa[i];
//		cout<<ans<<endl;
		if(aa<=n/2&&bb<=n/2&&cc<=n/2)
			cout<<ans<<endl;
		else{
			int qian;
			if(aa>n/2){
				for(int i=1;i<=n;i++){
					if(a[i][1]-a[i][2]<0||a[i][1]-a[i][3]<0) mina[i]=-1;
					else mina[i]=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
				}
				qian=aa-n/2;
			}
			else if(bb>n/2){
				for(int i=1;i<=n;i++){
					if(a[i][2]-a[i][1]<0||a[i][2]-a[i][3]<0) mina[i]=-1;
					else mina[i]=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
				}
				qian=bb-n/2;
			}
			else{
				for(int i=1;i<=n;i++){
					if(a[i][3]-a[i][1]<0||a[i][3]-a[i][2]<0) mina[i]=-1;
					else mina[i]=min(a[i][3]-a[i][1],a[i][3]-a[i][2]);
				}
				qian=cc-n/2;
			}
			sort(mina+1,mina+1+n);
			for(int i=1;i<=qian;i++){
				if(mina[i]==-1) qian++;
				else ans-=mina[i];
			}
			cout<<ans<<endl;
		}
	}
}
