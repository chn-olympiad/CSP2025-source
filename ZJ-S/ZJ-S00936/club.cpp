#include <bits/stdc++.h>
using namespace std;
long long sum;
struct stu{
	int b,c,d;
}a[100010];
void dfs(int n,int k,long long step,int bb,int cc,int dd){
	if(k==n+1){
		sum=max(sum,step);
		return;
	}
	if(bb<=n/2-1){
		dfs(n,k+1,step+a[k].b,bb+1,cc,dd);
	}
	if(cc<=n/2-1){
		dfs(n,k+1,step+a[k].c,bb,cc+1,dd);
	}
	if(dd<=n/2-1){
		dfs(n,k+1,step+a[k].d,bb,cc,dd+1);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		sum=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].b>>a[i].c>>a[i].d;
		}
		dfs(n,1,0,0,0,0);
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);

	return 0;
}
