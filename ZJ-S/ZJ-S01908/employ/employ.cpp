#include<bits/stdc++.h>
#define ll long long
using namespace std;
int ans,n,m,a1=1,a2=1,res=1,a[114514],flag[114514],b[114514];
const ll p=998244353;
char st[1114514];
bool check(){
	int fail,sum;
	fail=0;
	sum=0;
	for(int i=1;i<=n;i++){
		if(st[i-1]=='0'||fail>=b[a[i]]){
			fail++;
		}
		else{
			fail=0;
			sum++;
		}
	}
	return sum>=m;
}
void dfs(ll d){
	if(d>n){
		if(check()){
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(flag[i]==0){
			a[d]=i;
			flag[i]=1;
			dfs(d+1);
			flag[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	getchar();
	scanf("%s",st);
	getchar();
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		if(b[i]!=0){
			ans++;
		}
	}
	if(n==m){
		if(ans!=n){
			cout<<0;
			return 0;
		}
		for(int i=1;i<=n;i++){
			if(st[i-1]=='0'){
				cout<<0;
				return 0;
			}
			res*=i;
			res%=p;
		}
		cout<<res;
		return 0;
	}
	ans=0;
	dfs(1);
	cout<<ans;
	return 0;
}