#include<bits/stdc++.h>
using namespace std;
int a[110],t[20][20];
int u,m;
void cha(int &x,int &y){
	if(y%2)x++;
	else x--;
	if(x<1)x++,y++;
	if(x>u)x--,y++;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>u>>m;
	int k=u*m;
	for(int i=1;i<=k;i++)
		cin>>a[i];
	int f=a[1];
	sort(a+1,a+1+k);
	reverse(a+1,a+1+k);
	int x=1,y=1;
	for(int i=1;i<=k;i++,cha(x,y))
		t[x][y]=a[i];
	for(int i=1;i<=u;i++)
		for(int j=1;j<=m;j++)
			if(t[i][j]==f){cout<<j<<' '<<i;return 0;}
	return 0;
}
