#include<bits/stdc++.h>
using namespace std;
int t,n,a1[100005],a2[100005],a3[100005],f[100005];
int dp(int i,int x,int y,int z){
	if(i==n || x==n/2 || y==n/2 || z==n/2){
		return f[i];
	}
	if(f[i]){
		return f[i];
	}
	int nn=0;
	if(x<(n/2)){
		int n1=dp(i+1,x+1,y,z)+a1[i];
		nn=max(nn,n1);
	}
	if(y<(n/2)){
		int n2=dp(i+1,x,y+1,z)+a2[i];
		nn=max(nn,n2);
	}
	if(z<(n/2)){
		int n3=dp(i+1,x,y,z+1)+a3[i];
		nn=max(nn,n3);
	}
	f[i]=nn;
	return f[i];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;++i){
		cin>>n;
		memset(f,0,sizeof(f));
		for(int j=1;j<=n;++j){
			cin>>a1[j]>>a2[j]>>a3[j];
		}
		cout<<dp(1,0,0,0)<<endl;
	}

	fclose(stdin);
	fclose(stdout);
	
	return 0;
}