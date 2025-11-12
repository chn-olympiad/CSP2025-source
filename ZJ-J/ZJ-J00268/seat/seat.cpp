#include<bits/stdc++.h>
using namespace std;
int n,m,a,s,sum;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d",&s);
	int k=n*m;
	for(int i=2;i<=k;i++){
		scanf("%d",&a);
		if(a>s) sum++;
	}
	int c=sum/n+1,r=sum%n+1;
	if(c%2==0) r=n+1-r;
	cout<<c<<" "<<r<<endl;
	return 0;
}
