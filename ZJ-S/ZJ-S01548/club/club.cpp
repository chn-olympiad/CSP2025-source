#include<bits/stdc++.h>
using namespace std;
int T,n,A[200001],B[200001],C[200001];
long long cnt=0;
void dfs(int p,int a,int b,int c,unsigned long long ans) {
	if(p>n) {
		if(ans>cnt) {
			//cout<<"@\n";
			cnt=ans;
		}
		return;
	}
	if(a+1<=n/2) {
		dfs(p+1,a+1,b,c,ans+A[p]);
		//printf("A!%d %d %d %d %d\n",p,a+1,b,c,ans+A[p]);
	}
	if(b+1<=n/2) {
		dfs(p+1,a,b+1,c,ans+B[p]);
		//printf("B!%d %d %d %d %d\n",p,a,b+1,c,ans+B[p]);
	}
	if(c+1<=n/2) {
		dfs(p+1,a,b,c+1,ans+C[p]);
		//printf("C!%d %d %d %d %d\n",p,a,b,c+1,ans+C[p]);
	}
	return;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) {
		cin>>n;
		cnt=0;
		for(int i=1; i<=n; i++)cin>>A[i]>>B[i]>>C[i];
		dfs(1,0,0,0,0);
		cout<<cnt<<endl;
	}
}
