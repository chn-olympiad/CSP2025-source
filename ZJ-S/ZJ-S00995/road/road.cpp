#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,fa[10100],sum=2e15;
int c[10010],a[20][10010];
bool flag;
int find(int x){
	return fa[x]==x?fa[x]:fa[x]=find(fa[x]);
}
void merge(int x,int y){
	fa[find(x)]=find(y);
}
struct edge{
	int u,v,w;
}r[1300000],R[1300000];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>R[i].u>>R[i].v>>R[i].w;
	sort(R+1,R+1+m,cmp);
	for(int i=1;i<=k;i++){
		cin>>c[i];if(c[i])flag=1;
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	if(!flag){
		int cnt=m,t=0,ccnt=0,num=n;
		for(int j=0;j<k;j++){
			t+=c[j+1],++num;
			for(int l=1;l<=n;l++)
			R[++cnt]={n+j+1,l,a[j+1][l]},++ccnt;
		}
		sort(R+m+1,R+m+1+ccnt,cmp);
		int l1=1,l2=m+1;
		for(int j=1;j<=cnt;j++){
			if(l1>m)r[j]=R[l2++];
			else if(l2>cnt)r[j]=R[l1++];
			else{
				if(R[l2].w<R[l1].w)r[j]=R[l2++];
				else r[j]=R[l1++];
			}
		}
		for(int j=1;j<=n+k;j++)fa[j]=j;
		for(int j=1;j<=cnt;j++){
			if(find(r[j].u)!=find(r[j].v)){
				t+=r[j].w,merge(r[j].u,r[j].v),--num;
				if(num==1||t>=sum)break;
			}
		}
		cout<<t;
		return 0;
	}
	for(int i=(1<<k)-1;i>=0;i--){
		int cnt=m,t=0,ccnt=0,num=n;
		for(int j=0;j<k;j++){
			if(i&(1<<j)){
				t+=c[j+1],++num;
				for(int l=1;l<=n;l++)
					R[++cnt]={n+j+1,l,a[j+1][l]},++ccnt;
			}
		}
		sort(R+m+1,R+m+1+ccnt,cmp);
		int l1=1,l2=m+1;
		for(int j=1;j<=cnt;j++){
			if(l1>m)r[j]=R[l2++];
			else if(l2>cnt)r[j]=R[l1++];
			else{
				if(R[l2].w<R[l1].w)r[j]=R[l2++];
				else r[j]=R[l1++];
			}
		}
		for(int j=1;j<=n+k;j++)fa[j]=j;
		for(int j=1;j<=cnt;j++){
			if(find(r[j].u)!=find(r[j].v)){
				t+=r[j].w,merge(r[j].u,r[j].v),--num;
				if(num==1||t>=sum)break;
			}
		}
		sum=min(sum,t);
	}
	cout<<sum;
	return 0;
}
