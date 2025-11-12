#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
struct node{
	int a;
	int b;
	int c;
};
int n;
vector<node>A;
int dfs(int x,int a,int b,int c,int s){
	if(a>n/2||b>n/2||c>n/2)return -1;
	if(x==n)return s;
	return max(dfs(x+1,a+1,b,c,s+A[x].a),max(dfs(x+1,a,b+1,c,s+A[x].b),dfs(x+1,a,b,c+1,s+A[x].c)));
}
bool cmp(node x,node y){
	return x.a>y.a;
}
bool cmp2(node x,node y){
	return x.a-x.b<y.a-y.b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		A.clear();
		cin>>n;
		bool flagb=1,flagc=1;
		for(int i=0;i<n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			if(b!=0)flagb=0;
			if(c!=0)flagc=0;
			A.push_back({a,b,c});
		}
		if(n<=20){
			cout<<dfs(0,0,0,0,0)<<"\n";
		}
		else if(flagb&&flagc){
			sort(A.begin(),A.end(),cmp);
			int ans=0;
			for(int i=0;i<n/2;i++)ans+=max(A[i].a,0);
			cout<<ans<<"\n";
		}
		else if(flagc){
			sort(A.begin(),A.end(),cmp2);
			int ans=0;
			for(int i=0;i<n/2;i++)ans+=max(A[i].b,0);
			for(int i=n/2;i<n;i++)ans+=max(A[i].a,0);
			cout<<ans<<"\n";
		}
	}
	return 0;
}