#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int t=a[1],j=1;
	sort(a+1,a+n*m+1,greater<int>());
	int p=find(a+1,a+n*m+1,t)-a;
	while(p>n) p-=n,j++;
	cout<<j<<' '<<(j&1?p:n-p+1);
	return 0;
}
