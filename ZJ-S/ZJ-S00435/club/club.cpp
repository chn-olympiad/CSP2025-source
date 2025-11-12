#include <bits/stdc++.h>
using namespace std;
#define int long long
int T,n,i,j,ma,a[100001][4],f[1001],b[100001],tt1,tt2,s;
int ff[31][4][31][31][31],k,x,y,z,ff2[201][4][101][101];
bool cmp(int t,int w){
	return t>w;
}
struct no{
	int a[4],z;
}f2[100001][4];
void sc(int t,int x,int y,int z,int s){
//	if(s<=ma) return ;
	if(t>n){
		if(s>ma){
			ma=s;
//			if(ma==18){
//				for(int i=1;i<=n;i++) cout<<f[i]<<" ";
//				cout<<"\n";
//			}
		}
		return ;
	}
	if(x<n/2) f[t]=1,sc(t+1,x+1,y,z,s+a[t][1]);
	if(y<n/2) f[t]=2,sc(t+1,x,y+1,z,s+a[t][2]);
	if(z<n/2) f[t]=3,sc(t+1,x,y,z+1,s+a[t][3]);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){

		cin>>n;ma=-1e18;tt1=tt2=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=3;j++)
				cin>>a[i][j];	
			if(a[i][2]==0&&a[i][3]==0) tt1++;	
			if(a[i][3]==0) tt2++;	
		}
		if(tt1==n){
			s=0;
			for(i=1;i<=n;i++) b[i]=a[i][1];
			sort(b+1,b+n+1,cmp);
			for(i=1;i<=n/2;i++) s+=b[i];
			cout<<s<<"\n";
			continue;
		}
		if(tt2==n&&n<=200){
			for(i=1;i<=n;++i)
				for(x=0;x<=n/2;++x)
					for(y=0;y<=n/2;++y)
						ff2[i][1][x][y]=		
						ff2[i][2][x][y]=0;	
			for(i=1;i<=n;++i)
				for(k=1;k<=3;++k) 
					for(x=0;x<=min(i,n/2);++x)
						for(y=0;y<=min(i,n/2);++y){
							if(x+1<=n/2) ff2[i][1][x+1][y]=max(ff2[i][1][x+1][y],ff2[i-1][k][x][y]+a[i][1]);
							if(y+1<=n/2) ff2[i][2][x][y+1]=max(ff2[i][2][x][y+1],ff2[i-1][k][x][y]+a[i][2]);
						}	
			for(i=0;i<=n/2;++i)
				for(j=0;j<=n/2;++j)
					ma=max(ma,max(ff2[n][1][i][j],ff2[n][2][i][j]));
			cout<<ma<<"\n";	
			continue;		
		}
//		sc(1,0,0,0,0);
//		cout<<ma<<"\n";
		
		if(n>30){
			for(i=1;i<=n;i++)
				for(j=1;j<=3;j++)
					f2[i][j].z=f2[i][j].a[1]=f2[i][j].a[2]=f2[i][j].a[3]=0;
			for(i=1;i<=n;i++)
				for(j=1;j<=3;j++)
					for(k=1;k<=3;k++)
						if(f2[i-1][k].z+a[i][j]>f2[i][j].z&&f2[i-1][k].a[j]<n/2){
							f2[i][j].z=f2[i-1][k].z+a[i][j];
							f2[i][j].a[1]=f2[i-1][k].a[1];
							f2[i][j].a[2]=f2[i-1][k].a[2];
							f2[i][j].a[3]=f2[i-1][k].a[3];
							f2[i][j].a[j]++; 
						}
			cout<<max(f2[n][1].z,max(f2[n][2].z,f2[n][3].z))<<"\n";
			continue;
		}
		for(i=1;i<=n;i++)
			for(x=0;x<=n/2;x++)
				for(y=0;y<=n/2;y++)
					for(z=0;z<=n/2;z++)
						ff[i][1][x][y][z]=		
						ff[i][2][x][y][z]=		
						ff[i][3][x][y][z]=0;	
		for(i=1;i<=n;i++)
			for(k=1;k<=3;k++) 
				for(x=0;x<=min(i,n/2);x++)
					for(y=0;y<=min(i,n/2);y++)
						for(z=0;z<=min(i,n/2);z++){
							if(x+1<=n/2) ff[i][1][x+1][y][z]=max(ff[i][1][x+1][y][z],ff[i-1][k][x][y][z]+a[i][1]);
							if(y+1<=n/2) ff[i][2][x][y+1][z]=max(ff[i][2][x][y+1][z],ff[i-1][k][x][y][z]+a[i][2]);
							if(z+1<=n/2) ff[i][3][x][y][z+1]=max(ff[i][3][x][y][z+1],ff[i-1][k][x][y][z]+a[i][3]);
						}	
		for(i=0;i<=n/2;i++)
			for(j=0;j<=n/2;j++)
				for(k=0;k<=n/2;k++)
					ma=max(ma,max(ff[n][1][i][j][k],max(ff[n][2][i][j][k],ff[n][3][i][j][k])));
		cout<<ma<<"\n";
	}
	return 0;
}
