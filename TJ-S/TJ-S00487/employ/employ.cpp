#include <bits/stdc++.h>
using namespace std;
long long n,m,c[505],ans=1,cnt,s1[505],t,g;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+1+n);
	int lenth=s.size();
	for(int i=0;i<lenth;i++){
		s1[i+1]=s[i]-0;
		if(s[i]-'0'>=1){
			cnt++;
		}
	}
	if(cnt==lenth){
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}
	if(m==1&&cnt!=0){
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}
	else if(cnt==0){
		cout<<0;
		return 0;
	}
	if(m==n){
		if(cnt==lenth){
			for(int i=1;i<=n;i++){
				ans*=i;
				ans%=998244353;
			}
			cout<<ans;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		if(t>=c[i]){
			t++;
			continue;
		}
		else{
			if(s1[i]){
				g++;
			}
		}
	}
	if(g<m){
		cout<<0;
		return 0;
	}
	else if(g==m){
		cout<<1;
		return 0; 
	}
	return 0;
}
