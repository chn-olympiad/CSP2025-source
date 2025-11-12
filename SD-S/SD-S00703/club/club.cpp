#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
const int N=1e5+5;
int t,n,a[N][4],b[4],c[N],ans,t1;
void A(int i){
	if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
		b[1]++,ans+=a[i][1],c[i]=1;
	else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
		b[2]++,ans+=a[i][2],c[i]=2;
	else if(a[i][3]>=a[i][2]&&a[i][3]>=a[i][1])
		b[3]++,ans+=a[i][3],c[i]=3;
}
int st[N],cnt=0;
void B(int i){
	if(c[i]!=t1)return;
	int t2=t1%3+1,t3=(t1+1)%3+1;
	st[++cnt]=a[i][t1]-max(a[i][t2],a[i][t3]);
}
void solve(){
	memset(b,0,sizeof b);
	memset(c,0,sizeof c);
	cin>>n;ans=0;cnt=0;t1=-1;
	for(int i=1;i<=n;A(i),i++)
		for(int j=1;j<=3;j++)
			cin>>a[i][j];
	if(b[1]>n/2)t1=1;
	if(b[2]>n/2)t1=2;
	if(b[3]>n/2)t1=3;
	if(t1==-1){cout<<ans<<'\n';return;}
	for(int i=1;i<=n;i++)B(i);
	sort(st+1,st+cnt+1);
//	cout<<b[1]<<' '<<b[2]<<' '<<b[3]<<'\n';
	for(int i=1;i<=b[t1]-n/2;i++)
		ans-=st[i];
	cout<<ans<<'\n';
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;while(t--)solve();
	return 0;
}
//yu shi zhen hao ke !!!

