#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int N=1e5+5;
int t,n;
struct node{
	int val,id;
}a[N][4];
PII p[4];
int c[N],d[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		memset(c,0,sizeof c);
		memset(d,0,sizeof d);
		vector<int> vec[4];
		int s=0,tot=0;
		ll res=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&p[1].first,&p[2].first,&p[3].first);
			p[1].second=1,p[2].second=2,p[3].second=3;
			sort(p+1,p+3+1);
			for(int j=1;j<=3;j++){
				a[i][j].val=p[4-j].first;
				a[i][j].id=p[4-j].second;
			}
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=3;j++){
//				printf("%d ",a[i][j].val);
//			} 
//			puts("");
//		}
		for(int i=1;i<=n;i++){
			vec[a[i][1].id].push_back(i);
			res+=a[i][1].val;
		}
		for(int i=1;i<=3;i++){
			if(vec[i].size()>n/2){
				s=i;
				break;
			}
		}
		if(s==0){
			printf("%lld\n",res);
			continue;
		}
		for(int i=0;i<vec[s].size();i++){
			int v=vec[s][i];
			c[v]=max(a[v][2].val,a[v][3].val);
			c[v]=a[v][1].val-c[v];
		}
//		for(int i=1;i<=n;i++) printf("%d ",c[i]);
//		puts("");
		for(int i=1;i<=n;i++){
			if(c[i]) d[++tot]=c[i];
		}
		sort(d+1,d+tot+1);
		int len=vec[s].size()-n/2;
		for(int i=1;i<=len;i++){
			res-=d[i];
		}
		printf("%lld\n",res);
	}
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

1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926

*/
