#include<bits/stdc++.h>
using namespace std;
int n,m,rgrade,tot,a[105],cnt,mp[15][15];
bool cmp(int x,int y){return x>y;}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	tot=n*m;
	for(int i=1;i<=tot;i++)
		cin>>a[i];
	rgrade=a[1];
	sort(a+1,a+tot+1,cmp);
	int x=0,y=1,d=1;
	while(cnt<tot){
		if(x+d>m||x+d<1)y++,d=-d;
		else x+=d;
		mp[x][y]=a[++cnt];
		if(mp[x][y]==rgrade){
			cout<<y<<" "<<x<<'\n';
			break;
		}
	}
	return 0;
}