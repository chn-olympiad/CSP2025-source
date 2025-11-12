#include<bits\stdc++.h>
using namespace std;
int n,m,q[110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>q[i];
	int r=q[1];
	sort(q+1,q+1+n*m,cmp);
	int idx;
	for(int i=1;i<=n*m;i++)
		if(q[i]==r)idx=i;
	int c;
	if(idx%n!=0)c=idx/n+1;
	else c=idx/n;
	cout<<c<<" ";
	if(c%2){
		if(idx%n==0)cout<<n;
		else cout<<idx%n;
	}else {
		if(idx%n==0)cout<<1;
		else cout<<n+1-idx%n;
	}
	return 0;
}
