#include<bits/stdc++.h>
using namespace std;
int t,n;
struct ma {
	int h[3],x[3],c[3];
} a[100005];
int b[3][3][100005],l[3],r[3],ans;
void ti(int x,int k,int y) {
	////////cout<<"x\ny:"<<y<<endl;
	if(y<=1)return;
	////////cout<<x<<" "<<k<<" "<<y<<endl<<"2783465826438569";
	////////cout<<b[x][k][y]<<b[x][k][y/2];
	if(b[x][k][y]==0x7fffffff)return;
	if(b[x][k][y/2]==0x7fffffff) {
		////////cout<<x<<" "<<k<<" "<<y<<endl<<"2783465826438569";
		while(y!=1) {
//		////////cout<<x<<" "<<k<<" "<<y<<endl<<"2783465826438569";
////////cout<<y<<endl;
			if(b[x][k][y/2]==0x7fffffff&&b[x][k][y]!=0x7fffffff) {
				swap(b[x][k][y],b[x][k][y/2]);
//			////////cout<<x<<" "<<k<<" "<<y<<endl<<"2783465826438569";
				y/=2;
//		////////cout<<x<<" "<<k<<" "<<y<<endl<<"2783465826438569";
				////////cout<<'k'<<y<<'k'<<endl;
			}else break;
		}
//	////////cout<<x<<" "<<k<<" "<<y<<endl<<"2783465826438569";
	} else {

		////////cout<<'\n'<<10000000000;
		////////cout<<b[x][k][y]<<" "<<b[x][k][y/2];
		if(a[b[x][k][y]].c[k]<a[b[x][k][y/2]].c[k]) {
//		////////cout<<x<<" "<<k<<" "<<y<<endl<<"2783465826438569";
			swap(b[x][k][y],b[x][k][y/2]);
			////////cout<<b[x][k][y/2]<<" "<<b[x][k][y];
//		////////cout<<x<<" "<<k<<" "<<y<<endl<<"2783465826438569";
			ti(x,k,y/2);
//		////////cout<<x<<" "<<k<<" "<<y<<endl<<"2783465826438569";
		}
	}
}
void sh(int x,int y,int k) {
	////cout<<":"<<x<<' '<<y<<' '<<k<<endl;
	////cout<<":"<<x<<' '<<y<<' '<<k<<endl;
//	
	if(2*k>n)return;
	////cout<<" afgasjkjas"<<b[x][y][2*k]<<" "<<b[x][y][2*k+1]<<endl;
	if(b[x][y][2*k]==0x7fffffff) {
		if(b[x][y][2*k+1]==0x7fffffff) {
			b[x][y][k]=0x7fffffff;////cout<<" afgasjkj as";
			return;
		} else {
			b[x][y][k]=b[x][y][2*k+1];
			sh(x,y,2*k+1);////cout<<" afgasjk jas";
		}
	} else {
		if(b[x][y][2*k+1]==0x7fffffff) {
			b[x][y][k]=b[x][y][2*k];
			sh(x,y,2*k);////cout<<" afgas j kj as";
		}else
		if(a[b[x][y][2*k]].c[y]<a[b[x][y][2*k+1]].c[y]) {
			b[x][y][k]=b[x][y][2*k];
			sh(x,y,2*k);////cout<<" afgas jk jas ";
		} else {
			b[x][y][k]=b[x][y][2*k+1];
			sh(x,y,2*k+1);////cout<<" afgas jk j as";
		}
	}

}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.ans","w",stdout);
	cin>>t;
	while(t--) {
		ans=r[0]=r[1]=r[2]=0;
		cin>>n;for(int i=0;i<3;i++)
		for(int i=1; i<=n; i++)b[0][1][i]=b[0][2][i]=b[1][2][i]=b[1][0][i]=b[2][0][i]=b[2][1][i]=0x7fffffff;
		for(int i=1; i<=n; i++) {
			cin>>a[i].h[0]>>a[i].h[1]>>a[i].h[2];
			////////cout<<2<<endl;
			if(a[i].h[0]>=a[i].h[1]&&a[i].h[1]>a[i].h[2]) {
				a[i].x[0]=0;
				a[i].x[1]=1;
				a[i].x[2]=2;
				a[i].c[1]=a[i].h[0]-a[i].h[1];
				a[i].c[2]=a[i].h[0]-a[i].h[2];
			} else if(a[i].h[0]<a[i].h[1]&&a[i].h[1]<=a[i].h[2]) {
				a[i].x[0]=2;
				a[i].x[1]=1;
				a[i].x[2]=0;
				a[i].c[0]=a[i].h[1]-a[i].h[0];
				a[i].c[2]=a[i].h[1]-a[i].h[2];
			} else if(a[i].h[0]>=a[i].h[2]&&a[i].h[2]>a[i].h[1]) {
				a[i].x[0]=0;
				a[i].x[1]=2;
				a[i].x[2]=1;
				a[i].c[1]=a[i].h[0]-a[i].h[1];
				a[i].c[2]=a[i].h[0]-a[i].h[2];
			} else if(a[i].h[0]<a[i].h[2]&&a[i].h[1]>=a[i].h[2]) {
				a[i].x[0]=1;
				a[i].x[1]=2;
				a[i].x[2]=0;
				a[i].c[0]=a[i].h[1]-a[i].h[0];
				a[i].c[2]=a[i].h[1]-a[i].h[2];
			} else if(a[i].h[0]<=a[i].h[2]&&a[i].h[1]<a[i].h[0]) {
				a[i].x[0]=2;
				a[i].x[1]=0;
				a[i].x[2]=1;
				a[i].c[1]=a[i].h[2]-a[i].h[1];
				a[i].c[0]=a[i].h[2]-a[i].h[0];
			} else {
				a[i].x[0]=1;
				a[i].x[1]=0;
				a[i].x[2]=2;
				a[i].c[0]=a[i].h[1]-a[i].h[0];
				a[i].c[2]=a[i].h[1]-a[i].h[2];
			}
		}
		for(int i=1;i<=n;i++)//cout<<a[i].c[0]<<" "<<a[i].c[1]<<" "<<a[i].c[2]<<" "<<endl;
		for(int i=1; i<=n; i++) {
			ans+=a[i].h[a[i].x[0]];
			//////cout<<" "<<a[i].h[a[i].x[0]]<<endl;;
			////////cout<<3<<' '<<a[i].x[0]<<endl;
			
				////////cout<<'s';
//				
				////////cout<<" "<<a[i].x[0]<<" "<<endl;
				if(a[i].x[0]!=0) {
					++l[0];
					b[a[i].x[0]][0][l[0]]=i;
					////////cout<<endl<<b[a[i].x[0]][0][l[0]]<<'='<<i<<endl;
					////////cout<<t<<" "<<i<<"="<<b[a[i].x[0]][0][l[0]];
					ti(a[i].x[0],0,l[0]);
					
				}
				if(a[i].x[0]!=1) {
					++l[1];
					////////cout<<endl;
					////////cout<<b[a[i].x[0]][1][l[1]]<<"iu";
					b[a[i].x[0]][1][l[1]]=i;
					////////cout<<"iv"<<b[a[i].x[0]][1][l[1]];
					////////cout<<endl<<b[a[i].x[0]][1][l[1]]<<'='<<i<<endl;
					////////cout<<t<<" "<<i<<'='<<b[a[i].x[0]][1][l[1]];
					ti(a[i].x[0],1,l[1]);
				}
				if(a[i].x[0]!=2) {
					++l[2];
					b[a[i].x[0]][2][l[2]]=i;
					////////cout<<endl<<b[a[i].x[0]][2][l[2]]<<'='<<i<<endl;
					////////cout<<'c';
					////////cout<<t<<" "<<i<<'='<<b[a[i].x[0]][2][l[2]];
					ti(a[i].x[0],2,l[2]);
					
					
					
					
				}
//				////cout<<r[a[i].x[0]]<<" ";
			if(r[a[i].x[0]]<n/2) {r[a[i].x[0]]++; //cout<<a[i].x[0]<<" "<<r[a[i].x[0]]<<"v";}else {
////////cout<<i<<" "<<a[i].x[0]<<" "<<a[i].x[1]<<" ";
////////cout<<" "<<t<<"v\n";
				////////cout<<'t';
				////////cout<<"x"<<b[a[i].x[0]][a[i].x[1]][1]<<"x";
				if(b[a[i].x[0]][a[i].x[1]][1]==0x7fffffff){
					continue;
//					ans+=a[i].x[1];
				}
				ans-=a[b[a[i].x[0]][a[i].x[1]][1]].c[i];
				//cout<<" "<<a[b[a[i].x[0]][a[i].x[1]][1]].c[i]<<endl;
				////cout<<endl<<a[i].x[0]<<"cc"<<a[i].x[1]<<endl;

				////cout<<b[a[i].x[0]][a[i].x[1]][1]<<" ";
				////////cout<<"yy"<<endl;
				
////cout<<a[i].x[0]<<" "<<a[i].x[1];
//		for(int i=0;i<3;i++)for(int j=0;j<3&&j!=i;j++)for(int k=1;k<=n;k++)if(!(0x7fffffff-b[i][j][k])){////cout<<i<<'s'<<j<<'s'<<k<<'s'<<endl;exit(0);}
		sh(a[i].x[0],a[i].x[1],1);
		////cout<<"fagsdfg";
//				////cout<<
				////cout<<"a"<<b[a[i].x[0]][a[i].x[1]][1]<<" ";

				////////cout<<"yyy"<<endl;
			}
		}
//		for(int i=0;i<3;i++)for(int j=0;j<3&&j!=i;j++){for(int k=1;k<=n;k++)//cout<<b[i][j][k]<<" ";//cout<<endl;}
		cout<<ans<<'\n';
	}
	return 0;
}
