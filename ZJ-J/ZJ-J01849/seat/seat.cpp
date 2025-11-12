#include<bits/stdc++.h>
using namespace std;
const int N=15;
int n,m,a[N*N],b,k;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) b=a[i];
	}
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(b==a[i]){
			k=i;
			break;
		}
	}
	int x=(k-1)/n+1,y=k-(x-1)*n;
	cout<<x<<' ';
	if(x%2==0) cout<<m-y+1;
	else cout<<y;
	return 0;
} 
