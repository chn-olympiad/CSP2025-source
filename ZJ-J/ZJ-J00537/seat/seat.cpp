#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],c,r,yuan;
bool cmp(int x,int y){
	return x>y;
}
int js(int x){
	c=ceil(x*1.0/n);
	int z=x-(c-1)*n;
	if (c%2==1)
		r=z;
	else
		r=n-z+1;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int cnt=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			cin>>a[++cnt];
	yuan=a[1];
	sort(a+1,a+1+cnt,cmp);
	for (int i=1;i<=cnt;i++)
		if (a[i]==yuan){
			js(i);
			break;
		}
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
}
