#include<bits/stdc++.h>
using namespace std;
int n,m;
int num[1005];
int cnt=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);/**/
	cin>>n>>m;
	cin>>num[1];
	for(int i=2;i<=n*m;i++){
		cin>>num[i];
		if(num[i]>num[1])cnt++;
	}
	cout<<(cnt-1)/n+1<<" ";
	if(((cnt-1)/n+1)%2==1)cout<<(cnt-1)%n+1;
	else cout<<n-((cnt-1)%n);
	return 0;
}
