#include<bits/stdc++.h>
using namespace std;
int a[105],x,n,m,l;
inline bool cmp(int a,int b);
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>x;
	a[1]=x;
	for(int i=2;i<=n*m;++i)cin>>a[i];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;++i){
		if(a[i]==x){
			l=i;
			break;
		}
	}cout<<l/n+(!(!(l%n)))<<' ';
	if(!(l%n))cout<<n;
	else if(l/n%2)cout<<n+1-l%n;
	else cout<<l%n;
}
inline bool cmp(int a,int b){return a>b;}
