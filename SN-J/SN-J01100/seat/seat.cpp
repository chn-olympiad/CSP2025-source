#include<bits/stdc++.h>
using namespace std;
int n,m,x,cnt,sum,a;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>x;
	for(int i=1; i<n*m; i++) {
		cin>>a;
		if(a>x)cnt++;
	}
	if(cnt%n==0)sum=cnt/n,cnt=n;
	else sum=cnt/n,cnt%=n;
	cout<<sum+1<<" ";
	if(sum%2==1){
		cout<<cnt;
	}else{
		cout<<n-cnt+1;
	}
	return 0;
}
