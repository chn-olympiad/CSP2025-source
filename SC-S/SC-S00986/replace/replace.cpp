#include <iostream>
#include <cstdio>
#include <algorithm>

#include <string>
#include <cstring>
using namespace std;

string s[200020][3]={};

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	int n,q;
	cin>>n>>q;
	
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	
	for(int i=1;i<=q;i++){
		string a,b;
		cin>>a>>b;
		
		int ans=0;
		if(a.length()!=b.length()){
			cout<<0<<endl;
			continue;
		}
		for(int j=1;j<=n;j++){
			if((a.find(s[j][1])==b.find(s[j][2]))&&(a.find(s[j][1])<a.length())){
				string ax=a.substr(0,a.find(s[j][1]));
				string az=a.substr(a.find(s[j][1])+s[j][1].length(),a.length());
				string bx=b.substr(0,b.find(s[j][2]));
				string bz=b.substr(b.find(s[j][2])+s[j][2].length(),b.length());
				
				if((ax==bx)&&(az==bz)){
					ans++;
				}
			}
		}
		
		cout<<ans<<endl;
	}
	
	
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}