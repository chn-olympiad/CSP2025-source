#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#define MOD 998244353
#define CSP_IO freopen("polygon.in","r",stdin);freopen("polygon.out","w",stdout);
using namespace std;
int A[110];
struct node{
	int val;
	bool use;
	friend bool operator<(node a,node b){
		return a.val<b.val;
	}
};
multiset<node>s;
signed main(){
	CSP_IO;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&A[i]);
	sort(&A[1],&A[n+1]);
	int ans=0;
	s.insert({A[1]+A[2],1});
	s.insert({A[1],0});
	s.insert({A[2],0});
	for(int i=3;i<=n;i++){
		vector<node>V;
//		printf("i=%d:",i);
		for(set<node>::iterator it=s.begin();it!=s.end();it++){
		//	if((it->val)>=A[i])break;
			if((it->use)&&((it->val)+A[i]>2*A[i])){
				ans++;
				if(ans==MOD){
					printf("%d",ans);
					return 0;
				}
			}
			V.push_back({(it->val)+A[i],1});
	//		printf("{%d,%d,%d} ",it->val,it->use,(it->val)+A[i]>2*A[i]&&(it->use));
		}
//		puts("");
		for(int i=0;i<V.size();i++)s.insert(V[i]);
		s.insert({A[i],0});
	//	printf("%d\n",s.size());
//		printf("%d\n",ans);
	}
	printf("%d",ans);
	return 0;
}
