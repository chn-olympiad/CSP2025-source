//SN-J01091 阮书凡 安康中学教育集团初中部
#include<bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[105];
	long long o;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			o=a[i];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	long long p[15][15];
	long long u=1;
	for(int i=1;i<=m;i++){
		if(i&1){
		for(int j=1;j<=n;j++,u++){
			p[j][i]=a[u];
			if(p[j][i]==o){
				cout<<i<<" "<<j;
			}
	}
		}
		else{
			for(int j=n;j>=1;j--,u++){
				p[j][i]=a[u];
			
		
		if(p[j][i]==o){
			cout<<i<<" "<<j;
		}}}
}
//cout<<'\n';for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<p[i][j]<<" ";}cout<<'\n';}
return 0;
}
