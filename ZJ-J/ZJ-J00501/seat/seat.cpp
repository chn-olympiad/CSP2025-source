#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e3+7;
int n,m;
struct hd{
	int ij;int sc;
}a[N];
bool cmp(hd x,hd y){
	return x.sc>y.sc;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		a[i].ij=i;
		cin>>a[i].sc;
	}sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].ij==1){
			cout<<(i-1)/m+1<<" ";
			if(((i-1)/m+1)%2==0)cout<<m-(i-1)%m;
			else cout<<(i-1)%m+1;
			return 0;
		}
	}
	return 0;
}
