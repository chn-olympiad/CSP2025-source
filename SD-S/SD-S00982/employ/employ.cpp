#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10;
const int M = 2*N;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("empoly.out","w",stdout);
	int n,m,c[N];
	string a;
	scanf("%lld%lld",&n,&m);
	cin>>a;
	for(int i = 1;i<=n;i++){
		scanf("%lld",&c[i]);
	}
	if(m==1){
		int f = 1;
		for(int i =1;i<a.size();i++){
			if(a[i]=='0'){
				f = 0;
			}
		}
		if(f){
			cout<<0;
			return 0;
		}
		int ans = 1;
		for(int i = 1;i<=n;i++){
			ans = ans*i%998244353;
		}
		cout<<ans;
	}
	if(m==n){
		cout<<0;
	}
	return 0;
} 
