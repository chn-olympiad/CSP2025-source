#include<bits/stdc++.h>
using namespace std;
string s[100005];
string t[100005];
string budget(string z,string x,long long l,long long r){
	string o;
	for(int i=0;i<=l-1;i++){
		o+=z[i];
	}
	o+=x;
	for(int i=r+1;i<z.size();i++){
		o+=z[i];
	}
	return o;
}
int main (){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		cin>>t[i];
	}
	long long ans=0;
	while(q--){
		ans=0;
		string s1,t1;
		cin>>s1>>t1;
		if(t1.size()!=s1.size()){
			cout<<0<<"\n";
		}
		for(int i=0;i<s1.size();i++){
			for(int j=0;j<s1.size();j++){
				for(int k=1;k<=n;k++){
					if(i-j+1==s[k].size()){
						string s2=budget(s1,s[k],j,i);
						string t2=budget(t1,t[k],j,i);
						cout<<s2<<"      "<<t2<<endl;
						if(s2==t2){
							ans++;
						}
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}