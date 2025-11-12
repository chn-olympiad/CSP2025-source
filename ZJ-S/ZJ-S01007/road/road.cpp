#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,d;
}a[1000050];
struct nodee{
	int num,id;
}d[10050];
int fa[10050],n,m,k,ans;
vector<int> c[10050];
vector<node> b;
bool cmp(node x,node y){
	return x.d<y.d;
}
bool cmp2(node x,node y){
	return x.d>y.d;
}
bool cmp3(nodee x,nodee y){
	return x.num<y.num;
}
int find1(int x){
	if(fa[x]!=x)
		return find1(fa[x]);
	return x;
}
/*void dfs(int x){
	for(int i=0;i<a[x].size();i++){
		if(fa[a[x][i]]!=x){
			fa[a[x][i]]=x;
			dfs(a[x][i]);
		}
	}
}
bool find2(int x,int y){
	if(fa[x]==x)
		return 0;
	if(fa[x]==y)
		return 1;
	else
		return dfs(fa[x]);
}*/
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].d;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=m;i++){
		if(find1(a[i].x)!=find1(a[i].y)){
			b.push_back((node){a[i].x,a[i].y,a[i].d});
			c[a[i].x].push_back(a[i].y);
			c[a[i].y].push_back(a[i].x);
			fa[a[i].y]=fa[a[i].x];
			ans+=a[i].d;
		}
	}cout<<ans<<endl;
/*	sort(b.begin(),b.end(),cmp2);
	for(int i=1;i<=k;i++){
		cin>>x;
		ans2=ans;
		minn=INT_MAX;
		for(int j=1;j<=n;j++){
			cin>>d[j].num;
			d[j].id=j;
			if(d[j]<minn){
				minn=d[j];
				minid=j;
			}
		}
		sort(d+1,d+1+n,cmp3);
		ans2+=x+minn;
		fa[minid]=minid;
		dfs(minid);
		/*while(++j){
			j-=1;
			if(b[j].x==fa[b[j].y])
				int q=b[j].y;
			else
				int q=b[j].x;
			w=d[j+1].id;
			if(find2(w,q)){
				e.push_back({w,})
			}
			j+=1;
		}*/
		
	}
	
//	cout<<ans<<endl;
