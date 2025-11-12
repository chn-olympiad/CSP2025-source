#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,ans,sa,sb,sc;
int sum=0;
struct man{
	int a,b,c;
}m[N];

void files(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	return;
}

bool cmpa(man x,man y){
	return x.a>y.a;
}
void init(){
	sum=0;ans=-1;sa=0;sb=0;sc=0;
}
void dfs(int id,int cnt){
	if(id==n+1){
		ans=max(ans,cnt);
		return;
	}
	if(sa<n/2){
		sa++;
		dfs(id+1,cnt+m[id].a);
		sa--;
	}
	if(sb<n/2){
		sb++;
		dfs(id+1,cnt+m[id].b);
		sb--;
	}
	if(sc<n/2){
		sc++;
		dfs(id+1,cnt+m[id].c);
		sc--;
	}
	return;
}
void PA(){
	sort(m+1,m+n+1,cmpa);
	for(int i=1;i<=n/2;i++){
		sum+=m[i].a;
	}
	cout<<sum<<'\n';
	return;
}
void df2(int id,int cnt){
	if(id==n+1){
		ans=max(ans,cnt);
		return;
	}
	if(sa<n/2){
		sa++;
		df2(id+1,m[id].a+cnt);
	}
	if(sb<n/2){
		sb++;
		df2(id+1,m[id].b+cnt);
	}
	return;
}
int main(){
	files();
	int T;
	cin>>T;
	while(T--){
		init();
		cin>>n;
		bool pendA=false,pendB=false;
		for(int i=1;i<=n;i++){
			cin>>m[i].a>>m[i].b>>m[i].c;
			if(m[i].b!=0)pendA=true;
			if(m[i].c!=0)pendB=true;
		}
		if(!pendA&&!pendB){
			PA();
			continue;
		}
		if(!pendB){
			df2(1,0);
			cout<<ans<<'\n';
			continue;
		}
		if(n<=200){
			dfs(1,0);
			cout<<ans<<'\n';
			continue;
		}
	}
	return 0;
}
