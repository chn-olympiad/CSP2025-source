#include<bits/stdc++.h>

using namespace std;
int t,n,d[100005],ans,s[4];
struct str{
	int w,z;
};
str x[100005][4];
int weiyi(int m,int y){
	int minn=1e5,r;
	for(int i=1;i<m;i++){
		if(x[i][d[i]].w==x[m][y].w){
			if(x[i][d[i]].z-x[i][d[i]+1].z<minn){
				minn=x[i][d[i]].z-x[i][d[i]+1].z;
				r=i;
			}
		}
	}
	if(minn<x[m][y].z-x[m][y+1].z){
//		cout<<x[m][y].z<<"-"<<m<<"==>"<<x[r][d[r]].z<<"-"<<r<<endl;
		if(s[x[r][d[r]+1].w]==n/2) weiyi(r,d[r]+1);
		else{
			d[r]++;
			s[x[r][d[r]+1].w]++;
		}
		d[m]=y;
		return 1;
	}
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		for(int i=1;i<=3;i++) s[i]=0;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			d[i]=1;
			cin>>x[i][1].z>>x[i][2].z>>x[i][3].z;
			x[i][1].w=1;
			x[i][2].w=2;
			x[i][3].w=3;
			for(int j=1;j<3;j++){
				for(int l=j+1;l<=3;l++){
					if(x[i][j].z<x[i][l].z) swap(x[i][j],x[i][l]);
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(s[x[i][j].w]==n/2){
					if(weiyi(i,j)) break;
				}else{
					s[x[i][j].w]++;
					d[i]=j;
					break;
				}
			}
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=3;j++) cout<<x[i][j].z<<"-"<<x[i][j].w<<" ";
//			cout<<endl;
//		}
		for(int i=1;i<=n;i++){
//			cout<<x[i][d[i]].w<<" ";
			ans+=x[i][d[i]].z;
		}
//		cout<<endl;
		cout<<ans<<endl;
	}
	return 0;
}
