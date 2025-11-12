#include <bits/stdc++.h>
using namespace std;

int n,m;
int a1;
int a[105];
int s;
int c,d;

bool cmp(int x,int y){
	return x>y;
}

void dfs(int x,int y,int z){
	if(z==0){
		cout<<x<<' '<<y;
		return;
	}
	if(x%2==1){
		if(y==n){
			dfs(x+1,y,z-1);
			return;
		}
		else{
			dfs(x,y+1,z-1);
			return;
		}
	}
	else{
		if(y==1){
			dfs(x+1,y,z-1);
			return;
		}
		else{
			dfs(x,y-1,z-1);
			return;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	a1=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==a1){
			s=i;
			break;
		}
	}
	dfs(1,1,s-1);
	return 0;
}
