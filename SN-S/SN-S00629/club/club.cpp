#include<bits/stdc++.h>
#define O1145 ios::sync_with_stdio(false);
#define O1919 cin.tie(0),cout.tie(0);
#define mid ((l+r)>>1)
#define ls (now<<1)
#define rs ((now<<1)|1)
#define ll long long
#define endl "\n"
using namespace std;
const int N=1e5+5;
int T,n,d[4],l[4][N];
bool k[N];
int x[N];
struct node{
	int v,id;
	int op;
} a[N*3];
bool cmp(node a,node b){
	return a.v>b.v;
}
int main(){
//	O1145 O1919
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;d[1]=d[2]=d[3]=0;
		int tot=0;
		for(int i=1;i<=n;i++){
			k[i]=false;
			scanf("%d %d %d",&a[tot+1].v,&a[tot+2].v,&a[tot+3].v);
			++tot;a[tot].id=i;a[tot].op=1;l[1][i]=a[tot].v;
			++tot;a[tot].id=i;a[tot].op=2;l[2][i]=a[tot].v;
			++tot;a[tot].id=i;a[tot].op=3;l[3][i]=a[tot].v;
			x[i]=0;
		}
		sort(a+1,a+tot+1,cmp);
		ll sum=0;
		for(int i=1;i<=tot;i++){
			if(!x[a[i].id]){
				sum+=a[i].v;
				k[a[i].id]=true;
				d[a[i].op]++;
				x[a[i].id]=a[i].op;
			}
		}
		int now=0;
		if(d[1]>n/2)now=1;else if(d[2]>n/2)now=2;else if(d[3]>n/2)now=3;
		if(now==0)
		{	
			cout<<sum<<endl;
			continue;
		}
		tot=0;
		for(int i=1;i<=n;i++){
			k[i]=false;
			if(x[i]==now){
				for(int j=1;j<=3;j++)
					if(j!=now)++tot,a[tot].v=l[j][i]-l[now][i],a[tot].id=i,a[tot].op=j;
			}
		}
		sort(a+1,a+tot+1,cmp);
		for(int i=1;i<=tot;i++){
			if(!k[a[i].id]){
				sum+=a[i].v; k[a[i].id]=true; d[now]--;
				if(d[now]==n/2)break;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
