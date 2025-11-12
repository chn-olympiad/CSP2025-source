#include<bits/stdc++.h>
using namespace std;
int const N=1e6+5;
string t[N],s[N];
int n,m;
vector<string>to[N];

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	string a,b;
	for(int i=1;i<=n;i++){
		cin>>a;
		getchar();
		cin>>b;
		int cnt=1;
		for(int j=0;j<a.size();j++){
			if(a[j]!=b[j]){
				s[i]=s[i]+a[j]+b[j];
			}
		}
	}
	for(int i=1;i<=m;i++){
		cin>>a>>b;
		int cnt=1;
		if(a.size()!=b.size()){
			cout<<0<<endl;
			continue;
		}
		for(int j=0;j<a.size();j++){
			if(a[j]!=b[j]){
				t[i]=t[i]+a[j]+b[j];
			}
		}
		int ans=0;
		for(int j=1;j<=n;j++){
			if(s[j]==t[i]) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
