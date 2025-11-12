#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,cnt,x,a[1001],b[101][101];
bool cmp(int h,int t){
	return h>t;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
		cin>>a[i];
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(i=1;i<=m;i++){
		if(i%2)
			for(j=1;j<=n;j++)
				b[j][i]=a[++cnt];
		else
			for(j=n;j>=1;j--)
				b[j][i]=a[++cnt];
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(b[i][j]==x){
				cout<<j<<" "<<i;
				break;
			}
	return 0;
}
//#Shang4Shan3Ruo6Shui4
