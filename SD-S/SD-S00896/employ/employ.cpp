#include<bits/stdc++.h>
using namespace std;
const int maxn=505,mod=998244353;
int n,m,c[maxn],f[19][1<<18];
string s;
vector<int> ve[19];
int df(int a,int mk){
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0);
	cin>>n>>m;
	for(int i = 0;i<(1<<n);i++){
		int summ=0;
		for(int j = 0;j<n;j++){
			if(i&(1<<j))summ++;
		}
		ve[summ].push_back(i);
	}
	cin>>s;
	s=" "+s; 
	for(int i = 1;i<=n;i++){
		cin>>c[i];
	}
	if(n<=18){
		f[0][0]=1;
		for(int a = 1;a<=n;a++){
			for(int mk:ve[a-1]){
				if(s[a]=='1'){
					for(int i = 1;i<=n;i++){
						if(((1<<i-1)&mk)==0){
							for(int j = 0;j<c[i];j++){
								f[j][mk|(1<<i-1)]+=f[j][mk];
								f[j][mk|(1<<i-1)]%=mod;
							}
							for(int j = c[i];j<n;j++){
								f[j+1][mk|(1<<i-1)]+=f[j][mk];
								f[j+1][mk|(1<<i-1)]%=mod;
							}
//							cout<<f[0][mk];
						}
					}
				}
				else{
					for(int i = 1;i<=n;i++){
						if(((1<<i-1)&mk)==0){
							for(int j = 0;j<n;j++){
								f[j+1][mk|(1<<i-1)]+=f[j][mk];
								f[j+1][mk|(1<<i-1)]%=mod;
							}
						}
					}
				}
			}
		}
		int anss=0;
		for(int i = 0;i<=n-m;i++){
			anss=(anss+f[i][(1<<n)-1])%mod;
//			cout<<f[i][(1<<n)-1]<<" ";
		}
		cout<<anss;
	}
	
	return 0;
}

