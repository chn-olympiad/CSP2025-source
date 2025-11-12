#include<bits/stdc++.h>
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Dor(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
const int N=1e4;
int n,m,k,w[N*10+5];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	For(i,1,m){
		int u,v;
		cin>>u>>v>>w[i];
	}
	if(k==0){
		sort(w+1,w+m+1);
		int sum=0;
		For(i,1,n-1) sum+=w[i];
		cout<<sum;
	}
	return 0;
}
