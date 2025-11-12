#include<bits/stdc++.h>
using namespace std;
int n,m,a[1278],p,ans=1;
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++){
		cin>>a[i];
		ans%=998244353;
		ans*=a[i];
	}for(int i=0;i<s.size();i++){
		if(s[i]==1){
			p+=1;
		}
	}
	if(p<m){
		cout<<0;
		return 0;
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	cout<<ans;
	return 0;
}