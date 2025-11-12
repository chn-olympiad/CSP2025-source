#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int n,m,x;
int a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	int t=0;
	for(int i=1;i<=m;i++){
		if(i&1){
			for(int j=1;j<=n;j++){
				++t;
				if(a[t]==x){
					cout<<i<<' '<<j<<'\n';
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				++t;
				if(a[t]==x){
					cout<<i<<' '<<j<<'\n';
					return 0;
				}
			}
		}
	}
	return 0;
}
