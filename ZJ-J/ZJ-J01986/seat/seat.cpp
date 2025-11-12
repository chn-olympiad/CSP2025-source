#include<bits/stdc++.h>
using namespace std;
int a[2025];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[(i-1)*m+j];
	int r=a[1];
	sort(a+1,a+m*n+1,cmp);
	int k;
	for(k=1;k<=n*m;k++) if(r==a[k]) break;
	int c=(k-1)/n+1;
	if(c%2==0)
		cout<<c<<" "<<n-(k-1)%n<<endl;
	else
		cout<<c<<" "<<(k-1)%n+1<<endl;
	return 0;
}