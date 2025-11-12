#include<bits/stdc++.h>
using namespace std;
const int N=5009,M=998244353;
int a[N];
int n;
bool st[N];
int ans[N];
long long cnt=0;
void dfs(int c,int x,int sum){
	if(c<1){
		if(sum){
			cnt++;
			cnt%=M;
		}
		return ;
	} 
	for(int i=x;i<=n;i++){
		if(st[i]) continue;
		st[i]=1;
		if(c==1) sum-=a[i]*2;
		else sum+=a[i];
		ans[c]=a[i];
		dfs(c-1,i,sum);
		st[i]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n); 
	for(int i=3;i<=n;i++){
		dfs(i,1,0);
	}
	cout<<cnt%M;
	return 0;
}
