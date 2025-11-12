#include<bits/stdc++.h>
using namespace std;
long long n,q;
string y[200005],yy[200005],s,s1;
bool str(string t1,string t2){
	long long i=0;
	while(t1[i]==t2[i]&&i<t1.size()){
		i++;
	}
	if(i==t2.size()){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>y[i]>>yy[i];
	}
	while(q--){
		cin>>s>>s1;
		long long ans=0;
		for(int i=1;i<=n;i++){
				string x="",z="",op="";			
			if(s.find(y[i])<18446744073709551615||str(s,y[i])==1){
				for(int j=0;j<s.find(y[i]);j++){
					x+=s[j];
				}
				for(int j=s.find(y[i])+y[i].size();j<s.size();j++){
					z+=s[j];
				}
				op+=x+yy[i]+z;
			}else {
				continue;
			}
			if(op==s1){
				ans++;
			}
		}
		cout<<ans<<"\n";
	}

	
	return 0;
} 