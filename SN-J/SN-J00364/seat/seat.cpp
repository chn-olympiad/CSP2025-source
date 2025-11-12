//SN-J00364 张柏洋 延安市新区培文学校
#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,xr,a,s,ans=1,c,r;
	cin>>n>>m>>xr;
	priority_queue<int,vector<int>,less<int>> pq;
	pq.push(xr);
	while(cin>>a) pq.push(a);
	for(int i=1;i<=n*m;i++){
		if(xr!=pq.top()){
			pq.pop();
			ans++;
		}
		else break;
	}
	c=(ans+m-1)/m;
	if(c%2!=0) r=(ans+n-1)%n+1;
	else r=n-ans%n+1;
	cout<<c<<' '<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
