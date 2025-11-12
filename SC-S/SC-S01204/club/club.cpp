#include<bits/stdc++.h>
//#define ll long long 

using namespace std;
int n;
int t;

struct user{
	int a[3];
}r[100005];

int dfs(int der,int sum,int as,int bs,int cs){
	if(cs>n/2||bs>n/2||as>n/2){return 0;}
	if(der==n)return sum;
	return max(dfs(der+1,sum+r[der].a[1],as+1,bs,cs),max(dfs(der+1,sum+r[der].a[2],as,bs+1,cs),dfs(der+1,sum+r[der].a[3],as,bs,cs+1)));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&r[i].a[1],&r[i].a[2],&r[i].a[3]);
		}
		printf("%d\n",dfs(0,0,0,0,0));
	}
	return 0;
} 
//114514,114,514mr.beast