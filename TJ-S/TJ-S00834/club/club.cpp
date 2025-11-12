#include<bits/stdc++.h>
using namespace std;
int t,mf[6],ms[6],mt[6],ans[10],n,fi[5],sc[5],th[5],fo[5];
int fa[5],si[5],se[5],ei[5],ni[5],te[5];
void solve1(){
	int ans[15];
	ans[1]=mf[1]+ms[2];
	ans[2]=mf[1]+mt[2];
	ans[3]=ms[1]+mf[2];
	ans[4]=ms[1]+mt[2];
	ans[5]=mt[1]+mf[2];
	ans[6]=mt[1]+ms[2];
	sort(ans+1,ans+7,greater<int>());
	cout<<ans[1]<<"\n";
}
void solve2(){
	int maxx=-1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int x=1;x<=n;x++){
				for(int y=1;y<=n;y++){
					if(i==j&&i==x&&i==y) continue;
					if(i==j&&j==y) continue;
					if(i==x&&x==y) continue;
					if(x==j&&j==y) continue;
					if(i==j&&j==y) continue;
					maxx=max(maxx,fi[i]+sc[j]+th[x]+fo[y]);
				}
			}
		}
	}	
	cout<<maxx<<"\n";
}
//void solve3(){
//	int maxx=-1;
//	for(int i=1;i<=3;i++){
//		for(int j=1;j<=3;j++){
//			for(int x=1;x<=3;x++){
//				for(int y=1;y<=3;y++){
//					for(int z=1;z<=3;z++){
//						for(int ii=1;ii<=3;ii++){
//							for(int jj=1;jj<=3;jj++){
//								for(int xx=1;xx<=3;xx++){
//									for(int yy=1;yy<=3;yy++){
//										for(int zz=1;zz<=n;zz++){
//											if(i==j&&i==x&&i==y&&i==z&&i==ii) continue;
//											if(i==jj&&i==x&&i==y&&i==z&&i==ii) continue;
//											if(i==j&&i==jj&&i==y&&i==z&&i==ii) continue;
//											if(i==j&&i==x&&i==jj&&i==z&&i==ii) continue;
//											if(i==j&&i==x&&i==y&&i==jj&&i==ii) continue;
//											if(i==j&&i==x&&i==y&&i==z&&i==jj) continue;
//											if(i==xx&&i==x&&i==y&&i==z&&i==ii) continue;
//											if(i==j&&i==xx&&i==y&&i==z&&i==ii) continue;
//											if(i==j&&i==x&&i==xx&&i==z&&i==ii) continue;
//											if(i==j&&i==x&&i==y&&i==xx&&i==ii) continue;
//											if(i==j&&i==x&&i==y&&i==z&&i==xx) continue;
//											if(i==yy&&i==x&&i==y&&i==z&&i==ii) continue;
//											if(i==j&&i==yy&&i==y&&i==z&&i==ii) continue;
//											if(i==j&&i==x&&i==yy&&i==z&&i==ii) continue;
//											if(i==j&&i==x&&i==y&&i==yy&&i==ii) continue;
//											if(i==j&&i==x&&i==y&&i==z&&i==yy) continue;
//											if(i==zz&&i==x&&i==y&&i==z&&i==ii) continue;
//											if(i==j&&i==zz&&i==y&&i==z&&i==ii) continue;
//											if(i==j&&i==x&&i==zz&&i==z&&i==ii) continue;
//											if(i==j&&i==x&&i==y&&i==zz&&i==ii) continue;
//											if(i==j&&i==x&&i==y&&i==z&&i==zz) continue;
//											if(i==j&&i==x&&i==y&&i==z&&i==ii&&i==jj) continue;
//											if(i==xx&&i==x&&i==y&&i==z&&i==ii&&i==jj) continue;
//											if(i==yy&&i==x&&i==y&&i==z&&i==ii&&i==jj) continue;
//											if(i==zz&&i==x&&i==y&&i==z&&i==ii&&i==jj) continue;
//											if(i==xx&&i==x&&i==y&&i==z&&i==ii&&i==jj) continue;
//											if(i==yy&&i==x&&i==y&&i==z&&i==ii&&i==jj) continue;
//											if(i==zz&&i==x&&i==y&&i==z&&i==ii&&i==jj) continue;
//											if(i==j&&i==xx&&i==y&&i==z&&i==ii&&i==jj) continue;
//											if(i==j&&i==yy&&i==y&&i==z&&i==ii&&i==jj) continue;
//											if(i==j&&i==zz&&i==y&&i==z&&i==ii&&i==jj) continue;
//											if(i==j&&i==x&&i==xx&&i==z&&i==ii&&i==jj) continue;
//											if(i==j&&i==x&&i==yy&&i==z&&i==ii&&i==jj) continue;
//											if(i==j&&i==x&&i==zz&&i==z&&i==ii&&i==jj) continue;
//											if(i==j&&i==x&&i==y&&i==xx&&i==ii&&i==jj) continue;
//											if(i==j&&i==x&&i==y&&i==yy&&i==ii&&i==jj) continue;
//											if(i==j&&i==x&&i==y&&i==zz&&i==ii&&i==jj) continue;
//											if(i==j&&i==x&&i==y&&i==z&&i==xx&&i==jj) continue;
//											if(i==j&&i==x&&i==y&&i==z&&i==yy&&i==jj) continue;
//											if(i==j&&i==x&&i==y&&i==z&&i==zz&&i==jj) continue;
//											if(i==j&&i==x&&i==y&&i==z&&i==ii&&i==xx) continue;
//											if(i==j&&i==x&&i==y&&i==z&&i==ii&&i==yy) continue;
//											if(i==j&&i==x&&i==y&&i==z&&i==ii&&i==zz) continue;
//											if(i==j&&i==x&&i==y&&i==z&&i==ii&&i==jj&&i==xx) continue;
//											if(i==yy&&i==x&&i==y&&i==z&&i==ii&&i==jj&&i==xx) continue;
//											if(i==zz&&i==x&&i==y&&i==z&&i==ii&&i==jj&&i==xx) continue;
//											if(i==j&&i==yy&&i==y&&i==z&&i==ii&&i==jj&&i==xx) continue;
//											if(i==j&&i==zz&&i==y&&i==z&&i==ii&&i==jj&&i==xx) continue;
//											if(i==j&&i==x&&i==yy&&i==z&&i==ii&&i==jj&&i==xx) continue;
//											if(i==j&&i==x&&i==zz&&i==z&&i==ii&&i==jj&&i==xx) continue;
//											if(i==j&&i==x&&i==y&&i==zz&&i==ii&&i==jj&&i==xx) continue;
//											if(i==j&&i==x&&i==y&&i==yy&&i==ii&&i==jj&&i==xx) continue;
//											if(i==j&&i==x&&i==y&&i==z&&i==yy&&i==jj&&i==xx) continue;
//											if(i==j&&i==x&&i==y&&i==z&&i==zz&&i==jj&&i==xx) continue;
//											if(i==j&&i==x&&i==y&&i==z&&i==ii&&i==yy&&i==xx) continue;
//											if(i==j&&i==x&&i==y&&i==z&&i==ii&&i==zz&&i==xx) continue;
//											if(i==j&&i==x&&i==y&&i==z&&i==ii&&i==jj&&i==yy) continue;
//											if(i==j&&i==x&&i==y&&i==z&&i==ii&&i==jj&&i==zz) continue;
//											if(i==j&&i==x&&i==y&&i==z&&i==ii&&i==jj&&i==xx&&i==yy) continue;
//											if(i==zz&&i==x&&i==y&&i==z&&i==ii&&i==jj&&i==xx&&i==yy) continue;
//											if(i==j&&i==zz&&i==y&&i==z&&i==ii&&i==jj&&i==xx&&i==yy) continue;
//											if(i==j&&i==x&&i==zz&&i==z&&i==ii&&i==jj&&i==xx&&i==yy) continue;
//											if(i==j&&i==x&&i==y&&i==zz&&i==ii&&i==jj&&i==xx&&i==yy) continue;
//											if(i==j&&i==x&&i==y&&i==z&&i==zz&&i==jj&&i==xx&&i==yy) continue;
//											if(i==j&&i==x&&i==y&&i==z&&i==ii&&i==zz&&i==xx&&i==yy) continue;
//											if(i==j&&i==x&&i==y&&i==z&&i==ii&&i==jj&&i==zz&&i==yy) continue;
//											if(i==j&&i==x&&i==y&&i==z&&i==ii&&i==jj&&i==xx&&i==zz) continue;
//											if(i==j&&i==x&&i==y&&i==z&&i==ii&&i==jj&&i==xx&&i==yy&&i==zz) continue;
//											maxx=max(maxx,fi[i]+sc[j]+th[x]+fo[y]+fa[z]+si[ii]+se[jj]+ei[xx]+ni[yy]+te[zz]);
//										}
//									}
//								}
//							}
//						}
//					}
//				}
//			}
//		}
//	}	
//	cout<<maxx<<"\n";
//}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		if(n==2){
			for(int i=1;i<=n;i++) cin>>mf[i]>>ms[i]>>mt[i];
			solve1();
		} 
		else if(n==4){
			for(int i=1;i<=3;i++) cin>>fi[i];
			for(int i=1;i<=3;i++) cin>>sc[i];
			for(int i=1;i<=3;i++) cin>>th[i];
			for(int i=1;i<=3;i++) cin>>fo[i];
			solve2();
		}  
//		else if(n==10){
//			for(int i=1;i<=3;i++) cin>>fi[i];
//			for(int i=1;i<=3;i++) cin>>sc[i];
//			for(int i=1;i<=3;i++) cin>>th[i];
//			for(int i=1;i<=3;i++) cin>>fo[i];
//			for(int i=1;i<=3;i++) cin>>fa[i];
//			for(int i=1;i<=3;i++) cin>>si[i];
//			for(int i=1;i<=3;i++) cin>>se[i];
//			for(int i=1;i<=3;i++) cin>>ei[i];
//			for(int i=1;i<=3;i++) cin>>ni[i];
//			for(int i=1;i<=3;i++) cin>>te[i];
//			solve3();
//		}
//	}
	return 0;
} 
