#include<bits/stdc++.h>
using namespace std;
int n,m,k,sum;
int mapp[1005][1005],bjt[100005];
int cz[1005],croad[1005][1005];
//queue<int> s;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			mapp[i][j]=100000;
		}
	}
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		mapp[a][b]=c;
		mapp[b][a]=c;
		sum+=c;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) bjt[j]=0;
	}
	cout<<sum;
//	for(int i=m+1;i<=k+m;i++){
//		cin>>cz[i];
//		for(int j=1;j<=n;j++) cin>>croad[i][j],croad[j][i]=croad[i][j];
//	}
	
//	s.push(1);
//	bjt[1]=1;
//	while(!s.empty()){
//		int w=s.front();
//		for(int i=1;i<=n;i++){
//			if(i==w||bjt[i]==1) continue;
//			//if(mapp[w][i]!=2147483645){
//				for(int j=1;j<=n;j++){
//					if(j==i) continue;
//					mapp[w][i]=min(mapp[w][i],mapp[w][j]+mapp[j][i]);
//				}
//			s.push(i);
//			bjt[i]=1;
//			//}
//		}
//		s.pop();
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			if(mapp[i][j]!=100000){
//				cout<<i<<" "<<j<<" "<<mapp[i][j]<<'\n';
//			}
//		}
//	}
//	cout<<mapp[1][5];
	return 0;
}
//注意关注释