#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define LL long long
#define ULL unsigned long long
#define PII pair<int,int>
map<set<int> ,bool> vis;
int a[5005],n;
const int mod=998244353;
ULL C(int a,int b){
	ULL res1=1;
	ULL res2=1;
	for(int i=b;i>=b-a+1;i--){
		res1=(res1*i%mod);
	}
	for(int i=1;i<=a;i++){
		res2=(res2*i%mod);
	}
	return res1/res2;
}
LL ans=0;
void dfs(int nowsum,int nowmax,int nowcnt,int step,set<int> s){
	if(nowcnt>=3){
		if(nowsum>2*nowmax&&vis[s]!=1){
			vis[s]=1;
			ans=((ans+1)%mod);
		}
	}
	if(step>=n+1){
		return ;
	}
	dfs(nowsum,nowmax,nowcnt,step+1,s);
	s.insert(step);
	dfs(nowsum+a[step],max(nowmax,a[step]),nowcnt+1,step+1,s);
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
//	cout<<*max_element(a+1,a+1+n)<<' '<<*min_element(a+1,a+1+n)<<endl;
	if(*max_element(a+1,a+1+n)==*min_element(a+1,a+1+n)){
		for(int i=3;i<=n;i++){
			if(i>n/2){
				ans=(ans+C(n-i,n)%mod)%mod;
			}else{
				ans=(ans+C(i,n)%mod)%mod;
			}
		}
		cout<<ans%mod<<endl;
		return 0;
	}else{
		set<int> s1;
		dfs(0,0,0,1,s1);
		cout<<ans<<endl;
		return 0;
	}
	return 0;
}
/*
10
1 1 1 1 1 1 1 1 1 1
968

5
1 2 3 4 5
9

5
2 2 3 8 10
6
*/

