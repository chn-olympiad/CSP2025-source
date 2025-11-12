#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

namespace club {
	typedef long long int int64;

	const int N=100001;
	int n,a[N],b[N],c[N];
	vector<int> ai,bi,ci;

	int64 max(int64 x,int64 y) {
		return x>y ? x:y;
	}

	int max(int x,int y) {
		return x>y ? x:y;
	}

	int64 max(int64 x,int64 y,int64 z) {
		return max(x,max(y,z));
	}

	int max(int x,int y,int z) {
		return max(x,max(y,z));
	}

	bool cmpa(int x,int y) {
		return a[x]>a[y];
	}

	bool cmpb(int x,int y) {
		return b[x]>b[y];
	}

	bool cmpc(int x,int y) {
		return c[x]>c[y];
	}

	class node {
		public:
			node() {
				index=cost=target;
			}
			node(int i,int c,int t) {
				index=i,cost=c,target=t;
			}
			bool operator<(const node &tar)const {
				return cost<tar.cost;
			}
			int index,cost,target;
	};

	int getsize(const vector<int> &a) {
		int cnt=0;
		for(int i=0; i<a.size(); i++)
			if(a[i]!=-1)
				cnt++;
		return cnt;
	}

	void solve() {
		scanf("%d",&n);
		ai.clear();
		bi.clear();
		ci.clear();
		for(int i=0; i<n; i++) {
			scanf("%d%d%d",a+i,b+i,c+i);
			int maxn=max(a[i],b[i],c[i]);
			if(maxn==a[i])
				ai.push_back(i);
			else if(maxn==b[i])
				bi.push_back(i);
			else
				ci.push_back(i);
		}
		if(ai.size()>(n>>1)) {
			vector<node> v;
			for(int i=0; i<ai.size(); i++) {
				if(ai[i]==-1)
					continue;
				if(a[ai[i]]-b[ai[i]] <= a[ai[i]]-c[ai[i]])
					v.push_back(node(i,a[ai[i]]-b[ai[i]],2));
				else
					v.push_back(node(i,a[ai[i]]-c[ai[i]],3));
			}
			sort(v.begin(),v.end());
			for(int i=0; i<ai.size()-(n>>1); i++) {
				if(v[i].target==2)
					bi.push_back(ai[v[i].index]);
				else
					ci.push_back(ai[v[i].index]);
				ai[v[i].index]=-1;
			}
			for(int i=ai.size()-1; i>=0; i--)
				if(ai[i]==-1)
					ai.erase(ai.begin()+i);
			//fprintf(stderr,"bad a\n");
		}
		if(bi.size()>(n>>1)) {
			vector<node> v;
			for(int i=0; i<bi.size(); i++) {
				if(bi[i]==-1)
					continue;
				//fprintf(stderr,"throwing %d %d, costa=%d, costc=%d\n",i,bi[i],b[bi[i]]-a[bi[i]],b[bi[i]]-c[bi[i]]);
				if(b[bi[i]]-c[bi[i]] <= b[bi[i]]-a[bi[i]])
					v.push_back(node(i,b[bi[i]]-c[bi[i]],3));
				else
					v.push_back(node(i,b[bi[i]]-a[bi[i]],1));
			}
//		for(int x:bi)
//			fprintf(stderr,"%d ",x);
//		fprintf(stderr,"\n");
			sort(v.begin(),v.end());
//		for(int x:bi)
//			fprintf(stderr,"%d ",x);
//		fprintf(stderr,"\n");
			for(int i=0; i<bi.size()-(n>>1); i++) {
				//fprintf(stderr,"accepting %d %d, cost=%d\n",v[i].index,bi[v[i].index],v[i].cost);
				if(v[i].target==1)
					ai.push_back(bi[v[i].index]);
				else
					ci.push_back(bi[v[i].index]);
				bi[v[i].index]=-1;
			}
			for(int i=bi.size()-1; i>=0; i--)
				if(bi[i]==-1)
					bi.erase(bi.begin()+i);
			//fprintf(stderr,"bad b\n");
		}
		if(ci.size()>(n>>1)) {
			vector<node> v;
			for(int i=0; i<ci.size(); i++) {
				if(ci[i]==-1)
					continue;
				if(c[ci[i]]-b[ci[i]] <= c[ci[i]]-a[ci[i]])
					v.push_back(node(i,c[ci[i]]-b[ci[i]],2));
				else
					v.push_back(node(i,c[ci[i]]-a[ci[i]],1));
			}
			sort(v.begin(),v.end());
			for(int i=0; i<ci.size()-(n>>1); i++) {
				if(v[i].target==2)
					bi.push_back(ci[v[i].index]);
				else
					ai.push_back(ci[v[i].index]);
				ci[v[i].index]=-1;
			}
			for(int i=ci.size()-1; i>=0; i--)
				if(ci[i]==-1)
					ci.erase(ci.begin()+i);
			//fprintf(stderr,"bad c\n");
		}

//	if(ai.size()>(n>>1) || bi.size()>(n>>1) || ci.size()>(n>>1))
//		fprintf(stderr,"bad!!!");
//		for(int i=0; i<ai.size(); i++)
//			fprintf(stderr,"%d ",ai[i]);
//		fprintf(stderr,"\n");
//		for(int i=0; i<bi.size(); i++)
//			fprintf(stderr,"%d ",bi[i]);
//		fprintf(stderr,"\n");
//		for(int i=0; i<ci.size(); i++)
//			fprintf(stderr,"%d ",ci[i]);
//		fprintf(stderr,"\n");

		int64 sum=0;
		for(int i=0; i<ai.size(); i++)
			if(ai[i]!=-1)
				sum+=a[ai[i]];
		for(int i=0; i<bi.size(); i++)
			if(bi[i]!=-1)
				sum+=b[bi[i]];
		for(int i=0; i<ci.size(); i++)
			if(ci[i]!=-1)
				sum+=c[ci[i]];
		printf("%lld\n",sum);
	}

}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--) club::solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

