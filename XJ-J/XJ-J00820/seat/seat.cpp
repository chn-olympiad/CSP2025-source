#include<bits/stdc++.h>
using namespace std;
int n,m,a,s=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=1;i<n*m;++i){
		int aa;
		cin>>aa;
		if(aa>a){
			++s;
		}
	}
	int x=(s-1)/n+1,y=(s-1)%n+1;
	if(x&1)cout<<x<<' '<<y;
	else cout<<x<<' '<<n-(y-1);
	return 0;
}
