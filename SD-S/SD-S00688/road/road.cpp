#include <iostream>
#include <algorithm>
#include <vector>
#define SUBMITMODE 1
#define DEBU__G_ 0
#define DEBUG DEBU__G_&&!SUBMITMODE
using namespace std;
const int kxy=1000003;
int n,m,k;
int cntnode;
int c[13],a[13][kxy];
struct e {
	int u,v,w;
};
vector <e> edg;
bool cmp_edg_w(e a,e b) {
	return a.w<b.w;
}
int pare[kxy];
int getroot(int x) {
	if(pare[x]==x) return x;
	return pare[x]=getroot(pare[x]);
}
int unite(int a,int b) {
	int ar=getroot(a),br=getroot(b);
	/*if(ar<br) pare[br]=ar;
	else pare[ar]=br;*/
	pare[br]=ar;
}
/*int fakenode() {
	++
}*/

int mintree() {
	sort(edg.begin(),edg.end(),cmp_edg_w);
	int cnt_added=0,ie=0,ans=0;
	while(cnt_added!=n-1) {
		if(getroot(edg[ie].u)!=getroot(edg[ie].v)) {
			unite(edg[ie].u,edg[ie].v);
			ans+=edg[ie].w;
			++cnt_added;
			++ie;
		} else {
			++ie;
		}
	}
	return ans;
}
/*vector <e> adds;
vector <e> edg_bak;
int added_mintree() {
	edg_bak=edg;
	//if(DEBUG)
	for(auto x : adds) {
		edg.push_back(x);
	}
	int ans=mintree();
	edg=edg_bak;
	return ans;
}*/

int main_mintree() {
	for(int i=0;i<kxy;++i) {
		pare[i]=i;
	}
	cntnode=n;
	for(int i=1;i<=m;++i) {
		int u,v,w;
		cin>>u>>v>>w;
		edg.push_back({u,v,w});
	}
	bool specialA=1;
	if(k==0) specialA=0;
	for(int i=1;i<=k;++i) {
		cin>>c[i];
		if(c[i]!=0) {
			specialA=0;
		}
		for(int j=1;j<=n;++j) {
			cin>>a[i][j];
			//cout<<"j:"<<j<<',';
			if(a[i][j]!=0) {
				specialA=0;
			}
		}
		//if(DEBUG)cout<<"finish "<<i<<'\n';
	}
	//if(DEBUG) cout<<"!!!!!!!!!\n";
	if(specialA) {
		cout<<0;
		return 0;
	}
	if(1) {
		cout<<mintree();
	} else {
		/*cout<<"进入存在k状态\n";
		int ans=112425520;
		for(int i=0;i<(1<<k);++i) {
			if(DEBUG)cout<<"尝试添加伪造节点，启动种子:"<<i<<'\n';
			adds.clear();
			int aa=i,j=0,p2w=0;
			while(aa) {
				++j;
				if(DEBUG)cout<<"转换二进制 第"<<j<<"个伪造节点启动状态为:"<<aa%2<<'\n';
				if(aa%2) {
					p2w+=c[j];
					for(int k=1;k<=n;++k) {
						adds.push_back({n+j,k,a[j][k]});
						if(DEBUG)cout<<"添加伪造边:"<<n+j<<"到"<<k<<",权值:"<<a[j][k]<<'\n'; 
					}
				}
				aa/=2; 
			}
			if(DEBUG)cout<<"总计伪造节点开销:"<<p2w<<'\n';
			int pans=added_mintree();
			if(DEBUG)cout<<"结果:"<<pans+p2w<<'\n';
			ans=min(ans,pans+p2w);
		}
		cout<<ans<<'\n';*/
	}
	return 0;
}
int main() {
	//freopen("D:\\csps\\down\\road\\road3.in","r",stdin);
	if(SUBMITMODE) {
		freopen("road.in","r",stdin);
		freopen("road.out","w",stdout);
	}
	//ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	return main_mintree();
}
