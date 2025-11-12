#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int b[101][101];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[100010];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int cnt=a[1];
	sort(a+1,a+n*m+1,cmp);
	int f=0;
	int l=1;
	for(int i=1;i<=n*m;i++){
		if(f==0){
			b[1][l]=a[i];
			i++;
			int u=1;
			while(u+1<=n){
				b[++u][l]=a[i];
				i++;
			}
			l++;
			f=1;
		}
		if(f==1){
			b[n][l]=a[i];
			i++;
			int u=n;
			while(u-1>=1){
				b[--u][l]=a[i];
				i++;
			}
			l++;
			i--;
			f=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==cnt){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}
