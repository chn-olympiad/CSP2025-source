#include<bits/stdc++.h>
using namespace std;
const int M=1e6+2;
int r[M][2],w[M];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,sum=0,maxn=-1;
	cin>>n>>m>>k;
	for(int i=1;i=m;i++){
	cin>>r[i][0]>>r[i][1]>>w[i];
	sum+=w[i];
	maxn=max(w[i],maxn);	
	}
	if(k==0){
		sum-=maxn;
		cout<<sum;
		return 0;
	}
}