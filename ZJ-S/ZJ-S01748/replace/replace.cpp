#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<string,string>mp;
int n,m;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string x,y;
		cin>>x>>y;
		mp[x]=y;
	}
	while(m--){
		string x,y;
		cin>>x>>y;
		int ans=0;
		for(int i=0;x[i]!='\0';i++){
			for(int l=1;x[i+l-1]!='\0';l++){
				string a,b,c;
				a=x.substr(0,i);
				b=x.substr(i,l);
				//0123456
				c=x.substr(i+l,x.size()-(i+l));
				if(a==b&&a!=""||a==c&&c!=""||b==c&&b!="")continue;
//				cout<<a<<' '<<b<<' '<<c<<endl;
				if(mp[a]+mp[b]+mp[c]==y)ans++;
				else if(mp[a]+mp[b]+c==y)ans++;
				else if(mp[a]+b+mp[c]==y)ans++;
				else if(mp[a]+b+c==y)ans++;
				else if(a+mp[b]+mp[c]==y)ans++;
				else if(a+mp[b]+c==y)ans++;
				else if(a+b+mp[c]==y)ans++;
				else if(a+b+c==y)ans++;
			}
		}cout<<ans<<endl;
	}
	return 0;
}