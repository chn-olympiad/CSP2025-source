#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	b=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==b){
			cout<<(i+n-1)/n<<' ';
			if(((i+n-1)/n)%2==1) cout<<i-((i+n-1)/n-1)*n;
			else cout<<n-(i-((i+n-1)/n-1)*n)+1;
			
		}
	}
	return 0;
}
