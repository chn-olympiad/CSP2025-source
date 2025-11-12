#include<bits/stdc++.h>
#include<cstdio>
#define ll long long
using namespace std;
ll n,m,q[110],a,n1,m1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>q[i];
	}
	int w=q[1];
	sort(q+1,q+n*m+1);
	for(int i=1;i<=n*m;++i){
		if(q[i]==w){
			if(i%2!=0){
				m1=i%n;
				n1=i/n+1;
				break;
			}
			else {
				m1=n-i%n;
				n1=i/n;
				break;
			}
		}
	}
	cout<<n1<<' '<<m1;
	return 0;
}  
