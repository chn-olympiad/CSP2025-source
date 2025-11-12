#include <bits/stdc++.h>
using namespace std;
int n,a[101],h=0,k=0,c,b,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
//	std::ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	h+=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==h){
			k+=i;
			break;
		}
	}
	c=k/n+1;
	if(k%n==0) c--;
	b=k%n;
	if(c%2==0) b=m+1-b;
	if(b==0) b+=n;
	if(b==n+1) b-=n;
	cout<<c<<" "<<b;
	return 0;
}


