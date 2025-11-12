#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
const int N=15;
int n,m;
int a[N*N],b[N*N];
int rk[N*N];
int main(){
//	freopen()ni bei pian le
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n*m;++i)cin>>a[i],b[i]=a[i];
	sort(b+1,b+n*m+1);
	int rk=lower_bound(b+1,b+n*m+1,a[1])-b;
	rk=n*m-rk+1;
	for(int i=1;i<=m;++i){
		if(i&1)
			for(int j=1;j<=n;++j){
				--rk;
				if(!rk){
					cout<<i<<" "<<j<<endl;
					return 0;
				}
			}
		else
			for(int j=n;j>=1;--j){
				--rk;
				if(!rk){
					cout<<i<<" "<<j<<endl;
					return 0;
				}
			}
	}
	
	return 0;
}//mei bi yao di pai,dan hai shi xie le