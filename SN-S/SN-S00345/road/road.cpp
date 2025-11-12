#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,k,ansu=0;
int rd[1000005][4];
int zs[1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i)zs[i]=1e9+7;
	for(int i=1;i<=m;++i){
		cin>>rd[i][1]>>rd[i][2]>>zs[i];
//		ansu+=rd[i][3];
//		if(kt[rd[i][1]][rd[i][2]]==-1){
//			sft[rd[i][1]][++zs[rd[i][1]]]=rd[i][2];
//			sft[rd[i][2]][++zs[rd[i][2]]]=rd[i][1];
//			kt[rd[i][1]][rd[i][2]]=rd[i][3];
//			kt[rd[i][2]][rd[i][1]]=rd[i][3];
//			for(int ii=1;ii<=zs[rd[i][1]];++ii){
//				sft[rd[i][2]][++zs[rd[i][2]]]=sft[rd[i][1]][ii];
//				kt[rd[i][2]][sft[rd[i][1]][ii]]=min(kt[rd[i][2]][sft[rd[i][1]][ii]],rd[i][3]+kt[rd[i][1]][sft[rd[i][1]][ii]]);
//			}
//			for(int ii=1;ii<=zs[rd[i][2]];++ii){
//				sft[rd[i][1]][++zs[rd[i][1]]]=sft[rd[i][2]][ii];
//				kt[rd[i][1]][sft[rd[i][2]][ii]]=min(kt[rd[i][1]][sft[rd[i][2]][ii]],rd[i][3]+kt[rd[i][2]][sft[rd[i][2]][ii]]);
//			}
//		}
//		else{
//			if(kt[rd[i][1]][rd[i][2]]<rd[i][3]){
//				ansu-=rd[i][3];
//			}
//			else if(kt[rd[i][1]][rd[i][2]]>rd[i][3]){
//				ansu-=kt[rd[i][1]][rd[i][2]];
//				ansu+=rd[i][3];
//			}
//		}		
	}
//	cout<<ansu;
	sort(zs+1,zs+m+1);
	for(int i=1;i<n;++i){
		ansu+=zs[i];
	}
	cout<<ansu;
	return 0;
}

