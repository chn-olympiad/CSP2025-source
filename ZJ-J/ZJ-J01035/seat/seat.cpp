#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10010],r,t;
bool cmp(int i,int j){
	return i>j;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(r==a[i]){
			t=i;
			break;
		}
	if(t%n==0) cout<<t/n<<" "<<n;
	else{
		if((t/n+1)%2==0) cout<<t/n+1<<" "<<n-t%n+1;
		else cout<<t/n+1<<" "<<t%n;
	}
	return 0;
}