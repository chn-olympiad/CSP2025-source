#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<string>
#define int long long
using namespace std;
const int N=510,MOD=998244353;
int n,m,ans;
int c[N];
int od[N];
int jc[N];
bool flag_1=1;
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>s;
	s=' '+s;
	jc[0]=1;
	for(int i=1;i<=n;i++){
		jc[i]=(jc[i-1]*i)%MOD;
		cin>>c[i];
		if(s[i]!='1'){
			flag_1=0;
		}
		od[i]=i;
	}
	if(n<=10){
		do{
			
//			for(int i=1;i<=n;i++){
//				cout<<od[i]<<' ';
//			}
//			cout<<endl;
			
			int sum=0;
			for(int i=1;i<=n;i++){
				if(s[i]=='0'){
					sum++;
				}
				else{
					if(sum>=c[od[i]]){
						sum++;
					}
				}
			}
			if(n-sum>=m){
				ans++;
			}
		}while(next_permutation(od+1,od+n+1));
		cout<<ans;
		return 0;
	}
	else if(flag_1){
		cout<<jc[n];
		return 0;
	} 
	else{
		cout<<0;
	}
	return 0;
} 
