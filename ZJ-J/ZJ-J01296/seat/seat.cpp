#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100011],t=1;
void dfs(int x,int y,int w){
	if(w==t){
		cout<<x<<" "<<y;		
	}else{
		if(x%2==1){
			if(y<n){
				dfs(x,y+1,w+1);
			}else{
				dfs(x+1,y,w+1);
			}
		}else{
			if(y==1){
				dfs(x+1,y,w+1);
			}else{
				dfs(x,y-1,w+1);
			}
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			t++;
		}
	}
	dfs(1,1,1);
	return 0;
}
