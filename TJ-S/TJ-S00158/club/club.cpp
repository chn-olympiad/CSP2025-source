#include <cstdio>
#include <algorithm>

const int MAXN=100010;
struct rec{
	int a1,a2,a3;
}a[MAXN];
int n,limit;

namespace force{
	const int maxn=205;
	bool hasmem[maxn][maxn][maxn];
	long long mem[maxn][maxn][maxn];
	
	long long dfs(int c1,int c2,int c3){
		int len=c1+c2+c3;
		if(len==n) return 0;
		if(hasmem[c1][c2][c3]) return mem[c1][c2][c3];
		
		long long ans=0;
		if(c1<limit)
			ans=std::max(ans,dfs(c1+1,c2,c3)+a[len+1].a1);
		if(c2<limit)
			ans=std::max(ans,dfs(c1,c2+1,c3)+a[len+1].a2);
		if(c3<limit)
			ans=std::max(ans,dfs(c1,c2,c3+1)+a[len+1].a3);
		
		hasmem[c1][c2][c3]=true;
		mem[c1][c2][c3]=ans;
		return ans;
	}
	void solve(){
		limit=n/2;
		for(int i=0;i<=limit;i++){
			for(int j=0;j<=limit;j++){
				for(int k=0;k<=limit;k++){
					hasmem[i][j][k]=false;
				}
			}
		}
		printf("%lld\n",dfs(0,0,0));
	}
	/*
	3
	4
	4 2 1
	3 2 4
	5 3 4
	3 5 1
	4
	0 1 0
	0 1 0
	0 2 0
	0 2 0
	2
	10 9 8
	4 0 0
	*/
}

namespace ok{
const int maxn=100010;

bool cmp(rec x,rec y){
	if(x.a1!=y.a1) return x.a1>y.a1;
	if(x.a2!=y.a2) return x.a2>y.a2;
	return x.a3>y.a3; 
}

int mmax(int x,int y,int z){
	return std::max(std::max(x,y),std::max(y,z));
}
int mmax_id(int x,int y,int z){
	int d=mmax(x,y,z);
	if(d==x) return 1;
	if(d==y) return 2;
	return 3;
}

int mmin(int x,int y,int z){
	return std::min(std::min(x,y),std::min(y,z));
}
int mmin_id(int x,int y,int z){
	int d=mmin(x,y,z);
	if(d==x) return 1;
	if(d==y) return 2;
	return 3;
}

int mmid(int x,int y,int z){
	return x-mmax(x,y,z)+y-mmin(x,y,z)+z;
}
int mmid_id(int x,int y,int z){
	int d=mmid(x,y,z);
	if(d==x) return 1;
	if(d==y) return 2;
	return 3;
}

int c[5],s[5];

void solve(){
	std::sort(a+1,a+n+1,cmp);
	
	limit=n/2;
	for(int i=1;i<=n;i++){
		int maxai=mmax(a[i].a1,a[i].a2,a[i].a3);
		int maxid=mmax_id(a[i].a1,a[i].a2,a[i].a3);
		
		if(c[maxid]<limit) c[maxid]++,s[maxid]+=maxai;
		else{
			int midai=mmid(a[i].a1,a[i].a2,a[i].a3);
			int midid=mmid_id(a[i].a1,a[i].a2,a[i].a3);
			int minai=mmin(a[i].a1,a[i].a2,a[i].a3);
			int minid=mmin_id(a[i].a1,a[i].a2,a[i].a3);
			
			if(c[midid]<limit) c[midid]++,s[midid]+=midai;
			else c[minid]++,s[minid]+=minai;
		}
	}
	printf("%lld\n",(long long)s[1]+s[2]+s[3]);
	
	for(int i=1;i<=3;i++) c[i]=0,s[i]=0;
}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&a[i].a1,&a[i].a2,&a[i].a3);
		
		if(n<=1000) force::solve();
		else ok::solve();
	}
	return 0;
}
