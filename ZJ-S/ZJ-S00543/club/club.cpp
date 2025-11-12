#include <bits/stdc++.h>
using namespace std;
int T,n,i,j,y,a[100010][5],sum,e[200010],f[5][200010];
struct no{int x,y,z;}b[200010];
bool cmp(no x,no y){return x.x<y.x;}
void check(int x){
	int i,j;
	if(e[x]<=n/2)return ;
	for(i=1;i<=e[x];i++){
		y=0;
		for(j=1;j<=3;j++)
			if(j!=x)y=max(y,a[f[x][i]][j]);
		for(j=1;j<=3;j++)
			if(j!=x&&y==a[f[x][i]][j])b[i].z=j;
		b[i].x=a[f[x][i]][x]-y;b[i].y=f[x][i];
	}
	sort(b+1,b+e[x]+1,cmp);
	i=1;
	while(e[x]>n/2)sum=sum-b[i].x,a[b[i].y][x]=-1e9,e[x]--,e[b[i].z]++,i++;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		e[1]=e[2]=e[3]=0;sum=0;
		for(i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			y=max(a[i][1],max(a[i][2],a[i][3]));
			for(j=1;j<=3;j++)
				if(a[i][j]==y){e[j]++,sum+=a[i][j],f[j][e[j]]=i;break;}
		}
		while(e[1]>n/2||e[2]>n/2||e[3]>n/2)check(1),check(2),check(3);
		cout<<sum<<"\n";
	}
}
