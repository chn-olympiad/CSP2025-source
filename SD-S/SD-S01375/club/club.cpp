#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5;
int t;
int n;
struct code{
	int a,b,c;
	bool operator < (code &b){
		return a>b.a;
	}
}student[N];
int ans;
void dfs(int x,int sum,int a,int b,int c){
	if(x>n){
		ans=max(ans,sum);
		return ;
	}
	if(a<n/2)dfs(x+1,sum+student[x].a,a+1,b,c);
	if(b<n/2)dfs(x+1,sum+student[x].b,a,b+1,c);
	if(c<n/2)dfs(x+1,sum+student[x].c,a,b,c+1);
	cout<<x<<" "<<sum<<" "<<a<<" "<<b<<" "<<c<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		bool _2=1,_3=1; 
		for(int i=1;i<=n;i++){
			cin>>student[i].a>>student[i].b>>student[i].c;
			if(student[i].b!=0){
				_2=0;
			}
			if(student[i].c!=0){
				_3=0;
			}
		}
		if(_3&&_2){
			sort(student+1,student+n+1);
			int sum=0;
			for(int i=1;i<=n/2;i++){
				sum+=student[i].a;
			}
			cout<<sum<<"\n";
			continue;
		}
		else{
			ans=0;
			dfs(1,0,0,0,0);
			cout<<ans<<"\n";
//			for() 
		}
//		for(int i=1;i<=n;i++){
//			cout<<student[i].a<<" ";
//		}

	}
	return 0;
} 
