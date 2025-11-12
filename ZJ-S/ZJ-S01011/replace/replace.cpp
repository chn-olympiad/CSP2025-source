#include<bits/stdc++.h>
using namespace std;
map<string,string> a;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","r",stdout);
	int n,q;
	cin>>n>>q;
	string s1,s2;
	while(n--){
		cin>>s1>>s2;
		a[s1]=s2;
	}while(q--){
		cin>>s1>>s2;
		int ans=0;
		for(int i=0;i<s1.length()-1;i++){
			for(int j=s1.length()-1;j>0;j--){
				if(a[s1.substr(i,j-i+1)]==s2.substr(i,j-i+1)){
					ans++;
				}if(s1[j]!=s2[j]) break;
			}if(s1[i]!=s2[i]) break;
		}cout<<ans<<'\n';
	}
	return 0;
}
