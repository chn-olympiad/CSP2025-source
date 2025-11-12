#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
struct node{
	int x,y,z;
};
struct node2{
	int x,y;
};
bool cmp(node aa,node bb){
	return aa.x>bb.x;
}
bool cmp2(node2 aa,node2 bb){
	return aa.x>bb.x;
}
bool cmp3(int aa,int bb){
	return aa>bb;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int xl=0;
		int xy=0;
		int xr=0;
		int wei=-1;
		int yy=0;
		int n;
		cin>>n;
		int nn=n/2;
		node a[n+5];
		node b[n*3+10];
		node2 fa[n+5];
		node2 fb[n+5];
		node2 fc[n+5];
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				if(j==0){
					cin>>a[i].x;
					fa[i].x=a[i].x;
					fa[i].y=i;
					wei++;
					b[wei].x=a[i].x;
					b[wei].y=i;
					b[wei].z=0;
				}else if(j==1){
					cin>>a[i].y;
					fb[i].x=a[i].y;
					fb[i].y=i;
					wei++;
					b[wei].x=a[i].y;
					b[wei].y=i;
					b[wei].z=1;
				}else{
					cin>>a[i].z;
					fc[i].x=a[i].z;
					fc[i].y=i;
					wei++;
					b[wei].x=a[i].z;
					b[wei].y=i;
					b[wei].z=2;
				}
			}
		}
		sort(fa,fa+n,cmp2);
		sort(fb,fb+n,cmp2);
		sort(fc,fc+n,cmp2);
		int tong[3*n+10];
		int tong2[3*n+10];
		int tong3[3*n+10];
		for(int i=0;i<=n;i++){
			tong[i]=0;
			tong2[i]=0;
			tong3[i]=0;
		}
		sort(b,b+wei,cmp);
		int sum0=0;
		int sum1=0;
		int sum2=0;
		
		for(int i=0;i<n;i++){
			if(b[i].z==0){
				tong[b[i].y]++;
			}else if(b[i].z==1){
				tong2[b[i].y]++;
			}else{
				tong3[b[i].y]++;
			}
		}
		int ddd0=-1;
		int ddd1=-1;
		int ddd2=-1;
		int dd0[n+5];
		int dd1[n+5];
		int dd2[n+5];
		for(int i=0;i<n;i++){
			if(tong[fa[i].y]==0&&tong2[fa[i].y]==0&&tong3[fa[i].y]==0){
				ddd0++;
				dd0[ddd0]=fa[i].x;
			}
		}
		for(int i=0;i<n;i++){
			if(tong[fb[i].y]==0&&tong2[fb[i].y]==0&&tong3[fb[i].y]==0){
				ddd1++;
				dd1[ddd1]=fb[i].x;
			}
		}
		for(int i=0;i<n;i++){
			if(tong[fc[i].y]==0&&tong2[fc[i].y]==0&&tong3[fc[i].y]==0){
				ddd2++;
				dd2[ddd2]=fc[i].x;
			}
		}
		int ans=0;
		int xd0=0;
		int xd1=0;
		int xd2=0;
		int dka[n+5];
		int dkja=-1;
		int dkb[n+5];
		int dkjb=-1;
		int dkc[n+5];
		int dkjc=-1;
		for(int i=0;i<n;i++){
			if(tong[i]==1&&tong2[i]==0&&tong3[i]==0){
				xl++;
				dkja++;
				dka[dkja]=a[i].x;
			}
			if(tong[i]==0&&tong2[i]==1&&tong3[i]==0){
				xy++;
				dkjb++;
				dkb[dkjb]=a[i].y;
			}
			if(tong[i]==0&&tong2[i]==0&&tong3[i]==1){
				xr++;
				dkjc++;
				dkc[dkjc]=a[i].z;
			}
		}
		if(dkja!=-1){
			sort(dka,dka+dkja,cmp3);
		}
		if(dkjb!=-1){
			sort(dkb,dkb+dkjb,cmp3);
		}
		if(dkjc!=-1){
			sort(dkc,dkc+dkjc,cmp3);
		}
		for(int i=0;i<=dkja&&i<=nn;i++){
			ans+=dka[i];
		}
		for(int i=0;i<=dkjb&&i<=nn;i++){
			ans+=dkb[i];
		}
		for(int i=0;i<=dkjc&&i<=nn;i++){
			ans+=dkc[i];
		}
		int n2=n;
		for(int i=0;i<n2;i++){
			if(tong[i]>=1&&tong2[i]>=1&&tong3[i]==0){
				if(a[i].x+dd1[xd1]>a[i].y+dd0[xd0]){
					ans+=(a[i].x+dd1[xd1]);
					xd1++;
					//n2--;
				}else{
					ans+=(a[i].y+dd0[xd0]);
					xd0++;
					//n2--;
				}
			}else if(tong[i]>=1&&tong2[i]==0&&tong3[i]>=1){
				if(a[i].x+dd2[xd2]>a[i].z+dd0[xd0]){
					ans+=(a[i].x+dd2[xd2]);
					xd2++;
					//n2--;
				}else{
					ans+=(a[i].z+dd0[xd0]);
					xd0++;
					//n2--;
				}
			}else if(tong[i]==0&&tong2[i]>=1&&tong3[i]>=1){
				if(a[i].y+dd2[xd2]>a[i].z+dd1[xd1]){
					ans+=(a[i].y+dd2[xd2]);
					xd2++;
					//n2--;
				}else{
					ans+=(a[i].z+dd1[xd1]);
					xd1++;
					//n2--;
				}
			}else if(tong[i]>=1&&tong2[i]>=1&&tong3[i]>=1){
				int ly=a[i].x+dd1[xd1];
				int lr=a[i].x+dd2[xd2];
				int yl=a[i].y+dd0[xd0];
				int yr=a[i].y+dd2[xd2];
				int rl=a[i].z+dd0[xd0];
				int ry=a[i].z+dd1[xd1];
				int yzy[]={ly,lr,yl,yr,rl,ry};
				sort(yzy,yzy+6,cmp3);
				if(ly==yzy[0]){
					ans+=ly;
					xd1++;
				//	n2--;
				}else if(lr==yzy[0]){
					ans+=lr;
					xd2++;
				//	n2--;
				}else if(yl==yzy[0]){
					ans+=yl;
					xd0++;
				//	n2--;
				}else if(yr==yzy[0]){
					ans+=yr;
					xd2++;
				//	n2--;
				}else if(rl==yzy[0]){
					ans+=rl;
					xd0++;
				//	n2--;
				}else if(ry==yzy[0]){
					ans+=ry;
					xd1++;
				//	n2--;
				}
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
