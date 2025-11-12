#include<bits/stdc++.h>
#define int long long
#define bug cout<<"songge888"<<'\n';
using namespace std;
const int mod=998244353;
int n,m;
string s;
int fl=0;
int id[11];
int c[2222];
int f[2222][2];
int ans;
int cc;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	cin>>s;
	for(char c:s){
		if(c=='0'){
			fl=1;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		
	} 
	if(!fl){// 都能通过面试 
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
	}
	else if(n<=10){
		for(int i=1;i<=n;i++){
			id[i]=i;	
		}
		do{
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(cnt>=c[id[i]]){
					cnt++;
				}
				else if(s[i-1]=='0'){
					cnt++;
				}
			}
			int num=n-cnt;
			if(num>=m){
				ans++;
			}
			ans%=mod;
		}while(next_permutation(id+1,id+1+n));
	} 
	cout<<ans;
	return 0;
}

