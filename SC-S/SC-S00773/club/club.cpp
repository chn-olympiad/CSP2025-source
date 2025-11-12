#include<bits/stdc++.h>
using namespace std;

const int N=1e5;
struct member{
	int c1,c2,c3;
}c[N+10];
int n,c1m,c2m,c3m,ans;

void dfs(int mem,int num){
	if(mem>n){
		ans=max(ans,num);
		return;
	}
	if(c1m<n/2){
		c1m++;
		num+=c[mem].c1;
		//cout<<mem<<" "<<c1m<<" "<<c2m<<" "<<c3m<<" "<<num<<endl;
		dfs(mem+1,num);
		c1m--;
		num-=c[mem].c1;
	}
	if(c2m<n/2){
		c2m++;
		num+=c[mem].c2;
		//cout<<mem<<" "<<c1m<<" "<<c2m<<" "<<c3m<<" "<<num<<endl;
		dfs(mem+1,num);
		c2m--;
		num-=c[mem].c2;
	}
	if(c3m<n/2){
		c3m++;
		num+=c[mem].c3;
		//cout<<mem<<" "<<c1m<<" "<<c2m<<" "<<c3m<<" "<<num<<endl;
		dfs(mem+1,num);
		c3m--;
		num-=c[mem].c3;
	}
}

int main(){

	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1; i<=n; i++){
			cin>>c[i].c1>>c[i].c2>>c[i].c3;
		};
		
		ans=0,c1m=0,c2m=0,c3m=0;
		dfs(1,0);
		
		cout<<ans<<endl;
	}

	return 0;
}
//我是搜索仙人（ 
//如果你看到这行字，就证明我DP没想出来
//I am stupid
//往好了想这题搜出来的分至少比今年Alpine得的多（截至巴西站前） 