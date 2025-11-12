#include<bits/stdc++.h>
using namespace std;
int t,n,d[3][100005],m,z,i;
bool cmp(int x,int y){
	return x>y;
}
void dfs(int n1,int m1,int k1,int k2,int k3,int z){
	z+=d[m1][n1];
	if(n1==n){
		m=max(m,z);
		return;
	}
	if(k1<n/2) dfs(n1+1,0,k1+1,k2,k3,z);
	if(k2<n/2) dfs(n1+1,1,k1,k2+1,k3,z);
	if(k3<n/2) dfs(n1+1,2,k1,k2,k3+1,z);
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i1=0;i1<t;i1++){
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>d[0][i]>>d[1][i]>>d[2][i];
		}
		dfs(1,0,1,0,0,d[0][i]);
		dfs(1,1,0,1,0,d[1][i]);
		dfs(1,2,0,0,1,d[2][i]);
		cout<<m<<endl;
		m=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				d[j][i]=0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}