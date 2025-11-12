#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],num[505],maxx;
string s;
map<int,int>mp;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int d=0;
	s=" "+s;
	for(int i=1;i<s.size();i++){
		if(s[i]=='0') {
			d=1;
			num[i]++;
		}
		num[i]+=num[i-1];
	}
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		mp[a[i]]++;
		maxx=max(maxx,a[i]);
	}
	int k=0,len=0;
	for(int i=maxx;i>=0;i--){
		int d=mp[i];
		mp[i]=k;
		k+=d;
	}
	long long ans=1;
	for(int i=2;i<=n;i++) ans*=i;
	if(d==0) cout<<ans;
	else{
		long long ans=1;
		for(int i=s.size()-1;i>=1;i--){
			ans*=mp[num[i]];
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
