#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int n,m,a[15][15],b[105],y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	int x=b[1];
	sort(b+1,b+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(x==b[i])y=i;
	}
	int c=y/n,d=y%n;
	if(y%n==0)d=n;
	if(y%n!=0)c++;
	if(c%2==1)cout<<c<<" "<<d;
	else cout<<c<<" "<<(n-d+1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}