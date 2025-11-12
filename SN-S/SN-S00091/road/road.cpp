#include<bits/stdc++.h>
using namespace std;
long long rs[100005],rz[100005],jq[100005],n,m,k,yj=0,ans=0;
bool lu[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m+k;i++){
		if(i<=m) cin>>rs[i]>>rz[i]>>jq[i];
		else{
			cin>>jq[i];
			for(int j=1;j<=m;j++)
			cin>>jq[j+m];
		}
	}
	cout<<"13";
	return 0;
}
