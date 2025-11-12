#include<bits/stdc++.h>
using namespace std;
long long read(){
	char c=getchar();
	long long x=0,g=1;
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') g=-1,c=getchar();
	while(c>='0' && c<='9'){
		x=x*10+c-'0';c=getchar();
	}
	return x*g;
}
long long n,m,nn,ad,k,tot,sum,ans[22],c[22],final_ans;
struct node{
	long long st,en,w;
}eg[3000006],eg2[3000006];
bool cmp(node x,node y){
	return x.w<y.w;
}
long long fa[50000];
long long find_(long long x){return fa[x]==x?x:fa[x]=find_(fa[x]);}
void dij(long long lim,long long id,long long sum){
	sort(eg+1,eg+sum+1,cmp);
	long long num=0,all=0;
	for(long long i=1;i<=lim+k;i++) fa[i]=i;
	for(long long i=1;i<=sum;i++){
		long long dx=find_(fa[eg[i].en]),dy=find_(fa[eg[i].st]);
		if(fa[dx]==fa[dy]) continue;
		num++;fa[dx]=dy;all+=eg[i].w;
		if(num>=lim-1) break;
	}
	ans[id]=all;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();nn=n;
	for(long long i=1;i<=m;i++){
		long long u=read(),v=read(),w=read();
		tot++;
		eg[tot]=eg2[tot]={u,v,w};
	}
	long long sum=tot;
	dij(nn,0,sum);final_ans=ans[0];
	for(long long i=1;i<=k;i++){
		c[i]=read();
		for(long long j=1;j<=n;j++){
			long long x=read();
			eg[++sum]={j,nn+1,x};
		}
		dij(nn+1,i,sum);ans[i]+=(ad+c[i]);
		if(ans[i]>final_ans){
			sum=tot;
			for(int j=1;j<=sum;j++){
				eg[j]=eg2[j];
			}
		}
		else{
			ad+=c[i];
			nn++;tot=sum;
			final_ans=ans[i];
			for(int j=1;j<=sum;j++){
				eg2[j]=eg[j];
			}
		}
	}
	cout<<final_ans;
	return 0;
}