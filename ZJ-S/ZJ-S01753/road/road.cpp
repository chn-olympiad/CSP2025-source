#include<bits/stdc++.h>
using namespace std;
struct bian{
	int val,to;
};
vector<bian> v[10005];
int c[20][10005];
bian a[4000005];
int siz=0;
bool vis[10005];
void pushh(bian x){
	a[++siz]=x;
	int now=siz;
	while(a[now].val<a[now/2].val){
		bian o=a[now/2];
		a[now/2]=a[now];
		a[now]=o;
		now/=2;
	}
}
void popp(){
	a[1]=a[siz--];
	int now=1;
	if(now*2+1<=siz){
		while(a[now].val>a[now*2].val||a[now].val>a[now*2+1].val){
			if(a[now/2+1].val>a[now*2].val){
				bian o=a[now];
				a[now]=a[now*2];
				a[now*2]=o;
				now*=2;
			}else{
				bian o=a[now];
				a[now]=a[now*2+1];
				a[now*2+1]=o;
				now*=2;
				now+=1;
			}
			if(now*2+1>siz)break; 
		}
	}
	if(now*2==siz){
		if(a[now].val>a[now*2].val){
			bian o=a[now];
			a[now]=a[now*2];
			a[now*2]=o;
			now*=2;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;cin>>x>>y>>z;
		if(x==y)continue;
		bian l,u;
		l.to=x;u.to=y;
		l.val=z;u.val=z;
		v[x].push_back(u);
		v[y].push_back(l);
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<v[i].size();j++){
			//cout<<i<<' '<<v[i][j].to<<' '<<v[i][j].val<<endl;
		}
	}
	for(int i=1;i<=k;i++)
		for(int j=0;j<=n;j++)cin>>c[i][j];
	if(k==0){//1~4
		long long ans=0;
		vis[1]=1;
		for(int i=0;i<v[1].size();i++){
			if(!vis[v[1][i].to])pushh(v[1][i]);
		}
		int num=1;
		while(num<n){
			//for(int i=1;i<=siz;i++)
				//cout<<a[i].to<<' '<<a[i].val<<endl;
			//cout<<endl;
			bian x=a[1];
			popp();
			if(vis[a[1].to])continue;
			ans+=x.val;
			vis[x.to]=1;
			for(int i=0;i<v[x.to].size();i++){
				if(!vis[v[x.to][i].to])pushh(v[x.to][i]);
			}
			num++;
		}
		cout<<ans<<endl;
		return 0;
	}
	int f=1;
	for(int i=1;i<=k;i++){
		if(c[i][0]!=0){
			f=0;
			break;
		}
	}
	if(f){//ÐÔÖÊA 
		
	}
} 
