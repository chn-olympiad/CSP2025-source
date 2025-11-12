#include<bits/stdc++.h>
using namespace std;
long long n,m,p,s,a[1005],tot;
bool cmp(long long x,long long y){
	return x>y;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n;i++){
		int j=(i%2?1:n),del=(i%2?1:-1),ed=(i%2?n+1:0);
		while(j!=ed){
			tot++;
			if(a[tot]==s){
				cout<<i<<" "<<j<<"\n";
				return ;
			}
			j=j+del;
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	while(t--){
		solve();
	}
	return 0;
}