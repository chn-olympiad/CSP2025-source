#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		short n,a[100010][3]={0},b[100010]={0},x[100010]={0},y[100010]={0},z[100010]={0};
		int xx=0,yy=0,zz=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2])x[0]++,x[x[0]]=i,xx+=a[i][0];
			else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2])y[0]++,y[y[0]]=i,yy+=a[i][1];
			else z[0]++,z[z[0]]=i,zz+=a[i][2];
		}
		if(x[0]<=n/2&&y[0]<=n/2&&z[0]<=n/2){
			cout<<xx+yy+zz<<endl;
			continue;
		}
		if(x[0]>n/2){
			for(int i=1;i<=x[0];i++)b[i]=a[x[i]][0]-max(a[x[i]][1],a[x[i]][2]);
			sort(b+1,b+1+x[0]);
			for(int i=1;i<=x[0]-n/2;i++)xx-=b[i];
			cout<<xx+yy+zz<<endl;
			continue;
		}
		if(y[0]>n/2){
			for(int i=1;i<=y[0];i++)b[i]=a[y[i]][1]-max(a[y[i]][0],a[y[i]][2]);
			sort(b+1,b+1+y[0]);
			for(int i=1;i<=y[0]-n/2;i++)yy-=b[i];
			cout<<xx+yy+zz<<endl;
			continue;
		}
		if(z[0]>n/2){
			for(int i=1;i<=z[0];i++)b[i]=a[z[i]][2]-max(a[z[i]][1],a[z[i]][0]);
			sort(b+1,b+1+z[0]);
			for(int i=1;i<=z[0]-n/2;i++)zz-=b[i];
			cout<<xx+yy+zz<<endl;
			continue;
		}
	}
	return 0;
}
