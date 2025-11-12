#include<bits/stdc++.h>
using namespace std;
int n,m,s[110],k;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>s[i];
		if(s[i]>=s[1])++k;
	}
	cout<<(k+n-1)/n<<' ';
	if(((k+n-1)/n)&1){
		cout<<(k-1)%n+1;
	}
	else cout<<n-((k-1)%n+1)+1;
	return 0;
}
