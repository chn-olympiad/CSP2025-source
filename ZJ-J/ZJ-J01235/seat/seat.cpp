#include<bits/stdc++.h>
using namespace std;
int n,m,N;
int a[105],b[105];
int x,y;
int sum;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;N=n*m;
	for(int i=1;i<=N;i++) cin>>a[i],b[i]=a[i];
	sort(b+1,b+N+1);
	for(int i=1;i<=N;i++)
		if(b[i]==a[1]){
			sum=N-i+1;
			break;
		}
	x=(sum+n-1)/n;y=sum-(x-1)*n;
	if(x%2==0) cout<<x<<' '<<n-y+1;
	else cout<<x<<' '<<y;
	return 0;
} 
