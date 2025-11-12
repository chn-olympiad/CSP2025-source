#include<bits/stdc++.h>
#define int long long
using namespace std;
int b[101010],d[101010],ans=0,a[101010][3],tong[3],n,id[101010];
int T=0;
void solve()
{
	cin>>n,ans=0;
	for(int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2],d[i]=max({a[i][0],a[i][1],a[i][2]});
	for(int i=1;i<=n;i++) ans+=d[i],a[i][0]-=d[i],a[i][1]-=d[i],a[i][2]-=d[i];
	tong[0]=tong[1]=tong[2]=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<3;j++) if(a[i][j]==0) {tong[j]++,id[i]=j;break;}
	int nw=-1;
	for(int i=0;i<3;i++) if(tong[i]>n/2) nw=i;
	if(nw==-1) {cout<<ans<<'\n';return ;}
	for(int i=1;i<=n;i++) b[i]=-1e18;
	int tmp=0;
	for(int i=1;i<=n;i++)
	{
		if(id[i]!=nw) continue;
		tmp++;
		for(int j=0;j<3;j++)
		{
			if(j==nw) continue;
			b[tmp]=max(b[tmp],a[i][j]);
		}
	}
	sort(b+1,b+tong[nw]+1),reverse(b+1,b+tong[nw]+1);
	int cnt=0;
//	cout<<tong[nw]<<"\n";
	while(tong[nw]>n/2) tong[nw]--,ans+=b[++cnt];
	cout<<ans<<'\n';
	return ;
}
main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>T;
	while(T--) solve();
	return 0;
}
//I'm the bone of the code
//Steel is my body,and fire is my blood
//I have writed over a thousand codes
//Unavare to loss,nor avare to gain
//Withstood pain to write many codes ,waiting for one's arrival.
//I have no regrets.This is the only path
//My whole life was "Unlimited Code Works".
//CSP-S2025 RP++ 