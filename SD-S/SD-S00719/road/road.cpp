#include<bits/stdc++.h>
using namespace std;//long long
int input(){
	char c=getchar();
	int ans=0;
	while((c<'0'||c>'9'))c=getchar();
	while(c<='9'&&c>='0'){
		ans*=10;
		ans+=c-'0';
		c=getchar();
	}
	return ans;
}
int n,m,k,fa[40004],c[25];
int fd(int x){
	if(fa[x]==x)return fa[x];
	return fa[x]=fd(fa[x]);
}
struct edge{
	int u,v,val;
	edge(int u_=0,int v_=0,int val_=0){
		u=u_,v=v_,val=val_;
	}
}g[1000006];
bool cmp(edge x,edge y){
	return x.val<y.val;
}
int cnt,cnta;
edge tmp[40005],a[23][20005];
vector<edge>v;
long long solve(int p,vector<edge> &tmpv,long long lst,int num){
	vector<edge> tmpp;
	long long tmpans=lst;
	cnt=0;
	int cnt1=0,cnt2=0;
	while(cnt!=((n+num)+n)-2){
		if(cnt1==(n+num)-2){
			while(cnt2!=n)tmp[cnt++]=a[p][cnt2++];
		}
		else if(cnt2==n){
			while(cnt1!=(n+num)-2)tmp[cnt++]=tmpv[cnt1++];
		}
		else{
			if(a[p][cnt2].val<tmpv[cnt1].val){
				tmp[cnt++]=a[p][cnt2++];
			}
			else{
				tmp[cnt++]=tmpv[cnt1++];
			}
		}
	}
	//for(int j=0;j<cnt;j++)printf("%d %d %d\n",tmp[j].u,tmp[j].v,tmp[j].val);
	for(int j=1;j<=(n+num);j++)fa[j]=j;
	for(int j=0;j<cnt;j++){
		if(fd(tmp[j].u)!=fd(tmp[j].v)){
			fa[fd(tmp[j].u)]=fd(tmp[j].v);
			tmpans+=tmp[j].val;
			tmpp.push_back(tmp[j]);
		}
	}
	//printf("\n%lld\n",tmpans);
	/*for(int i=0;i<tmpp.size();i++){
		printf("%d %d %d\n",tmpp[i].u,tmpp[i].v,tmpp[i].val);
	}*/
	for(int i=p+1;i<=k;i++){
		tmpans=min(tmpans,solve(i,tmpp,lst+c[i],num+1));
	}
	return tmpans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=input();
	m=input();
	k=input();
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int x,y,z;
		x=input();
		y=input();
		z=input();
		g[i]=edge(x,y,z);
	}
	sort(g+1,g+m+1,cmp);
	int cnt=0;
	long long ans=0;
	for(int i=1;i<=m;i++){
		if(fd(g[i].u)!=fd(g[i].v)){
			fa[fd(g[i].u)]=fd(g[i].v);
			ans+=g[i].val;
			cnt++;
			v.push_back(g[i]);
		}
		if(cnt==n-1)break;
	}
	//printf("\n%lld\n",ans);
	//for(int i=0;i<cnt;i++)printf("%d %d %d\n",v[i].u,v[i].v,v[i].val);
	for(int i=1;i<=k;i++){
		c[i]=input();cnta=0;
		for(int j=1;j<=n;j++){
			int x;
			x=input();
			a[i][cnta++]=edge(i+n,j,x);
		}
		sort(a[i],a[i]+cnta,cmp);
	}
	long long anss=ans;
	for(int i=1;i<=k;i++)anss=min(anss,solve(i,v,c[i],1));
	cout<<anss;
	return 0;
}
