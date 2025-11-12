#include<bits/stdc++.h>
using namespace std;
int n,m,x,num,a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	x=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--){
		if(a[i]==x){
			num=n*m-i+1;
			if(((num-1)/n+1)%2==1)cout<<(num-1)/n+1<<" "<<(num-1)%n+1;
			else cout<<(num-1)/n+1<<" "<<n-((num-1)%n+1)+1;
			return 0;
		}
	}
	return 0;
}
