#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	for(int i=1;i<=n*m;i++)if(a[i]>=a[1])cnt++;
	int x=cnt/n,y=cnt%n;
	if(y==0){
		cout<<x<<" ";
		if(x%2==1){
			cout<<n;
		}
		else cout<<1;
	}
	else{
		cout<<x+1<<" ";
		if((x+1)%2==1){
			cout<<y;
		}
		else cout<<n-y+1;
	}
	return 0;
}
