#include<bits/stdc++.h> 
using namespace std;
int n,m,k;
int a[10025];
long long cost=10e18;
struct stu{
	int u,v,w;
	int knum;
}r[2000005];
int top;
bool cmp(const stu &x,const stu &y){
	return x.w<y.w;
}
int c[15];
void begin(){
	for(int i=1;i<=10025;i++){
		a[i]=i;
	}
}
int get(int x){
	if(a[x]==x)return x;
	return a[x]=get(a[x]);
}

int book[15];
int ans(){
	long long sum=0;
	begin();
	for(int i=1;i<=top;i++){
		if(book[r[i].knum]==1)continue;
		int t=r[i].u;
		int s=r[i].v;
		t=get(t);
		s=get(s);
		if(t!=s){
			sum+=r[i].w;
			a[s]=t;
		}
	}
	return sum;
}
void dfs(int step){
	if(step==k+1){
		long long x=ans();
		for(int i=1;i<=k;i++){
			if(!book[i]){
				x+=c[i];
			}
		}
		
		cost=min(x,cost);
		return;
	}
	book[step]=1;
	dfs(step+1);
	book[step]=0;
	dfs(step+1);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&r[i].u,&r[i].v,&r[i].w);
		r[i].knum=0;
	}
	
	top=m;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
			top++;
			r[top].u=n+i;
			r[top].v=j;
			r[top].w=x;
			r[top].knum=i;
		}
	}
	
	sort(r+1,r+1+top,cmp);
	
	begin();
	dfs(1);
	cout<<cost;
	fclose(stdin);
	fclose(stdout);
	return 0;
}