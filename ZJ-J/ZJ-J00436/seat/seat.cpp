#include<bits/stdc++.h>
#define ll long long
using namespace std;
void fre(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
}
ll n,m,a[110],now,z;
ll mp[110][110],x,y;
int main(){
	fre();
	cin>>n>>m;
	x=1,y=1;
	for(int i=1;i<=n*m;i++){
		mp[x][y]=i;
		if(x<n&&mp[x+1][y]==0)x++;
		else if(x>1&&mp[x-1][y]==0)x--;
		else y++;
	}
	for(int i=1;i<=n*m;++i)
		cin>>a[i];
	now=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;++i)
		if(a[i]==now){
			z=i;
			break;
		}
	z=n*m-z+1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(mp[i][j]==z){
				cout<<j<<" "<<i<<endl;
				break;
			}
	return 0;
}