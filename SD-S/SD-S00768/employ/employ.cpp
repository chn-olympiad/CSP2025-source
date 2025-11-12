#include<bits/stdc++.h>
using namespace std;
int n,m,a[10000],d[1000];
string s;
long long mod=998244353;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		ans=ans*i;
		d[i]=i;
	}
	long long ans1=0;
	for(int i=1;i<=ans;i++){
		int cnt=0,op=0;
		for(int j=1;j<=n;j++){
			if(s[j]=='0'){
				cnt++;
			}
			else{
				if(a[d[j]]>cnt){
					op++;
				}
				else{
					cnt++;
				}
			}
		}
//		for(int j=1;j<=n;j++){
//				cout<<d[j]<<" ";
//			}
//			cout<<endl;
//		cout<<op;
		if(op>=m){
			ans1++;
			ans1%=mod;
		}
		next_permutation(d+1,d+1+n);
	}
	cout<<ans1%mod;
	return 0;
}

