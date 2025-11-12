#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	map<string,string> m;
	int n,q;
	cin>>n>>q;
	for(int i = 0;i < n;i++){
		string a,b;
		cin>>a>>b;
		m[a] = b;
	}
	for(int k = 0;k < q;k++){
		string s,t;
		cin>>s>>t;
		int leng = s.length();
		//string u = "abcdefg";
		int ans = 0;
		//cout<<(u.substr(2,5));
		for(int i = 0;i <= leng;i++){
			for(int j = 0;j <= leng-i;j++){
				if(m[s.substr(i,j)]!=""){
					string u = s.substr(0,i) + m[s.substr(i,j)] + s.substr((i+j),(leng-i-j));
					//cout<<u<<endl;
					if(u==t)ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
