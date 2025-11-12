#include<iostream>
#include<algorithm> 
using namespace std;
long long n,m,k,ans;
struct node{
	int u,v,w;
}stu[100010];
struct bx{
	int b[100010];
	void clean(){
		for(int i=1;i<=n;i++){
			b[i]=i;
		}
		return;
	}
	long long check(int a){
		if(b[a]==a) return a;
		else        return b[a]=check(b[a]);
	}
	void merge(int x,int y){
		b[check(x)]=check(y);
		return;
	}
}tool;
bool cmp(node a,node b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>stu[i].u>>stu[i].v>>stu[i].w;
	}
	sort(stu+1,stu+m+1,cmp);
	tool.clean();
	for(int i=1;i<=m;i++){
		if(tool.check(stu[i].u)!=tool.check(stu[i].v)){
			tool.merge(stu[i].u,stu[i].v);
			ans+=stu[i].w; 
		}
	}
	cout<<ans;
	return 0; 
}

//4 3 4
