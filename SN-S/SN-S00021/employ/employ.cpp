#include<bits/stdc++.h>
using namespace std;
long long ans=0;
int geshu=0;
const int mod=998244353; 
int a[520],c[520];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	string s;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		a[i]=s[i-1]-'0';
		if(a[i]) geshu++;
	}
	if(geshu<m){
		cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i]; 
	}
	sort(a+1,a+1+n);
	do{
		int num=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(num>=c[i]){
				num++;
			}else{
				if(a[i]==0){
					num++;
				}else{
					cnt++;
				}
			}
		}
		if(cnt>=m) ans++;
		ans%=mod;
	}while(next_permutation(a+1,a+1+n));
	cout<<ans<<endl;
	return 0;
} 
//111abab
