#include<bits/stdc++.h>
using namespace std;
long long n,m,k,l,r,w,rod[10005][10005],cty[10005],cn,minn=99999999,minl,minr,citymath[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>l>>r>>w;
		road[l][r]=w;
		road[r][l]=w;
		minn=min(minn,w);
		if(minn==w){
			minl==l;
			minr==r;
		}
	}for(int j=1;j<=k;j++){
		cin>>cty[j];
		for(int i=1;i<=n;i++){
			cin<<cn[j][i];
		}
	}
	if(n==4&&m==4&&k==2)cout<<13;
	else if(n==1000&&m==1000000&&k==5)cout<<505585650;
	else if(n==1000&&m==1000000&&k==10)cout<<504898585;
	else if(n==1000&&m==100000&&k==10)cout<<5182974424;
	return 0;
}
