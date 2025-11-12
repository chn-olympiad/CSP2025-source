#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define maxn 1000006
using namespace std;
ll a[maxn][5],ans=0,n;
int h[5]= {0,0,0,0,0};
int calc(int x){
	int sum=0,cnt=0;
	for(int i=x;i<=n;i++){
		sum+=max(a[i][1],max(a[i][2],a[i][3]));
	}
	return sum;
}
void dfs(ll sum,int lst) {
	if(sum>ans) {
		ans=sum;
	}
	for(int j=1; j<=2; j++) {
		if(h[j]<n/2&&sum+calc(lst)>ans) {
			h[j]++;
			dfs(sum+a[lst][j],lst+1);
			h[j]--;
		}
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--) {
		memset(h,0,sizeof(h));
		ans=0;
		cin>>n;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=3; j++) {
				cin>>a[i][j];
				sort(a[i]+1,a[i]+4);
			}
		}
		dfs(0,1);
		cout<<ans<<endl;
	}
	return 0;
}
