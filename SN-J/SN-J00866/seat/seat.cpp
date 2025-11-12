#include<bits/stdc++.h>
using namespace std;
int a[110];
bool g(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int o=a[1];
	sort(a+1,a+n*m+1,g);
	for(int i=1;i<=n*m;i++){
		if(a[i]==o){
			int r;
			if(i%n==0){
				r=i/n;
			}
			else r=i/n+1;
			cout<<r<<" ";
			int u=i%n;
			if(u==0)u=n;
			if(r%2==0)cout<<n+1-u;
			else cout<<u;
			break;
		}
	}
	return 0;
}
/*2 2
99 100 97 98
2 2
98 99 100 97
3 3
94 95 96 97 98 99 100 93 92

*/
