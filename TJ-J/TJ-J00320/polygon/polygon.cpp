#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
bool flag=true;
void dfs(int sum,int cnt,int x,int mx){
	if(x==n+1){
		if(cnt>=3&&sum>mx*2){
			ans++;
			ans%=998244353;
		}
		return ;
	}
	dfs(sum+a[x],cnt+1,x+1,max(mx,a[x]));
	dfs(sum,cnt,x+1,mx);
}
long long f(int m){
	long long s=1;
	int n2=n-m+1,d=0;
	for(int i=n;i>=m;i--){
		if(i>n2){
			s*=i;
			d++;
		}
	}
	int e=1;
	while(d--){
		s/=e;
		e++;
	}
	return s;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=false;
	}
	if(flag&&n>20){
		long long t=1;
		for(int i=4;i<=n;i++){
			t+=f(i);
			t%=998244353;
		}
		cout<<t;
		return 0;
	}
	dfs(0,0,1,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
