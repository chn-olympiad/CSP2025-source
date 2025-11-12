#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int r,cnt=1;
	cin>>r;
	for(int i=2;i<=n*m;i++){
		int x;cin>>x;
		if(x>r)cnt++;
	}
	int lie=(cnt+n-1)/n;
	int hang=cnt-n*(lie-1);
	if(lie%2==0)hang=n-hang+1;
	cout<<lie<<' '<<hang;
	return 0;
}

