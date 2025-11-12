#include<bits/stdc++.h>
using namespace std;
struct node{
	int start,end;
	long long lucheng;
}lu[2200002];
int cha[10012];
long long n,m,k,u,v,x,ans,c[12][10002];
int find(int a){
	if(cha[a]==a) return a;
	else cha[a]=find(cha[a]);
	return cha[a];
}
bool panduan(int a,int b){
	if(find(a)==find(b)) return true;
	else return false;
}
void hebing(int a,int b){
	cha[find(a)]=find(b);
	return ;
}
bool cmp(node a,node b){
	return a.lucheng<b.lucheng;
}
void dfs(int floor,int maxx,int cnt){
	if(floor==maxx){
		sort(lu+1,lu+1+m,cmp);
		long long num=cnt;
		for(int i=1;i<=m;i++){
			if(!panduan(lu[i].start,lu[i].end)){
				hebing(lu[i].start,lu[i].end);
				num+=lu[i].lucheng;
			}
		}
		//cout<<num<<endl;
		ans=min(ans,num);
		for(int i=1;i<=10010;i++){
			cha[i]=i;
		}
		return ;
	}
	if(c[floor][0]!=0) dfs(floor+1,maxx,cnt);
	for(int i=1;i<=n;i++){
		lu[++m].start=n+floor;
		lu[m].lucheng=c[floor][i];
		lu[m].end=i;
		lu[++m].start=i;
		lu[m].lucheng=c[floor][i];
		lu[m].end=n+floor;
	}
	dfs(floor+1,maxx,cnt+c[floor][0]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=10010;i++){
		cha[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>u>>v>>x;
		lu[i].start=u;
		lu[i].end=v;
		lu[i].lucheng=x;
		lu[i+m].start=v;
		lu[i+m].end=u;
		lu[i+m].lucheng=x;
	}
	m*=2;
	sort(lu+1,lu+1+m,cmp);
	if(k==0){
		for(int i=1;i<=m;i++){
			if(!panduan(lu[i].start,lu[i].end)){
				hebing(lu[i].start,lu[i].end);
				ans+=lu[i].lucheng;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i][0];
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
		}
	}
	ans=1e18;
	dfs(1,k,0);
	cout<<ans;
	return 0;
}