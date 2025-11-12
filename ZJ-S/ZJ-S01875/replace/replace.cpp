#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,q;
string s[N][2];
int search(string t1,string t2,string s1,string s2){
	int tot=0;
	for(int i=0;i<t1.length()-s1.length();i++){
		bool f=true;
		for(int j=0;j<s1.length();j++){
			if(t1[i+j]!=s1[j]||t2[i+j]!=s2[j]){
				f=false;
				break;
			}
		}
		if(f==true)tot++;
	}
	return tot;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.length()!=t2.length())cout<<0;
		else{
			int ans=0;
			for(int j=1;j<=n;i++){
				ans+=search(t1,t2,s[j][1],s[j][2]);
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}