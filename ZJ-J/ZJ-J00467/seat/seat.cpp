#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,cnt=1,ans;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=2;i<=n*m;i++){
		cin>>b;
		if(b>a)cnt++;
	}
	ans=(cnt+n-1)/n;
	if(ans%2==1)
	    cout<<ans<<' '<<cnt-(ans-1)*n;
	else cout<<ans<<' '<<n-(cnt-(ans-1)*n)+1;
	return 0;
}
