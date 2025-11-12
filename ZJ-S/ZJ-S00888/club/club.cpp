#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;
struct node{
	int x,id;
}q[5];
int a[N];
int b[N];
vector<int>c[5];
bool cmp(node a,node b){
	return a.x>b.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&q[j].x);
				q[j].id=j;
			}
			sort(q+1,q+1+3,cmp);
			c[q[1].id].push_back(i);
			a[i]=q[1].x-q[2].x;
			ans+=q[1].x;
		}
		for(int i=1;i<=3;i++){
			if(c[i].size()>n/2){
				for(int j=0;j<c[i].size();j++){
					b[j+1]=a[c[i][j]];
				}
				sort(b+1,b+1+c[i].size());
				for(int j=1;j<=c[i].size()-n/2;j++){
					ans-=b[j];
				}
			}
			c[i].clear();
		}
		printf("%d \n",ans);
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
*/