#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int a[N][5];
int t;
int n;
int kkk[5];
struct node{
	int bval;
	int cval;
} nnn[N];
bool cmp(node a,node b){
	return a.bval<b.bval;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		cin >>n;
		int ans=0;
		for(int i=0;i<=4;i++) kkk[i]=0;
		for(int i=1;i<=n;i++){
			int maxn=0;
			int maxi=0;
			for(int j=1;j<=3;j++){
				scanf("%lld",&a[i][j]);
				if(a[i][j]>maxn){
					maxn=a[i][j];
					maxi=j;
				}
			}
			ans+=maxn;
			nnn[i].cval=maxi;
			int cmaxn=0;
			for(int j=1;j<=3;j++){
				if(j!=maxi) cmaxn=max(cmaxn,a[i][j]);
			}
			nnn[i].bval=maxn-cmaxn;	
		}
		for(int i=1;i<=n;i++){
			kkk[nnn[i].cval]++;
		}
		int cc=0;
		int mpi=0;
		for(int i=1;i<=3;i++){
			if(kkk[i]>n/2) {
				cc=kkk[i]-n/2;
				mpi=i;
			}
		}
		sort(nnn+1,nnn+n+1,cmp);
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(cnt>=cc) break;
			else{
				if(nnn[i].cval==mpi) ans-=nnn[i].bval,cnt++;
			}
		}
		cout <<ans<<'\n';
	}
	return 0;
}
