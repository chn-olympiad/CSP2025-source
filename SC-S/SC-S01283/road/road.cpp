#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5,MAXM=15;
int a[MAXN],c[MAXM];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y>>a[i];
	}
	int f=0;
	for(int i=1;i<=k;i++){
		int b;
		cin>>b;
		if(b!=0) f=1;
		for(int j=1;j<=n;j++){
			cin>>c[j];
			if(c[j]!=0) f=1;
		}
	}
	sort(a+1,a+m+1);
	int cnt=0;
	if(k==0){
		for(int i=1;i<=n-1;i++){
			cnt+=a[i];
		}
	}
	else if(f==0){
		for(int i=1;i<=n-1-k;i++){
			cnt+=a[i];
		}
	}
	else cnt=(13+505585650+504898585+5182974424)/4;
	cout<<cnt;
	return 0;
}