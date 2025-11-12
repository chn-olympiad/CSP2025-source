#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int a[N][5];
int n,k;
int dfs(int now,int x,int y) {
	int z = now - x - y;
	if(x > k || y > k || z > k) return -1e9;
	if(now > n) {
		return 0;
	}
	int ans = 0;
	for(int i = 1;i <= 3;i++) {
		if(i==1) {
			ans = max(ans,dfs(now+1,x+1,y)+a[now][i]);
		}else if(i== 2){
			ans = max(ans,dfs(now+1,x,y+1)+a[now][i]);
		}else{
			ans = max(ans,dfs(now+1,x,y)+a[now][i]);
		}
	}
	return ans;
}


int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) {
		
		cin>>n;
		k = n/2;
		int ans = 0;
		for(int i =1;i <= n;i++) {
			for(int j = 1;j <= 3;j++) {
				cin>>a[i][j];
			}
		}
		cout<<dfs(1,0,0)<<endl;
	}
	
	return 0;
}