#include<bits/stdc++.h>
using namespace std;
int n,m,a,s,cnt,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=2;i<=n*m;i++){
		cin>>a;
		if(a>s) cnt++;
	}
	c=(cnt+n)/n;
	if(c%2==1) r=(cnt+1)%n;
	else r=n-cnt%n;
	if(r==0) r+=n;
	cout<<c<<" "<<r;
	//#Shang4Shan3Ruo6Shui4
	return 0;
}

