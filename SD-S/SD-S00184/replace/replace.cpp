#include<bits/stdc++.h>
#define int long long

using namespace std;
const int N=2e5+5;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	cin>>n>>q;
	map<string,string> m;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		m[s1]=s2;
	}
	for(int i=1;i<=q;i++){
		string t1,t2;
		cin>>t1>>t2;
		int ans=0;
		for(int i=0;i<=t1.size()-1;i++){
			for(int j=i+1;j<=t1.size()-1;j++){
				if(t2.substr(i,j-i+1)==m[t1.substr(i,j-i+1)]){
					string s1=t1.substr(0,i),s2=m[t1.substr(i,j-i+1)],s3=t1.substr(j+1,n-j);
//					cout<<s1<<' '<<s2<<' '<<s3<<endl;
					if(s1+s2+s3==t2) ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
