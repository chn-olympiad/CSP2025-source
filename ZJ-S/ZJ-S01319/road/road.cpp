#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long k=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		k=k*10+c-'0';
		c=getchar();
	}
	return k*f;
}
const long long maxn=2e4+100,maxm=2e6+20*maxn;
struct node{
	long long w;
	int fr,to,next;
}edge[maxm],edge2[maxn*20];
int vex[maxn],ei;
inline void add(int u,int v,long long w){
	edge[++ei].next=vex[u];
	edge[ei].fr=u;
	edge[ei].to=v;
	edge[ei].w=w;
	vex[u]=ei;
}
int vex2[maxn],ei2;
inline void add2(int u,int v,long long w){
	edge2[++ei2].next=vex2[u];
	edge2[ei2].to=v;
	edge2[ei2].w=w;
	edge2[ei2].fr=u;
	vex2[u]=ei2;
}
inline bool cmp(node a,node b){
	return  a.w<b.w;
}
long long prt[maxn],d[21][maxn],sum,ans=0x7f7f7f7f7f7f,num,n,m,k;
inline long long gf(long long x){
	if(x==prt[x]){
		return x;
	}
	prt[x]=gf(prt[x]);
	return prt[x];
}
inline void kruskal(long long &num){
	long long cnt=0,i=1,j=1,p;
	while(1){
		if(num>ans){
			return ;
		}
//		cout<<ei2<<" "<<j<<" "<<edge2[j].w<<" "<<edge[i].w<<endl;
		if(i<=ei&&(j>ei2||edge2[j].w>=edge[i].w)){
			p=i;
//			cout<<p<<endl;
			i++;
			long long f1=gf(edge[p].fr),f2=gf(edge[p].to);
			if(f1!=f2){
//				cout<<edge[p].fr<<" "<<edge[p].to<<" "<<edge[p].w<<endl;
				prt[f1]=f2;
				num+=edge[p].w;
				cnt++;
				if(cnt==sum){
				return ;
				}
			}
		}else if(j<=ei2){
			p=j;
			j++;
			
			long long f1=gf(edge2[p].fr),f2=gf(edge2[p].to);
			if(f1!=f2){
//				cout<<edge2[p].fr<<" "<<edge2[p].to<<" "<<edge2[p].w<<endl;
				prt[f1]=f2;
				num+=edge2[p].w;
				cnt++;
				if(cnt==sum){
					return ;
				}
			}
		}else{
			break;
		}
		
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(long long i=1;i<=m;i++){
		int u,v;
		long long w;
		u=read();
		v=read();
		w=read();
		add(u,v,w);
	}
	for(long long i=1;i<=n;i++){
		prt[i]=i;
	}
	sort(edge+1,edge+ei+1,cmp);
	int f1=0;
	for(long long i=0;i<k;i++){
		int f=1;
		for(long long j=0;j<=n;j++){
			d[i][j]=read();
			if(d[i][j]!=0){
				f=0;
			}
		}
		if(f){
			f1=1;
		}
	}
	if(f1){
		cout<<0;
		return 0;
	}
	for(long long i=0;i<(1<<k);i++){
		num=0,sum=n,ei2=0;
		for(long long j=1;j<=n+k;j++){
			prt[j]=j;
		}
		int f=0;
		for(long long j=0;(1<<j)<=i;j++){
			if(((1<<j)&i)!=0){
				num+=d[j][0];
				if(num>ans){
					f=1;
					break;
				}
				sum++;
				for(long long z=1;z<=n;z++){
					add2(z,j+n+1,d[j][z]);
				}
			}
			
		}
		if(f){
			break;
		}
//		cout<<ei<<" "<<ei2<<" ";
		sort(edge2+1,edge2+ei2+1,cmp);
		kruskal(num);
//	cout<<num<<"**()"<<endl;
		ans=min(ans,num);
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
