#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
int t,n; 
unsigned long long ans;
bool A=1,B=1,C=1;
struct node{
	int l,m,r;
}a[N];
void dfs(int now,unsigned long long sum,int x,int y,int z){
	if(now==n){
		if(sum>ans) ans=sum;
		return;
	}
	if(x<n/2&&!A) dfs(now+1,sum+a[now].l,x+1,y,z);
	if(y<n/2&&!B) dfs(now+1,sum+a[now].m,x,y+1,z);
	if(z<n/2&&!C) dfs(now+1,sum+a[now].r,x,y,z+1);
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while(t--){
	    ans=0;
		cin >> n;
		for(int i=0;i<n;i++){
			cin >> a[i].l;
			cin >> a[i].m;
			cin >> a[i].r;
			if(a[i].l) A=0;
			if(a[i].m) B=0;
			if(a[i].r) C=0;
		}
		dfs(0,0,0,0,0);
		cout << ans << "\n";
	}
	return 0;
} 
