#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <list>
using namespace std;
namespace novillage {

	typedef long long int int64;

	class dest {
		public:
			dest() {
				v=w=0;
			}
			dest(int V,int W) {
				v=V,w=W;
			}

			int v,w;
	};

	class road {
		public:
			int x,y,d;
			road() {
				x=y=d=0;
			}
			road(int X,int Y,int D) {
				x=X,y=Y,d=D;
			}
			bool operator<(const road &tar)const {
				return d<tar.d;
			}
	};

	vector<road> r;

	const int N=10001;
	int n,m,k,c[16],a[16][N],fa[N],sz[N];
	int64 ans;
	vector<dest> g[N];

	int find(int x) {
		return fa[x]==x ? x : fa[x]=find(fa[x]);
	}

	bool in(int x,int y) {
		return find(x)==find(y);
	}

	bool onlyone() {
		int t=find(1);
		for(int i=2; i<=n; i++)
			if(find(i)!=t)
				return false;
		return true;
	}

	void merge(int x,int y) {
		x=find(x);
		y=find(y);
		if(x==y)
			return;
		if(sz[x]<sz[y])
			swap(x,y);
		fa[y]=x;
		sz[x]+=sz[y];
	}

	int main() {
		freopen("road.in","r",stdin);
		freopen("road.out","w",stdout);
		scanf("%d%d%d",&n,&m,&k);
		for(int i=0; i<m; i++) {
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			g[u].push_back(dest(v,w));
			g[v].push_back(dest(u,w));
			r.push_back(road(u,v,w));
		}
		if(k>0)//why i have to solve it??!!?
			throw "are you crazy???!!??";
		for(int i=0; i<k; i++) {
			scanf("%d",c+i);
			for(int j=1; j<=n; i++)
				scanf("%d",&a[i][j]);
		}

		for(int i=1; i<=n; i++)
			fa[i]=i,sz[i]=1;
		sort(r.begin(),r.end());

		for(int i=0; i<r.size() && !onlyone(); i++) {
			if((!in(1,r[i].x)) || (!in(1,r[i].y))) {
				merge(r[i].x,r[i].y);
				ans+=r[i].d;
				//fprintf(stderr,"add %d %d, cost+=%d\n",r[i].x,r[i].y,r[i].d);
			}
		}

		printf("%d",ans);

		fclose(stdin);
		fclose(stdout);
		return 0;
	}

}


namespace hasvillage {

	typedef long long int int64;

	class dest {
		public:
			dest() {
				v=w=0;
			}
			dest(int V,int W) {
				v=V,w=W;
			}

			int v,w;
	};

	class road {
		public:
			int x,y,d;
			road() {
				x=y=d=0;
			}
			road(int X,int Y,int D) {
				x=X,y=Y,d=D;
			}
			bool operator<(const road &tar)const {
				return d<tar.d;
			}
	};

	const int N=10001;
	int n,m,k,c[16],a[16][N],fa[N],sz[N];
	int64 ans;
	vector<dest> g[N];
	
	int find(int x) {
		return fa[x]==x ? x : fa[x]=find(fa[x]);
	}

	bool in(int x,int y) {
		return find(x)==find(y);
	}

	bool onlyone() {
		int t=find(1);
		for(int i=2; i<=n; i++)
			if(find(i)!=t)
				return false;
		return true;
	}

	void merge(int x,int y) {
		x=find(x);
		y=find(y);
		if(x==y)
			return;
		if(sz[x]<sz[y])
			swap(x,y);
		fa[y]=x;
		sz[x]+=sz[y];
	}
	
	int inline applyvil(int x,int y,int vil){
		a[vil][x]=a[vil][y]=c[vil]=0;
	}
	
	int inline getcost(int x,int y,int vil){
		return a[vil][x]+a[vil][y]+c[vil];
	}
	
	int inline getmincost(int x,int y,int &vil){
		int minc=0x7fffffff,minvi;
		for(int i=0;i<k;i++){
			if(getcost(x,y,i)<minc)
				minc=getcost(x,y,i),minvi=i;
		}
		vil=minvi;
		return minc;
	}
	
	int inline getbestplan(){
		for(int i=1;i<=n;i++){
			if(in(1,i))
				continue;
			for(int j=1;j<=n;j++){
				if(i==j)
					continue;
				if(!in(1,i))
					continue;
				
			}
		}
	}
	
	class plan{
	public:
		bool type;//false:standard, true:village
		road *r;
		int x,y,v;
		
		void apply(){
			if(!necessary())
				return;
			if(type==false){
				merge(r->x,r->y);
				ans+=r->d;
			}
			else{
				merge(x,y);
				ans+=getcost(x,y,v);
				applyvil(x,y,v);
			}
		}
		
		int cost()const{
			if(!necessary())
				return 0;
			if(type==false)
				return r->d;
			else
				return getcost(x,y,v);
		}
		
		bool necessary()const{
			if(type==false){
				return (!in(1,r->x)) ^ (!in(1,r->y));
			}
			else{
				return (!in(1,x)) ^ (!in(1,y));
			}
		} 
		
		bool maybe()const{
			if(type==false){
				return (!in(1,r->x)) || (!in(1,r->y));
			}
			else{
				return (!in(1,x)) || (!in(1,y));
			}
		}
		
		bool operator<(const plan &tar)const{
			return cost()>tar.cost();
		}
	};
	
	list<plan> p;

	int main() {
		freopen("road.in","r",stdin);
		freopen("road.out","w",stdout);
		scanf("%d%d%d",&n,&m,&k);
		for(int i=0; i<m; i++) {
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			g[u].push_back(dest(v,w));
			g[v].push_back(dest(u,w));
			road *rd=new road(u,v,w);
			plan pl;
			pl.type=false;
			pl.r=rd;
			p.push_back(pl);
		}
//		fprintf(stderr,"done\n");
		
		for(int i=0; i<k; i++) {
			scanf("%d",c+i);
			for(int j=1; j<=n; j++)
				scanf("%d",&a[i][j]);
//			fprintf(stderr,"vildone\n");
		}
		
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				if(i==j)
					continue;
				for(int v=0;v<k;v++){
					plan pl;
					pl.type=true;
					pl.x=i;
					pl.y=j;
					pl.v=v;
					p.push_back(pl);
				}
			}

		for(int i=1; i<=n; i++)
			fa[i]=i,sz[i]=1;
		
		while(!onlyone()){
			plan pl;
			pl.x=-1;
			for(list<plan>::iterator it=p.begin();it!=p.end();){
//				fprintf(stderr,"%d      %d %d\n",it->necessary(),it->type?it->x:it->r->x,it->type?it->y:it->r->y);
				if(!it->maybe()){
					list<plan>::iterator del=it;
					it++;
					p.erase(del);
//					fprintf(stderr,"del\n");
				}
				else
					it++;
			}
			for(list<plan>::iterator it=p.begin();it!=p.end();it++){
//				fprintf(stderr,"%d      %d %d\n",it->necessary(),it->type?it->x:it->r->x,it->type?it->y:it->r->y);
				if(it->necessary())
					if(pl.x==-1 || it->cost()<pl.cost())
						pl=*it;
			}
//			for(int i=1;i<=n;i++)
//				fprintf(stderr,"%d ",fa[i]);
//			fprintf(stderr,"\nadd %d %d\n",pl.type?pl.x:pl.r->x,pl.type?pl.y:pl.r->y);
			if(pl.x==-1)
				break;
			pl.apply();
		}

		printf("%d",ans);

		fclose(stdin);
		fclose(stdout);
		return 0;
	}

}

int main() {
	return hasvillage::main();
}
