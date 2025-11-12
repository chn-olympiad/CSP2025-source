#include <bits/stdc++.h>
using namespace std;
const int NB=120;
int n,m,a[NB],
	dx[NB],dy[NB];
bool cmp(int sheng,int ge)
{
	return sheng>ge;
}
int main(void)
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int tjx=a[1],pos=0;
	sort(a+1,a+1+n*m,cmp);
	for(int i=0;i<m;i++) {
		for(int j=1;j<=n;j++) {
			dx[i*n+j]=i+1;
			if(i%2==0) dy[i*n+j]=j;
			else dy[i*n+j]=n+1-j;
		}
	}
	for(int i=1;i<=n*m;i++) {
		if(a[i]==tjx) {
			pos=i;
			break;
		}
	}
	cout<<dx[pos]<<' '<<dy[pos];
	return 0;
}
