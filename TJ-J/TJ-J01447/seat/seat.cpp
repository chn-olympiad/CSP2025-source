#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],t,b=1,c[105],j;
bool bo[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		bo[i]=true;
	}
	t=a[0];
	for(int i=0;i<n*m;i++){
		int maxx=0;
		for(j=0;j<m*n;j++){
			if(a[j]>maxx&&bo[j]==true){
				maxx=a[j];
			}
		}
		for(j=0;j<m*n;j++){
			if(a[j]==maxx){
				bo[j]=false;
				break;
			}
		}
		c[i]=maxx;
	}
	for(int i=0;i<m*n;i++,b++){
		if(t==c[i]) break;
	}
	if(b<=n){
		cout<<1<<" "<<b;
	}
	else if(b%n==0){
		cout<<b/n<<" "<<n;
	}
	else{
		int count=b/n+1;
		cout<<count<<" "<<b-(count-1)*n;
	}
	return 0;
}
