#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[105][105];
int b[105]; 
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>b[i];
	int sum=b[1];
	sort(b+1,b+n*m+1,cmp);
	int cnt=0;
	for(int j=1;j<=m;j++){
		if(j%2==1)for(int i=1;i<=n;i++)a[i][j]=b[++cnt];
		else for(int i=n;i>=1;i--)a[i][j]=b[++cnt];
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(a[i][j]==sum){
		cout<<j<<" "<<i;
		return 0;
	}
	return 0;
}
