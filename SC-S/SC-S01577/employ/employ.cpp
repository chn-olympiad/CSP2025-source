#include<bits/stdc++.h>
using namespace std;
const int N=505;
int a[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	string s;cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=10){
		int cnt=0,p[15];
		for(int i=1;i<=n;i++){
			p[i]=i;
		}
		do{
			int tot=0,succ=0;
			for(int i=1;i<=n;i++){
				if(tot>=a[p[i]]||s[i-1]=='0'){
					tot++;
				}else{
					succ++;
				}
			}
			if(succ>=m)cnt++;
		}while(next_permutation(p+1,p+n+1));
		cout<<cnt<<endl;return 0;
	}
	if(m==n){
		bool f=1;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0'){
				f=0;break;
			}
			if(a[i]==0){
				f=0;break;
			}
		}
		if(f==0)cout<<0<<endl;
		else{
			long long mod=998244353,mul=1;
			for(int i=1;i<=n;i++){
				mul=mul*i%mod;
			}cout<<mul<<endl;
		}
	}
	/*
	10 5
1101111011
6 0 4 2 1 2 5 4 3 3

3 2
101
1 1 2

*/
}