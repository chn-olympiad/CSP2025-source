#include<bits/stdc++.h>
using namespace std;
int n,m,k,l=0,q[2000][2000],ans;
bool kf[1000100];
struct str{
	int x,y,z;
}a[1000100];
bool cmp(str x,str y){
	return x.z<y.z;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	memset(q,127,sizeof(q));
	for(int i=1;i<=m;i++){
		l++;
		scanf("%d%d%d",&a[l].x,&a[l].y,&a[l].z);
		ans+=a[l].z;
		q[a[l].x][a[l].y]=a[l].z;
		q[a[l].y][a[l].x]=a[l].z;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			int x;
			scanf("%d",&x);
		}
	}
	for(int i=1;i<=n;i++) q[i][i]=0;
	sort(a+1,a+1+m,cmp);
//	cout<<ans<<endl;
	for(int ii=1;ii<=m;ii++){
		q[a[l].x][a[l].y]=99999999;
		q[a[l].y][a[l].x]=99999999;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(max(q[j][i],q[i][k])<9999999){
						if(q[j][i]+q[i][k]<q[j][k]){
							q[j][k]=q[j][i]+q[i][k];
						}
					}
				}
			}
		}
		if(q[a[l].x][a[l].y]<9999999){
			ans-=a[l].z,kf[l]=1;
		//	cout<<q[a[l].x][a[l].y];
		}
		memset(q,127,sizeof(q));
		for(int j=1;j<=m;j++){
			if(kf[j]==0){
				q[a[l].x][a[l].y]=a[l].z;
				q[a[l].y][a[l].x]=a[l].z;
			}
		}
		for(int j=1;j<=n;j++) q[j][j]=0;
	}
	cout<<ans;
	return 0;
}
//s-00398
