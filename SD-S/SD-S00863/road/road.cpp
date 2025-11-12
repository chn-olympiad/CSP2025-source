#include<bits/stdc++.h>
#define ll long long
using namespace std;
//第二题，跑dijs 
ll tu[10010][10010];
long long sum=0,ans=1e9,no=1; 
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll n,m,k;//n个城m条路k 个城市
	ll jilu;
	ll mindist[10090],wen[10090];
//	memset(mindist,0x3f,sizeof(mindist));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		
		int a,b,c;
		cin>>a>>b>>c;
		if(!tu[a][b]){
			tu[a][b]=c;
			tu[b][a]=c;
		}
		tu[a][b]=min(tu[a][b],c);
		tu[b][a]=tu[a][b];
		
	} 
	for(int j=1;j<=k;j++)
	for(int i=0;i<=n;i++){
		ll a;
		cin>>a;
		tu[n+j][i]=a;
		tu[i][n+j]=a;
		if(i!=0&&a==0){
			no=0;
		}
	//	ans=min(ans,tu[n+j][0]);
	}
	
	for(int i=1;i<=n;i++){
	
		jilu=0;
		tu[i][0]=1e9;
		for(int j=i+1;j<=n;j++){
			if(!wen[j]&&tu[i][jilu]>tu[i][j]&&tu[i][j]){
			jilu=j;
		//	cout<<jilu<<" ";
			}
			
		}
		if(jilu==0) continue;
	//	wen[jilu]=1;
		sum+=tu[i][jilu];
	}
	if(no){
		for(int j=1;j<=k;j++){
			ans=min(tu[n+j][0],ans);
		}
		cout<<min(sum,ans);
		return 0;
	}
//	cout<<sum<<" ";
	memset(wen,0,sizeof(wen));
	for(int i=1;i<=k;i++){
		ans+=tu[n+i][0];
		//cout<<ans<<" ";
		wen[n+i]=1;
		//cout<<"?";
		for(int j=1;j<=n+i;j++){
			jilu=0;
		tu[n+i][0]=1e9;
			for(int q=1;q<=n+i;q++){
				if(!wen[q]&&tu[j][jilu]>tu[j][q]&&tu[j][q])
				jilu=q;
			}
			if(!jilu) continue;
			wen[jilu]=1;
			ans+=tu[j][jilu];
			
		}
		sum=min(sum,ans);
		ans=0;
		memset(wen,0,sizeof(wen));
		for(int j=1;j<=i;j++) wen[j]=1;
	}
	cout<<sum;
	return 0;
}
