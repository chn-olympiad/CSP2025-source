#include<bits/stdc++.h>
using namespace std;
void R(int &x){
	char c=getchar();
	while(c<'0' || c>'9'){
		c=getchar();
	}
	x=0;
	while(c>='0' && c<='9'){
		x=10*x+c-48;
		c=getchar();
	}
	return;
}
int n,k,x[1000001],y[1000001],z[1000001],head[10011],to[2200001],net[2200001],w[2200001],a[11][10001],cnt,d[10011];
bool v[10011];
void add(int x,int y,int z){
	to[++cnt]=y;
	net[cnt]=head[x];
	head[x]=cnt;
	w[cnt]=z;
	return;
}
struct node{
	int x,d;
	friend bool operator<(node x,node y){
		return x.d>y.d;
	}
};
priority_queue<node>q;
long long p(){
	for(int i=1;i<=n+k;i++){
		d[i]=2e9;
		v[i]=0;
	}
	long long sum=0;
	q.push({1,0});
	node f;
	int r;
	while(q.size()){
		f=q.top();
		q.pop();
		if(v[f.x])	continue;
		v[f.x]=1;
		sum+=f.d;
		for(int i=head[f.x];i;i=net[i]){
			r=to[i];
			if(!v[r] && w[i]<d[r]){
				d[r]=w[i];
				q.push({r,w[i]});
			}
		}
	}
	return sum;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int m,ch=1;
	R(n);
	R(m);
	R(k);
	for(int i=1;i<=m;i++){
		R(x[i]);
		R(y[i]);
		R(z[i]);
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			R(a[i][j]);
		}
		ch&=!a[i][0];
	}
	if(ch){
		for(int i=1;i<=m;i++){
			add(x[i],y[i],z[i]);
			add(y[i],x[i],z[i]);
		}
		int t;
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				if(!a[i][j]){
					t=j;
					break;
				}
			}
			for(int j=1;j<=n;j++){
				if(j==t)	continue;
				add(j,t,a[i][j]);
				add(t,j,a[i][j]);
			}
		}
		printf("%lld",p());
		return 0;
	}
	long long sum,min1=1e18;
	for(int i=0;i<1<<k;i++){
		sum=cnt=0;
		for(int j=1;j<=n+k;j++){
			head[j]=0;
		}
		for(int j=1;j<=m;j++){
			add(x[j],y[j],z[j]);
			add(y[j],x[j],z[j]);
		}
		for(int j=1;j<=k;j++){
			if((i>>j-1)&1){
				sum+=a[j][0];
				for(int K=1;K<=n;K++){
					add(j+n,K,a[j][K]);
					add(K,j+n,a[j][K]);
				}
			}
		}
		if(sum<=min1)	min1=min(min1,sum+p());
	}
	printf("%lld",min1);
	return 0;
}
