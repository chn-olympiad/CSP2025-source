#include <bits/stdc++.h>
using namespace std;
int a[1005];
int main(){
	freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
	int n,m;cin>>n>>m;
	if(n>15){
		cout<<0;return 0;
	}
	string s,s2;cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s2+=(i+'0');
	}int ans=0;
	do{
		//cout<<s2<<endl;
		int f=0,u=0;
		for(int i=0;i<s2.size();i++){
			if(f>=a[s2[i]-'0']){
				f++;continue;
			}
			if(s[i]=='1')u++;
			else f++;
		}
		if(u>=m)ans++;
	}
	while(next_permutation(s2.begin(),s2.end()));
	cout<<ans;
	return 0;
}