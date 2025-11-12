#include<iostream>
using namespace std;
const int MAX =100005;
int t,n;
int m[MAX][5],s[MAX][5],vis[MAX];
int mx,mi;
void dfs(int x,int y){
	if(x==1){
		return ;
	}
	for(int i=x-1;i>=1;i--){
		if(s[i][2]==y){
			for(int j=1;j<=3;j++){
				if(!(j!=y&&m[i][j]+m[x][y]>s[i][3]&&vis[j]<n/2)){
					dfs(i,j);
				}
				if(j!=y&&m[i][j]+m[x][y]>s[i][3]){
					vis[j]++;
					vis[y]--;
					s[i][1] = m[i][j];
					s[i][2] = j;
					s[i][3] = m[i][j]+m[x][y];
					mx = m[x][y];
					mi = y;
				}
			}
		}
	}
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){//层级
			mx = 0;mi =0;
			for(int j=1;j<=3;j++){//位次 
				cin>>m[i][j];
				if(m[i][j]>mx&&vis[j]<n/2){
					mx = m[i][j];
					mi = j;
				}else{
					dfs(i,j);
				}
			}
			if(mi){
				s[i][1] = mx;//最大
				s[i][2] = mi;//位次 
				s[i][3] = mx;
				vis[mi]++;//位次 
			}
		}
		int ans =0;
		for(int i=1;i<=n;i++){
			ans+=s[i][1];
		}
		cout<<'\n'<<ans<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
