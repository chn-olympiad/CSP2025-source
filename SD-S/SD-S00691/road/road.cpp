#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int ans=0;
	char c=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))ans=1ll*ans*10+c-'0',c=getchar();
	return ans;
}
struct node{
	int x,y,z;
}a[1000010],b[10010],c[20][100010],v1[50][100010],v2[50][100010];
int ss1[110],ss2[110];
int fa[20010];
int x[10010];
inline int find(int i){
	int u=i;
	while(fa[i]!=i)i=fa[i];
	while(fa[u]!=i){
		int t=fa[u];
		fa[u]=i;
		u=t;
	}
	return i;
}
int w[110];
bool cmp(node i,node j){
	return i.z<j.z;
}
node mem[1000010];
void merge(node a[],node b[],int s1,int s2){
	int x=1,y=1,sz=0;
	while(x<=s1||y<=s2){
		if(x<=s1&&(y>s2||a[x].z<b[y].z))mem[++sz]=a[x],x++;
		else mem[++sz]=b[y],y++;
	}
}
node tmp[1000010],tmp1[1000010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=read(),m=read(),k=read();
	long long ans=1e15;
	for(int i=1;i<=m;i++){
		a[i].x=read();
		a[i].y=read();
		a[i].z=read();
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=k;i++){
		w[i]=read();
		for(int j=1;j<=n;j++){
			c[i][j].x=i+n,c[i][j].y=j;
			c[i][j].z=read();
		}
		sort(c[i]+1,c[i]+n+1,cmp);
	}
	int sz=0;
	for(int i=1;i<=m;i++){
		int u=find(a[i].x),v=find(a[i].y);
		if(u==v)continue;
		fa[u]=v;
		b[++sz]=a[i];
	}
	if(k<=5){
		for(int i=0;i<(1<<k);i++){
			int s=sz;
			long long sum=0;
			for(int i=1;i<=sz;i++)tmp[i]=b[i];
			for(int i=1;i<=n+k;i++)fa[i]=i;
			for(int j=1;j<=k;j++){
				if((i>>(j-1))&1){
					merge(c[j],tmp,n,s);
					s+=n;
					for(int i=1;i<=s;i++)tmp[i]=mem[i];
					sum+=w[j];
				}
			}
			for(int i=1;i<=s;i++){
				int x=find(tmp[i].x),y=find(tmp[i].y);
				if(x==y)continue;
				fa[x]=y;
				sum+=tmp[i].z;
			}
			ans=min(ans,sum);
		}
		cout<<ans<<endl;
	}else{
		int B=k/2;
		for(int i=0;i<(1<<B);i++){
			int s1=0,s=sz;
			for(int i=1;i<=sz;i++)tmp[i]=b[i];
			for(int i=1;i<=n+k;i++)fa[i]=i;
			for(int j=1;j<=B;j++){
				if((i>>(j-1))&1){
					merge(c[j],tmp,n,s);
					s+=n;
					for(int i=1;i<=s;i++)tmp[i]=mem[i];
				}
			}
			for(int j=1;j<=s;j++){
				int x=find(tmp[j].x),y=find(tmp[j].y);
				if(x==y)continue;
				fa[x]=y;
				v1[i][++s1]=tmp[j];
			}
			ss1[i]=s1;
		}
		for(int i=0;i<(1<<(k-B));i++){
			int s1=0,s=sz;
			for(int i=1;i<=sz;i++)tmp[i]=b[i];
			for(int i=1;i<=n+k;i++)fa[i]=i;
			for(int j=B+1;j<=k;j++){
				if((i>>(j-B-1))&1){
					merge(c[j],tmp,n,s);
					s+=n;
					for(int i=1;i<=s;i++)tmp[i]=mem[i];
				}
			}
			for(int j=1;j<=s;j++){
				int x=find(tmp[j].x),y=find(tmp[j].y);
				if(x==y)continue;
				fa[x]=y;
				v2[i][++s1]=tmp[j];
			}
			ss2[i]=s1;
		}
		for(int i=0;i<(1<<k);i++){
			int s1=i&((1<<B)-1),s2=(i&((1<<k)-(1<<B)))>>B;
			long long sum=0;
			for(int i=1;i<=n+k;i++)fa[i]=i;
			for(int j=1;j<=ss1[s1];j++)tmp1[j]=v1[s1][j];
			for(int j=1;j<=ss2[s2];j++)tmp[j]=v2[s2][j];
			merge(tmp1,tmp,ss1[s1],ss2[s2]);
			for(int j=1;j<=ss1[s1]+ss2[s2];j++){
				int x=find(mem[j].x),y=find(mem[j].y);
				if(x==y)continue;
				fa[x]=y;
				sum+=mem[j].z;
			}
			for(int j=1;j<=k;j++){
				if((i>>(j-1))&1)sum+=w[j];
			}
			ans=min(ans,sum);
		}
		cout<<ans<<endl;
	}
	return 0;
}

