#include<bits/stdc++.h>
using namespace std;
int a[6000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,b=0,c=0,d=0;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	b=a[0];
	c=a[1];
	d=a[2];
	if((b+c+d)>max(b,max(c,d))*2)cout<<1;
	else cout<<0;
	return 0;
}
