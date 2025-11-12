#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int read()
{
	register int x=0,t=1;
	register char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') t=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*t;
}
int a[N][4],b[4],c[N],d1[N],d2[N];
void solve()
{
	priority_queue<int,vector<int>,greater<int>>q[4];
	int n=read();
	for(int i = 1;i<=n;i++){
		a[i][1]=read(),a[i][2]=read(),a[i][3]=read();
		b[1]=a[i][1],b[2]=a[i][2],b[3]=a[i][3];
		sort(b+1,b+1+3);
		for(int j = 1;j<=3;j++){
			if(a[i][j]==b[3]){
				d1[i]=j;
			}
		}
		for(int j = 1;j<=3;j++){
			if(j!=d1[i]){
				if(a[i][j]==b[2]){
					d2[i]=j;
				}
			}
		}
		c[i]=b[3]-b[2];
	//	cout << d1[i] << " " << d2[i] << '\n';
	}
	int ans=0;
	for(int i = 1;i<=n;i++){
		if(q[d1[i]].size()<n/2){
			q[d1[i]].push(c[i]);
			ans+=a[i][d1[i]];
		}
		else{
			if(q[d1[i]].top()<c[i]){
				ans-=q[d1[i]].top();
				q[d1[i]].pop();
				ans+=a[i][d1[i]];
				q[d1[i]].push(c[i]);
			}
			else{
				ans+=a[i][d2[i]];
			}
		}
	//	cout << ans << '\n';
	}
	cout << ans << '\n';
	return;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--) solve();
	return 0;
}
/*
容易发现的一点是，如果某个满了，那么其他的肯定再也不肯满了

先随便选，每个部门存一个优先队列，满了以后就踢掉一个

考虑要踢掉哪一个，也许某个虽然拉，但是第二个更拉 
*/
