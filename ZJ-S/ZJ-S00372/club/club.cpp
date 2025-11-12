#include<bits/stdc++.h>
using namespace std;

int T,n;
int a[100010][4];
int b[100010];
struct point{
	int dis,num;
}p[100010];
int x[4],t,c;
long long ans;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		x[1]=x[2]=x[3]=ans=0;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			t=1,c=200000;
			for(int j=2;j<=3;j++)
				if(a[i][j]>a[i][t]) t=j;
			for(int j=1;j<=3;j++)
				if(j!=t&&c>a[i][t]-a[i][j]) c=a[i][t]-a[i][j];
			p[i].dis=c,p[i].num=t;
			x[t]++,ans+=a[i][t];
		}
		t=-1;
		for(int i=1;i<=3;i++)
			if(x[i]>n/2) t=i;
		if(t!=-1){
			int y=x[t]-(n/2),u=0;
			for(int i=1;i<=n;i++)
				if(p[i].num==t) b[++u]=p[i].dis;
			sort(b+1,b+u+1);
			for(int i=1;i<=y;i++) ans-=b[i];
		}
		cout<<ans<<"\n";
	}
}
