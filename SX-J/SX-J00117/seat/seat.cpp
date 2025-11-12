#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=15*15;
int a[N],sec;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	sec=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==sec){
			cout<<ceil(double(i)/n)<<" ";
			if((int)(ceil(double(i)/n))&1){
				if(i%n==0) cout<<n;
				else cout<<i%n;
			}
			else{
				if(i%n==0) cout<<"1";
				else cout<<n-i%n+1;
			}
			break;
		}
	}
	return 0;
}