#include<bits/stdc++.h>
using namespace std;
#define int long long
int k,i,R,a[1010],y,n,m;
bool cmp(int q,int h){
	return q>h;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
		cin>>a[i];
	R=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(i=1;i<=n*m;i++)
		if(a[i]==R){
			k=i;
			break;
		}
	y=(k-1)/n+1;
	cout<<y<<" ";
	if(y%2==1){
		cout<<k-(y-1)*n;
	}
	else{
		cout<<(n-(k-(y-1)*n)+1);
	}
}