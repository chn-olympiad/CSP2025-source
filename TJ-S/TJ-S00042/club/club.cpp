#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> r[100005];
int t,n;
int a,b,c;
int ans=-0x3f3f3f;
void dfs(int i,int w){
	//cout<<2;
	if(i>n){
		ans=max(w,ans);
		return ;
	}
	if(a+1<=n/2){
		
		a++;
		//cout<<'a'<<" "<<i<<endl;
		dfs(i+1,w+r[i][0]);
		a--;
	}
	if(b+1<=n/2){
		
		b++;
		//cout<<'b'<<" "<<i<<endl;
		dfs(i+1,w+r[i][1]);
		b--;
	}
	if(c+1<=n/2){
		
		c++;
		//cout<<'c'<<" "<<i<<endl;
		dfs(i+1,w+r[i][2]);
		c--;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
//		priority_queue<int> a;
//		priority_queue<int> b;
//		priority_queue<int> c;
		cin>>n;
		for(int i=1;i<=n;i++){
			r[i].clear();
			int a1,b1,c1;
			cin>>a1>>b1>>c1;
			r[i].push_back(a1);
			r[i].push_back(b1);
			r[i].push_back(c1);
		}
		a=0,b=0,c=0;
		ans=0;
		//cout<<1;
		dfs(1,0);
		cout<<ans<<endl;
	}
	
	return 0;
} 
