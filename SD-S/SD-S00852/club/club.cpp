#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define ull unsigned long long
#define Ckmax(x,y) x=max((x),(y))
#define Ckmin(x,y) x=min((x),(y))
using namespace std;
const int N=1e5+5;
const int IINF=0x3f3f3f3f;
const ll LINF=0x3f3f3f3f3f3f3f3fll;

inline void FileIO(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
} 

template<typename Type>
inline void read(Type &res){
	Type x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}	
	res=x*f;
}

int T,n;

struct Node{
	int x,v;
	
	bool operator<(const Node& tmp)const{
		return v>tmp.v;
	}
}a[N][4];

priority_queue<pii,vector<pii>,greater<pii> > q[4];

void Clear(){
	for(int i=1;i<=3;i++){
		while(q[i].size()) q[i].pop(); 
	}
}

void Solve(){
	Clear();
	read(n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			read(a[i][j].v);
			a[i][j].x=j;
		}
		sort(a[i]+1,a[i]+4);
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
//		printf("A[%d]: (%d,%d)(%d,%d)(%d,%d)\n",i,a[i][1].x,a[i][1].v,a[i][2].x,a[i][2].v,a[i][3].x,a[i][3].v);
		int id=a[i][1].x;
		if((signed)q[id].size()==(n>>1)){
			if(a[i][1].v-q[id].top().first>a[i][2].v){
				ans+=a[i][1].v-q[id].top().first;
				int x=q[id].top().second; q[id].pop();
				q[id].push({a[i][1].v-a[i][2].v,i});
				q[a[x][2].x].push({a[x][2].v-a[x][3].v,x});
			}
			else{
				ans+=a[i][2].v;
				q[a[i][2].x].push({a[i][2].v-a[i][3].v,i});
			}
		}
		else{
			ans+=a[i][1].v;
			q[id].push({a[i][1].v-a[i][2].v,i});
		}
	}
	printf("%lld\n",ans);
}

signed main(){
	//静心，longlong，大小，空间，格式，文件，复杂度
	//Ren5Jie4Di4Ling5%
	FileIO();
	read(T);
	while(T--) Solve();
	return 0;
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
