#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,ma,i,a[100010][10],b[10],f[100010][10],t,w;
void dfs(int x,int y,int z){
	if(b[y]>n/2)return ;
	if(x==n){ma=max(ma,z);return ;}
	for(int i=1;i<=3;i++){
		b[i]++;
		dfs(x+1,i,z+a[x+1][i]);
		b[i]--;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;ma=0;t=w=0;
		for(i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2])t=1;if(a[i][3])w=1;
		}
		if(t&&w){dfs(0,0,0);cout<<ma<<endl;}
		else if(t==0&&w==0){
			for(i=1;i<=n;i++)b[i]=a[i][1];
			sort(b+1,b+n+1);
			for(i=n;i>=n/2+1;i--)ma+=b[i];
			cout<<ma<<endl;
		}
	}
}
