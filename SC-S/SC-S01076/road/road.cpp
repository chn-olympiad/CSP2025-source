#include<bits/stdc++.h>
using namespace std;
const int N=21000010;
const int N2=1000010;
int n,m,k;
bool bo[N2];
struct node{
	int to,w,u;
	int id;
}e[N];
int p=0;
int q[N];
int w1[20];
int f[N2];
int c1[N2];
long long num;
long long sum;

void add(int a,int b,int c,int d){
	e[++p].to=b;
	e[p].u=a;
	e[p].w=c;
	e[p].id=d;
}
bool cmp(node a,node b){
	return a.w+w1[a.id]<b.w+w1[b.id];
}
int find(int x){
	if(x==f[x]){
		return x;
	}else{
		f[x]=find(f[x]);
		return f[x];
	}
}
void m_s(int x,int y){
	int f_x=find(x),f_y=find(y);
	f[x]=y;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		
		add(x,y,z,0);
		add(y,x,z,0);
		sum+=z;
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			f[i]=i;
		}
		int cnt=0;
		sort(e+1,e+1+p,cmp);
		int i=1;

		while(cnt<n-1){
			int u=e[i].u,v=e[i].to;
	
			u=find(u);
			v=find(v);
			if(f[u]==f[v]){
				i++;
				continue;
			}else{
				m_s(u,v);
				cnt++;
				num+=e[i].w;
				i++;
			} 
		}
	}else{
	for(int i=1;i<=k;i++){
		scanf("%d",&w1[i]);
		
		for(int j=1;j<=n;j++){
			if(i==1){
				f[j]=j;
			}
			scanf("%d",&c1[j]);
		//	cout<<p<<endl;
			if(w1[i]>=sum){
				continue;
			}
			for(int u=1;u<j;u++){
				add(u,j,c1[u]+c1[j],i);
				add(j,u,c1[u]+c1[j],i);	
			}
		}
	}
	int cnt=0;
	sort(e+1,e+1+p,cmp);
	int i=1;
//	for(int j=1;j<=n;j++){
//		cout<<f[j]<<endl;
//	}
	while(cnt<n-1){
		int u=e[i].u,v=e[i].to;
	//	cout<<u<<' '<<v<<' '<<cnt<<' '<<e[i].w<<' '<<w1[e[i].id]<<endl;
		u=find(u);
		v=find(v);
		if(f[u]==f[v]){
			i++;
			continue;
		}else{
			m_s(u,v);
			cnt++;
			num+=e[i].w;
			if(e[i].id!=0&&bo[e[i].id]==0){
				bo[e[i].id]=1;
				num+=w1[e[i].id];
			}
			i++;
		} 
	}
	}

	printf("%lld",num);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 