#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005],a1,a2;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	a1=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--)
		if(a[i]==a1){
			a2=n*m-i+1;
			break;
		}
	if(((a2-1)/n)&1) cout<<(a2-1)/n+1<<' '<<n-(a2-1)%n;
	else cout<<(a2-1)/n+1<<' '<<(a2-1)%n+1;
	return 0;
}
