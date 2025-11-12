#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
int n,m,k=0;
int e,a;
int x,y; 
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=2; i<=n*m; i++){
		cin>>e;
		if(e>a) k++;
	}
	int q=k/(n*2);
	int w=k%(n*2)+1;
	if(w>n) x=q*2+2,y=2*n-w+1;
	else x=q*2+1,y=w;
	cout<<x<<" "<<y;
	return 0;
}

