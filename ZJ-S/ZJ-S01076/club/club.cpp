#include<bits/stdc++.h> 
using namespace std;
int t,n,mp[10005][5],f[10005][5],h[10005],s[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		memset(f,0,sizeof(f));
		memset(h,0,sizeof(h));
		memset(s,0,sizeof(s));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&mp[i][j]);
			}
		}
		for(int i=1;i<=n;i++){
				int j;
				for(int p=1;p<=3;p++){
					if(mp[i][p]==max(mp[i][1],max(mp[i][2],mp[i][3]))){
						j=p;
						h[i]=j;
					}
				}
				for(int k=1;k<=n;k++){
					s[h[k]]++;
				}
				int m=mp[i][j];
				if(s[j]<=n/2){
					f[i][j]=m;
				}else{
					int mina=1e7,l;
					for(int k=1;k<i;k++){
						if(mina>=mp[k][j]&&h[k]==j){
							mina=mp[k][j];
							l=k;
						}
					}
					if(j==1){
						int maxa1=max(mp[l][2],mp[l][3]),maxa2=max(mp[i][1],max(mp[i][2],mp[i][3]));
						int mid=mp[i][1]+mp[i][2]+mp[i][3]-maxa2-min(mp[i][1],min(mp[i][2],mp[i][3]));
						int mo,mi;
						for(int p=1;p<=3;p++){
							if(mp[i][p]==mid){
								mi=p;
								break;
							}
						}
						for(int p=1;p<=3;p++){
							if(mp[i][p]==maxa1){
								mo=p;
								break;
							}
						}
						if(mina-maxa1<=maxa2-mid){
							h[i]=j;
							h[l]=mo;
							f[i-1][h[i-1]]=mp[i-1][h[i-1]]+f[i-2][h[i-2]];
							f[i][h[i]]=f[i-1][h[i-1]]+mp[i][h[i]];
						}else{
							h[i]=mi;
							f[i][h[i]]=f[i-1][h[i-1]]+mid;
						}
					}
					if(j==2){
						int maxa1=max(mp[l][1],mp[l][3]),maxa2=max(mp[i][1],max(mp[i][2],mp[i][3]));
						int mid=mp[i][1]+mp[i][2]+mp[i][3]-maxa2-min(mp[i][1],min(mp[i][2],mp[i][3]));
						int mi,mo;
						for(int p=1;p<=3;p++){
							if(mp[i][p]==mid){
								mi=p;
								break;
							}
						}
						for(int p=1;p<=3;p++){
							if(mp[l][p]==maxa1){
								mo=p;
								break;
							}
						}
						if(mina-maxa1<=maxa2-mid){
							h[i]=j;
							h[l]=mo;
							f[i-1][h[i-1]]=mp[i-1][h[i-1]]+f[i-2][h[i-2]];
							f[i][h[i]]=f[i-1][h[i-1]]+mp[i][h[i]];
						}else{
							h[i]=mi;
							f[i][h[i]]=f[i-1][h[i-1]]+mid;
						}
					}
					if(j==3){
						int maxa1=max(mp[l][1],mp[l][2]),maxa2=max(mp[i][1],max(mp[i][2],mp[i][3]));
						int mid=mp[i][1]+mp[i][2]+mp[i][3]-maxa2-min(mp[i][1],min(mp[i][2],mp[i][3]));
						int mi,mo;
						for(int p=1;p<=3;p++){
							if(mp[i][p]==mid){
								mi=p;
								break;
							}
						}
						for(int p=1;p<=3;p++){
							if(mp[i][p]==maxa1){
								mo=p;
								break;
							}
						}
						if(mina-maxa1<=maxa2-mid){
							h[i]=j;
							h[l]=mo;
							f[i-1][h[i-1]]=mp[i-1][h[i-1]]+f[i-2][h[i-2]];
							f[i][h[i]]=f[i-1][h[i-1]]+mp[i][h[i]];
						}else{
							h[i]=mi;
							f[i][h[i]]=f[i-1][h[i-1]]+mid;
						}
					}
				}
		}	
		int sum=0;
		for(int i=1;i<=n;i++){
			sum+=f[i][h[i]];
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
