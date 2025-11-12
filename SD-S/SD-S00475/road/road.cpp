#include<bits/stdc++.h>
using namespace std;
long long n,m,k,sum=0,c[2000005];
struct o{
	long long x,y,z;
	long long xx,yy,zz,aa,bb;
}a[2000005],b[2000005];
int cmp(o a,o b){
	return a.z<b.z;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","r",stdout);
    cin>>n>>m>>k;
    memset(c,0,sizeof(c));
    	for(int i=1;i<=m;i++){
    		cin>>a[i].x>>a[i].y>>a[i].z;
    		c[i]=1;
		}
	  for(int i=1;i<=k;i++){
	  	 cin>>b[i].xx>>b[i].yy>>b[i].zz>>b[i].aa>>b[i].bb;
	  }
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(c[a[i].x]==0&&c[a[i].y]==0) continue;
		else sum+=a[i].z,c[a[i].x]=0,c[a[i].y]=0;
	}
	cout<<sum<<endl;
	return 0;
}
