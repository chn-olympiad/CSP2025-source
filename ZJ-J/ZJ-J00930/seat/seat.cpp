#include<bits/stdc++.h>
using namespace std;
int g[1000],n,m,ansx,ansy,tmp,mp[110][110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&g[i]);
	}
	tmp=g[1];
	int cnt=1;
	sort(g+1,g+1+n*m,greater<int>());
	for(int i=1;i<=m;i++){
		if(i&1){
			for(int j=1;j<=n;j++){
				mp[j][i]=g[cnt];
				cnt++;
			}
		}else{
			for(int j=n;j>=1;j--){
				mp[j][i]=g[cnt];
				cnt++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[i][j]==tmp){
				printf("%d %d\n",j,i);
				return 0;
			}
		}
	}
	return 0;
}
