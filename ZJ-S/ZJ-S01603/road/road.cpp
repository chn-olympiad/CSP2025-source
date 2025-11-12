#include<bits/stdc++.h>
using namespace std;
int a[10002][10002];
bool flag[10002];
int c[10002];
int n,m,k,u,v,w,t,ans,l;
void search(int k,int sum){
	if(sum>ans)return;
	if(l==m-1)ans=sum;
	for(int i=1;i<=m+k;i++)
		if(!flag[i]){
			flag[i]=1;
			if(i<=m){
				l++;search(i,sum+a[i][k]);l--;
			}else{
				search(i,sum+a[i][k]-c[i]);
			}
			flag[i]=0;
		}
}
int main(){
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		a[u][v]=a[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>t;
			a[m+i][j]=a[j][m+i]=c[i]+t;
		}
	}
	ans=1e+9;
	for(int i=1;i<=m;i++){
		search(i,0);
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);return 0;
}