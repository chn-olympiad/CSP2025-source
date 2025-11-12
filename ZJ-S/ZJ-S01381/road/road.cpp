#include<bits/stdc++.h>
using namespace std;
int n,m,k,destroy[10005][10005]={},a[11][10005]={},c[11]={},map1[10005][10005]={},map2[10005][10005]={},cz[11]={},nn[10005]={};
long long sum=0;

int main(){
	//ios::sync_with_stdio(false);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(destroy,-1,sizeof(destroy));
	for(int i=1;i<=m;i++){
		int o,p;
		cin>>o>>p;
		cin>>destroy[o][p];
		destroy[p][o]=destroy[o][p];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	
	for(int i=1;i<=n;i++){
		if(nn[i]==1) continue;
		int min1=0;
		int flag=0;
		for(int j=1;j<=n;j++){
			if(destroy[i][j]<=min1&&destroy[i][j]!=-1||min1==0&&destroy[i][j]!=-1){
				flag=j;
				min1=destroy[i][j];
			}
		}
		nn[flag]=1;
		map1[i][flag]=min1;
		map1[flag][i]=min1;
		sum+=min1;
	}//求出不新建城镇使城镇联通的费用最小值 
	int min1=100000001;
	for(int i=1;i<=k;i++){
		if(c[i]<min1) min1=c[i];
		
	}
	if(k==0) cout<<sum;
	else cout<<min1;
	
}
