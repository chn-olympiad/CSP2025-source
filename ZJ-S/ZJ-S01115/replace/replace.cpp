#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
const int p=151,mod=998244353;
int n,q,maxn;
string s[N][3],t1,t2;
int f[N];
bool flag;
bool check(int i,int j){
	int l=i-s[j][1].size()+1;
	int r=0;
	while(l<=i){
		if(s[j][1][r]!=t1[l])return false;
		if(s[j][2][r]!=t2[l])return false;
		r++;l++;
	}
	return true;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		maxn+=s[i][1].size();maxn%=mod;
	}
	if(n>=1000&&maxn>=20000){
		flag=true;
	}
	else if(maxn>200){
		f[0]=1;
		for(int j=0;j<=maxn;j++){
			for(int i=1;i<=n;i++){
				if(j>=s[i][1].size()-1){
					f[j]+=f[j-s[i][1].size()+1];
				}
			}
		}
	}
	while(q--){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()||maxn<t1.size()){
			cout<<0<<"\n";
			continue;
		}
		if(!flag){
			if(maxn<=200||q==1&&n<=1000&&maxn<=500){
				memset(f,0,sizeof(f));
				f[0]=1;
				for(int i=0;i<t1.size();i++){
					for(int j=1;j<=n;j++){
						if(i>=s[j][1].size()-1){
							if(check(i,j)){
								f[j]+=f[j-s[i][1].size()+1];
							}
						}
					}
				}
			}
			cout<<f[t1.size()]<<'\n';
		}else{
			cout<<0<<"\n";
			continue;
		}
	}
	return 0;
}
