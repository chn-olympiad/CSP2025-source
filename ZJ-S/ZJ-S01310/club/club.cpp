#include <bits/stdc++.h>
using namespace std;
const int NB=1e5+4;
int T,n,ans=0,mp2=0,mp3=0,bc[NB];
struct node
{
	int firtcl,sectcl,thitcl;
} a[NB];
struct node1
{
	int val1,val2,ncl;
} tjx[NB];
bool cmp(node1 sheng,node1 ge)
{
	if(sheng.val1==ge.val1) return sheng.val2>ge.val2;
	return sheng.val1>ge.val1;
}
void dfs(int lev,int tj1,int tj2,int tj3)
{
	if(lev==n+1) {
		int rres=0;
		for(int i=1;i<=n;i++) {
			if(bc[i]==1) rres+=a[i].firtcl;
			else if(bc[i]==2) rres+=a[i].sectcl;
			else rres+=a[i].thitcl;
		}
		ans=max(ans,rres);
		return ;
	}
	if(tj1<n/2) {
		bc[lev]=1;
		dfs(lev+1,tj1+1,tj2,tj3);
	}
	if(tj2<n/2) {
		bc[lev]=2;
		dfs(lev+1,tj1,tj2+1,tj3);
	}
	if(tj3<n/2) {
		bc[lev]=3;
		dfs(lev+1,tj1,tj2,tj3+1);
	}
	return ;
}
int main(void)
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--) {
		mp2=mp3=ans=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i].firtcl>>a[i].sectcl>>a[i].thitcl;
		if(n<=30) dfs(1,0,0,0);
		else {
			for(int i=1;i<=n;i++) {
				tjx[i].val1=a[i].sectcl-a[i].firtcl;
				tjx[i].val2=a[i].thitcl-a[i].firtcl;
				ans+=a[i].firtcl;
			}
			sort(tjx+1,tjx+n+1,cmp);
			for(int i=1;i<=n/2;i++) {
				if(i>n/2 && max(tjx[i].val1,tjx[i].val2)<0) break;
				if(mp3==n/2) {
					ans+=tjx[i].val1;
					mp2++;
				} else if(mp2==n/2) {
					ans+=tjx[i].val2;
					mp3++;
				} else {
					if(tjx[i].val1>=tjx[i].val2) {
						ans+=tjx[i].val1;
						mp2++;
					} else {
						ans+=tjx[i].val2;
						mp3++;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
