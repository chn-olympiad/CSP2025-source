#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int mp[N][N],n,m,k,x,y,z,cs[20],cct,cnt;
long long ans;
bool mark[N]={0};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(mp,0x3f3f3f3f,sizeof(mp));
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>x>>y>>z;
		mp[x][y]=z;
		mp[y][x]=z;
	}
	for(int i=1;i<=k;i++){
		cin>>cs[i];
		for(int j=1;j<=n;j++){
			cin>>x;
			mp[i+n][j]=x+cs[i];
			mp[j][i+n]=x+cs[i];
		}
	}
	cnt=1;
	mark[1]=1;
	while((cnt-cct)<n){
		y=0x3f3f3f3f;
		for(int j=1;j<=n+k;j++){
			if(mark[j]){
				for(int i=1;i<=n+k;i++){
					if((y>mp[j][i])&&(!mark[i])){
						z=i;
						y=mp[j][i];
					}
				}	
			}	
		}
		mark[z]=1;
		ans+=y;
		cnt++;
		if(z>n){
			cct++;
			for(int i=1;i<=n;i++){
				mp[z][i]-=cs[z-n];
				mp[i][z]-=cs[z-n];
			}
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
