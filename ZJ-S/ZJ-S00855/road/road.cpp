#include<bits/stdc++.h>

using namespace std;
const int N=1e6+10;
const int M=1e4+10;
const int G=1e3+10;
struct node{
	int x,y,z;
}a[N];
int n,m,k,ans=0,sum=0;
int f[M],b[G][G],c[G];
bool cmp(node x,node y){
	return x.z<y.z;
}
int find(int x){
	if(x==f[x])return x;
	return f[x]=find(f[x]);
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){
		for(int i=1;i<=m;i++)cin>>a[i].x>>a[i].y>>a[i].z;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++)f[i]=i;
	    for(int i=1;i<=m;i++){
	    	int fx=find(a[i].x),fy=find(a[i].y);
	    	if(fx!=fy){
	    		sum++;
	    	    f[fx]=fy;
	    	    ans+=a[i].z;
			}
			if(sum==n-1)break;
		}
		cout<<ans;
	}else{
		for(int i=1;i<=n;i++)
		    for(int j=1;j<=n;j++)b[i][j]=1e9;
		for(int i=1;i<=m;i++){
			int x,y,z;
			cin>>x>>y>>z;
			b[x][y]=b[y][x]=min(b[x][y],z);
		}
		for(int i=1;i<=k;i++){
			int d;
			cin>>d;
			for(int j=1;j<=n;j++)cin>>c[j];
			for(int j=1;j<=n;j++)
			    for(int r=j+1;r<=n;r++)b[j][r]=b[r][j]=min(b[j][r],c[j]+c[r]);
		}
		int num=0;
		for(int i=1;i<=n;i++)
		    for(int j=i+1;j<=n;j++)
		        if(b[i][j]!=1e9)
		            a[++num].x=i,a[num].y=j,a[num].z=b[i][j];
		sort(a+1,a+num+1,cmp);	
		for(int i=1;i<=n;i++)f[i]=i;
	    for(int i=1;i<=num;i++){
	    	int fx=find(a[i].x),fy=find(a[i].y);
	    	if(fx!=fy){
	    		sum++;
	    	    f[fx]=fy;
	    	    ans+=a[i].z;
			}
			if(sum==n-1)break;
		}
		cout<<ans;
	}
	return 0;
}
/*4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 1 8 2 4
0 1 3 2 4*/
