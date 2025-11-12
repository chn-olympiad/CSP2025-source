#include<bits/stdc++.h>
using namespace std;
int t,n,ren1,ren2,ren3,ans;
struct cy{
	int my1,my2,my3;
	int jy,cjy,jz;
}cys[100010];
bool cmp(cy a,cy b){
	return a.jz>b.jz;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0,ren1=0,ren2=0,ren3=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&cys[i].my1,&cys[i].my2,&cys[i].my3);
		}
		for(int i=1;i<=n;i++){
			if(cys[i].my1>cys[i].my2&&cys[i].my1>cys[i].my3){
				cys[i].jy=1;
				if(cys[i].my2>cys[i].my3){
					cys[i].cjy=2;
					cys[i].jz=cys[i].my1-cys[i].my2;
				}else{
					cys[i].cjy=3;
					cys[i].jz=cys[i].my1-cys[i].my3;
				}
			}else if(cys[i].my2>cys[i].my1&&cys[i].my2>cys[i].my3){
				cys[i].jy=2;
				if(cys[i].my1>cys[i].my3){
					cys[i].cjy=1;
					cys[i].jz=cys[i].my2-cys[i].my1;
				}else{
					cys[i].cjy=3;
					cys[i].jz=cys[i].my2-cys[i].my3;
				}
			}else if(cys[i].my3>cys[i].my1&&cys[i].my3>cys[i].my2){
				cys[i].jy=3;
				if(cys[i].my1>cys[i].my2){
					cys[i].cjy=1;
					cys[i].jz=cys[i].my3-cys[i].my1;
				}else{
					cys[i].cjy=2;
					cys[i].jz=cys[i].my3-cys[i].my2;
				}
			}
		}
		sort(cys+1,cys+n+1,cmp);
//		for(int i=1;i<=n;i++){
//			cout << cys[i].jy << " " << cys[i].cjy << " " << cys[i].jz << endl << endl << endl;
//		}
		for(int i=1;i<=n;i++){
			if(cys[i].jy==1){
				if(ren1<(n/2)){
					ren1++;
					ans+=cys[i].my1;
				}else{
					if(cys[i].cjy==2){
						if(ren2<(n/2)){
							ren2++;
							ans+=cys[i].my2;
						}else{
							ren3++;
							ans+=cys[i].my3;
						}
					}else{
						if(ren3<(n/2)){
							ren3++;
							ans+=cys[i].my3;
						}else{
							ren2++;
							ans+=cys[i].my2;
						}
					}
				}
			}else if(cys[i].jy==2){
				if(ren2<(n/2)){
					ren2++;
					ans+=cys[i].my2;
				}else{
					if(cys[i].cjy==1){
						if(ren1<(n/2)){
							ren1++;
							ans+=cys[i].my1;
						}else{
							ren3++;
							ans+=cys[i].my3;
						}
					}else{
						if(ren3<(n/2)){
							ren3++;
							ans+=cys[i].my3;
						}else{
							ren1++;
							ans+=cys[i].my1;
						}
					}
				}
			}else{
				if(ren3<(n/2)){
					ren3++;
					ans+=cys[i].my3;
				}else{
					if(cys[i].cjy==1){
						if(ren1<(n/2)){
							ren1++;
							ans+=cys[i].my1;
						}else{
							ren2++;
							ans+=cys[i].my2;
						}
					}else{
						if(ren2<(n/2)){
							ren2++;
							ans+=cys[i].my2;
						}else{
							ren1++;
							ans+=cys[i].my1;
						}
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
