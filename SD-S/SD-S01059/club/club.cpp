#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#define pii pair<int,int>
using namespace std;
const int N=1e5+10;
int n;
struct node{
	int x,y,z,loca;
};
node A[N];
vector<pii>v[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		v[1].clear(),v[2].clear(),v[3].clear();
		long long ans=0;
		int cnt[10]={};
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			A[i].x=a,A[i].y=b,A[i].z=c,A[i].loca=i;
		}
		for(int i=1;i<=n;i++){
			int a=A[i].x,b=A[i].y,c=A[i].z,la=A[i].loca;
			if(a>=b&&a>=c){
				v[1].push_back({a,la});
				ans+=a;
			}
			else if(b>=a&&b>=c){
				v[2].push_back({b,la});
				ans+=b;
			}
			else{
				v[3].push_back({c,la});
				ans+=c;
			} 
		}
		priority_queue <int> q;
		if(v[1].size()>n/2){
			int t=v[1].size();
			for(int i=0;i<t;i++){
				q.push(max(A[v[1][i].second].y-A[v[1][i].second].x,A[v[1][i].second].z-A[v[1][i].second].x));
			}
			for(int i=1;i<=t-n/2;i++){
				ans+=q.top();
				q.pop();
			}
		}
		if(v[2].size()>n/2){
			int t=v[2].size();
			for(int i=0;i<t;i++){
				q.push(max(A[v[2][i].second].x-A[v[2][i].second].y,A[v[2][i].second].z-A[v[2][i].second].y));
			}
			for(int i=1;i<=t-n/2;i++){
				ans+=q.top();
				q.pop();
			}
		}if(v[3].size()>n/2){
			int t=v[3].size();
			for(int i=0;i<t;i++){
				q.push(max(A[v[3][i].second].y-A[v[3][i].second].z,A[v[3][i].second].x-A[v[3][i].second].z));
			}
			for(int i=1;i<=t-n/2;i++){
				ans+=q.top();
				q.pop();
			}
		}
		int la=1,lb=1,lc=1,Cnt=1;
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
