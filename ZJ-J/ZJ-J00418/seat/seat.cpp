#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+7;

int n,m;
int a[201][201];
int b[20010];
int id;
//seth=0:up  ;  seth=1:down
void dfs(int x,int y,int seth,int pos){
	if(b[pos]==id){
		cout<<y<<" "<<x<<"\n";
		return ;
	}
	if(seth){
		if(x<n) dfs(x+1,y,seth,pos+1);
		else dfs(x,y+1,0,pos+1);
	}
	else{
		if(x>1) dfs(x-1,y,seth,pos+1);
		else dfs(x,y+1,1,pos+1);
	}
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>b[i];
	id=b[1];
	sort(b+1,b+n*m+1,greater<int>());
	
	dfs(1,1,1,1);

	return 0;
}
