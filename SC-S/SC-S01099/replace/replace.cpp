#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
pair<string,string>a[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<0<<endl;
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			int len=a[i].first.size();
			//cout<<len<<endl;
			string x="",y="",z=s1;
			string y1=a[i].first,y2=a[i].second;
			for(int i=0;i<len;i++){
				y+=z[0];
				//cout<<z<<endl;
				z.erase(0,1);
			}
			//cout<<x<<" "<<y<<" "<<z<<endl;
			string s=x+y2+z;
			if(y1==y && s==s2){
				ans++;
			}
			for(int i=len;i<s1.size();i++){
				x+=y[0];
				y+=z[0];
				y.erase(0,1);
				z.erase(0,1);
				string s=x+y2+z;
				if(y1==y && s==s2){
					//cout<<y2<<endl;
					ans++;
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
