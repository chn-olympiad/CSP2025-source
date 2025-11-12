#include<bits/stdc++.h>
using namespace std;
int n,m,a,x,c=1,b1,b2;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(!(i==1&&j==1)){
				cin>>x;
				if(x>a)c++;
			}
	b2=c%n,b1=(c-b2)/n;
	if(b2==0)
		if(b1%2==0)cout<<b1<<" "<<1;
		else cout<<b1<<" "<<n;
	else
		if(b1%2==0)cout<<b1+1<<" "<<b2;
		else cout<<b1+1<<" "<<n-b2+1;
}
