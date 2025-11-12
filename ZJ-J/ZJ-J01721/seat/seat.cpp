#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e3+10;
int n,m,a[N],cnt;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) cnt=a[i];
	} 
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(cnt==a[i]){
			if(((i-1)/n)%2==0) {
				cout<<(i-1)/n+1<<" "<<(i-1)%n+1<<"\n";
			}else{
				cout<<(i-1)/n+1<<" "<<n-(i-1)%n<<"\n";
			}
		}
	}
	return 0;
}