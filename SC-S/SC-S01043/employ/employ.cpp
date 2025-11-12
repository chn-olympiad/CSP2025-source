#include<bits/stdc++.h>
using namespace std;
int n,m,c[510],s[510],ans,cnt;
string si;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>si;
	for(int i=0;i<si.size();i++){
		s[i]=si[i]-'0';
		if(s[i]==0) cnt++;
	}
	for(int i=1;i<=n;i++)
		cin>>c[i];
	if(cnt==0){
		ans=1;
		for(int i=1;i<=m;i++)
			ans*=i;
		if(m==n){cout<<ans;return 0;}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
