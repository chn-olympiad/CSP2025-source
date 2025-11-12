#include<bits/stdc++.h>
using namespace std;
int a[505],b[505];
int s[105][105];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,R,seat,t=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	R=a[1];
	sort(b+1,b+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(R==b[i]){
			seat=i;
			break;
		}
	for(int i=1;i<=m;i++){
		if(i%2==1)for(int j=1;j<=n;j++)s[j][i]=t,t++;
		else for(int j=n;j>=1;j--)s[j][i]=t,t++;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(s[i][j]==seat){
				cout<<j<<' '<<i;
				break;
			}
	return 0;
}
