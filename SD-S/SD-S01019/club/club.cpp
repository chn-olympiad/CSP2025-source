#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int siz;
const int xx=1e5+5;
struct node{
	int a,b,c;
}z[xx];
int maxn;
vector<int> num1;
void dfs(int u,int cnt_a,int cnt_b,int cnt_c,int sum){
	if(u==n+1){
		maxn=max(sum,maxn);
		return ;
	}
	if(cnt_a<siz){
		sum=sum+z[u].a;
		dfs(u+1,cnt_a+1,cnt_b,cnt_c,sum);
		sum=sum-z[u].a;
	}
	if(cnt_b<siz){
		sum=sum+z[u].b;
		dfs(u+1,cnt_a,cnt_b+1,cnt_c,sum);
		sum=sum-z[u].b;
	}
	if(cnt_c<siz){
		sum=sum+z[u].c;
		dfs(u+1,cnt_a,cnt_b,cnt_c+1,sum);
		sum=sum-z[u].c;
	}
	return ;
}
bool pd1=true;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		siz=n/2;
		maxn=-1;
		for(int i=1;i<=n;i++){
			cin>>z[i].a;
			cin>>z[i].b;
			cin>>z[i].c;
			num1.push_back(z[i].a);
			if(z[i].b!=0){
				pd1=false;
			}
		}
		if(pd1){
			sort(num1.begin(),num1.end());
			int ans=0;
			for(int i=0;i<siz;i++){
				ans+=num1[i];
			}
			cout<<ans<<"\n";
			continue;
		}
		dfs(1,0,0,0,0);
		cout<<maxn<<"\n"; 
	}
}
//25pts
