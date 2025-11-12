#include <bits/stdc++.h>
using namespace std;

const int N=1000;
int t,n,ans;
int ca,cb,cc;
struct txt{
	int a,b,c;
};

txt stu[N];

void dfs(int x,int cnt){
	if(x==n){
		ans=max(cnt,ans);
		return;
	}
	if(ca<n/2){
		ca++;
		dfs(x+1,cnt+stu[x+1].a);
		ca--;
	}
	if(cb<n/2){
		cb++;
		dfs(x+1,cnt+stu[x+1].b);
		cb--;
	}
	if(cc<n/2){
		cc++;
		dfs(x+1,cnt+stu[x+1].c);
		cc--;
	}	
}


int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
		
		ans=-0x3f3f3f;
		ca=0;
		cb=0;
		cc=0;
		
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>stu[i].a>>stu[i].b>>stu[i].c;
		}
		dfs(0,0);
		cout<<ans<<endl;
	}
}
