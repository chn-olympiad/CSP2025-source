#include<bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,next,id;
	long long w;
}e[2200001];
int n,m,k,x,y,head[10011],r[10011],cnt,vis[11];
long long s[10011],ans,z,v[11][10001];
queue<long long>q;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>x>>y>>z;
		e[i*2-1].from=x;
		e[i*2-1].to=y;
		e[i*2-1].next=head[x];
		e[i*2-1].w=z;
		e[i*2-1].id=i*2-1;
		head[x]=i*2-1;
		
		e[i*2].from=y;
		e[i*2].to=x;
		e[i*2].next=head[y];
		e[i*2].w=z;
		e[i*2].id=i*2;
		head[y]=i*2;
	}
	cnt=n+1;
	for(int i=1;i<=k;i++){
		cin>>v[i][0];
		for(int j=1;j<=n;j++){
			x=i+n;
			y=j;
			cin>>v[i][j];
			z=v[i][j];
			e[cnt*2-1].from=x;
			e[cnt*2-1].to=y;
			e[cnt*2-1].next=head[x];
			e[cnt*2-1].w=z;
			e[cnt*2-1].id=cnt*2-1;
			head[x]=cnt*2-1;
		
			e[cnt*2].from=y;
			e[cnt*2].to=x;
			e[cnt*2].next=head[y];
			e[cnt*2].w=z;
			e[cnt*2].id=cnt*2;
			head[y]=cnt*2;
			cnt++;
		}
	}
	memset(s,0x3f3f3f,sizeof(s));
	s[1]=0;
	q.push(1);
	while(!q.empty()){
		x=q.front();
		q.pop();
		for(int i=head[x];i;i=e[i].next){
			y=e[i].to;
			z=e[i].w;
			if(s[y]>s[x]+z){
				if(x>n){
					vis[x-n]++;
				}
				s[y]=s[x]+z;
				r[y]=e[i].id;
				q.push(y);
				if(y>n){
					vis[y-n]--;
				}
			}
		}
	}
	for(int i=2;i<=n+k;i++){
		if(i<=n||vis[i-n]){
			if(vis[i-n]){
				ans+=v[i-n][0];
			}
	 	    x=e[r[i]].from;
	    	ans+=e[r[i]].w;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
