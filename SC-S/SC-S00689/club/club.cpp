#include<bits/stdc++.h>
using namespace std;
int n,m,a[100][100];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>m;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=3;j++)cin>>a[i][j];
		}
		if(m==2){
			int jjj=0;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(i==j){continue;
					}
					jjj=max(jjj,a[1][i]+a[2][j]);
				}
			}
			cout<<jjj<<endl;
		}
		if(m==3){
			int jjj=0;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					for(int k=1;k<=3;k++){
						if(i==j || i==k || k==j)continue;
						jjj=max(jjj,a[1][i]+a[2][j]+a[3][k]);
					} 
				}
			}
			cout<<jjj<<endl;
		}
		if(m==4){
			int qq[100],ww[100],ee[100],dd[100],ell=1;
			int jjj=0;
			for(int i=1;i<=4;i++){
				for(int j=1;j<=4;j++){
					for(int k=1;k<=4;k++)
					{
						if(i==j || i==k || k==j)continue;
						qq[ell]=i;
						ww[ell]=j;
						ee[ell]=k;
						dd[ell++]=a[i][1]+a[j][2]+a[k][3];
					}
				}
			}
			int y=0;
			for(int i=1;i<ell;i++){
				for(int j=1;j<=4;j++){
					if(j==qq[i] || ww[i]==j || ee[i]==j)continue;
					for(int k=1;k<=3;k++){
						y=max(dd[i]+a[j][k],y);
						cout<<dd[i]<<" "<<a[j][k]<<" "<<y<<endl;
					}
				}
			}
			cout<<y<<endl;
		}
	}
	
    return 0;
    fclose(stdin);
    fclose(stdout);
}