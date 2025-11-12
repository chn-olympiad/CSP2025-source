#include<bits/stdc++.h>
using namespace std;
int a[210];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int f=0;
	for(int i=1;i<=n*m;++i){
		cin>>a[i];
	}
	f=a[1];
	sort(a+1,a+n*m+1);
	int idx=lower_bound(a+1,a+n*m+1,f)-a;
	idx=n*m-idx+1;
	int n1=(idx-1)/n+1;
	if(n1%2==0){
		cout<<n1<<' '<<n-idx%n+1;
	}else{
		cout<<n1<<' '<<(idx-1)%n+1;
	}
	return 0;
}