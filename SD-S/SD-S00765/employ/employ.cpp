#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,m,a[1000],b[1000],cnt=0;
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=i;
	}
	do{
		int qian=0,ren=0;
		for(int i=0;i<n;i++){
			if(s[i]=='0'||qian>=a[b[i+1]]){
				qian++;
			}else{
				ren++;
			}
		}
		if(ren>=m) cnt+=1,cnt%mod;
	}while(next_permutation(b+1,b+n+1));
	cout<<cnt%mod;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
