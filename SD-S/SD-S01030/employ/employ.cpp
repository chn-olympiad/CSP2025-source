#include<bits/stdc++.h>
using namespace std;
const int MAXN=510;
int a[MAXN],c[MAXN];
bool pass[MAXN];
const int MOD=998244353;
long long fac[MAXN],inv[MAXN];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	string s;
	cin>>n>>m;
	bool mm11=1,mmnn=1,A=1;
	if(m!=1)mm11=0;
	if(m!=n)mmnn=0;
	for(int i=1;i<=n;i++){
		a[i]=i;
	}
	cin>>s;
	for(int i=1;i<=n;i++){
		scanf("%d",c+i);
	}
	for(int i=0;i<n;i++){
		if(s[i]=='1')pass[i+1]=1;
	}
	if(mm11){
		bool flag=0;
		for(int i=1;i<=n;i++){
			if(pass[i]==1){
				flag=1;
				break;
			}
		}
		sort(c+1,c+n+1,greater<int>());
		if(flag==0){
			cout<<0<<endl;
		}else{
			int fail=0,sum=0;
			for(int i=1;i<=n;i++){
				if(pass[i]==1){
					if(0);
				}
			}
		}
	}else if(mmnn){
		for(int i=1;i<=n;i++){
			if(pass[i]==0||c[i]==0){
				cout<<0<<endl;
				return 0;
			}
		}
		fac[1]=1;
		for(int i=2;i<=n;i++){
			fac[i]=1ll*fac[i-1]*i%MOD;
		}
		cout<<fac[n]%MOD<<endl;
	}else if(A&&0){
	}else{
		int ans=0;
		do{
			int sum=0,fail=0,flag=0;
			for(int j=1;j<=n;j++){
				int i=a[j];
				if(fail>=c[i]){
					fail++;
					continue;
				}
				if(pass[j]){
					sum++;
					if(sum>=m){
						flag=1;
						break;
					}
				}else{
					fail++;
				}
			}
			if(flag==1)ans++;
		}while(next_permutation(a+1,a+n+1));
		cout<<ans<<endl;
	}
	return 0;
}

/*

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/
