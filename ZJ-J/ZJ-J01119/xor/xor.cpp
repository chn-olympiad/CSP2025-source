#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#define MOD 998244353
#define CSP_IO freopen("xor.in","r",stdin);freopen("xor.out","w",stdout);
using namespace std;
typedef pair<int,int> PII;
map<int,int>vis;
map<int,int>id_bg;
map<int,int>id_ed;
vector<PII>A;
set<int>s_bg;
set<int>s_ed;
bool cmp(PII a,PII b){
	int lena=a.second-a.first;
	int lenb=b.second-b.first;
	if(lena==lenb)return a.first<b.first;
	return lena<lenb;
}
signed main(){
	CSP_IO;
	int n,k;
	scanf("%d%d",&n,&k);
	int now=0;
	int ans=0;
	vis[0]=0;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		now=now^x;
		if(vis.find(now^k)!=vis.end()){
			A.push_back({vis[now^k]+1,i});
			id_bg[vis[now^k]+1]=i;
			id_ed[i]=vis[now^k]+1;
		}
		if(x==k)id_bg[i]=i,id_ed[i]=i,A.push_back({i,i});
		vis[now]=i;
	}
	sort(A.begin(),A.end(),cmp);
	
//	for(PII&x:A){
//		printf("%d %d\n",x.first,x.second);
//	}puts("");
//	
//	
//	return 0;
	
	
	for(PII&x:A){
		bool flag=1;
		//jian cha begin
		set<int>::iterator t=s_bg.lower_bound(x.first);
	//	if(x.first==1)printf("%d %d\n",s_bg.size(),*t);
		if(*t<=x.first&&t!=s_bg.end()&&id_bg[*t]>=x.first)flag=0;
	//	printf("check_begin:%d  ",flag);
		//jian cha end
		bool check_second=1;
		
		t=s_ed.upper_bound((x.second)-1);
		if(t!=s_ed.end()&&id_ed[*t]<=x.second)flag=0,check_second=0;
	//	printf("check_second:%d\n",check_second);
		if(!flag)continue;
		
		ans++;
		s_bg.insert(x.first);
		s_ed.insert(x.second);
	}
	printf("%d",ans);
	return 0;
}
