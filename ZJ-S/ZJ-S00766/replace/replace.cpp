#include <bits/stdc++.h>
using namespace std;
int n,T,i,j,len,ans,s[200010];
string x,y,a[200010],b[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>T;
	for(i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		s[i]=a[i].size();
	}
	while(T--){
		cin>>x>>y;
		len=x.size();ans=0;
		if(y.size()!=len){
			cout<<"0\n";
			continue;
		}
		for(i=1;i<=n;i++){
			for(j=0;j<=len-s[i];j++){
				if(x.substr(0,j)!=y.substr(0,j)) break;
				else if(x.substr(j,s[i])==a[i]&&y.substr(j,s[i])==b[i]&&x.substr(j+s[i],len-j-s[i])==y.substr(j+s[i],len-j-s[i])) ans++;
			}
		}
		cout<<ans<<"\n";
	}
}
