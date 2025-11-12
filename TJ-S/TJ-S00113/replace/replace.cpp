#include<bits/stdc++.h>
using namespace std;
map<string,string> m;
map<pair<string,string>,int> c;
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		int l=0,r=0;
		for(int j=0;j<s1.size();j++){
			if(s1[j]!=s2[j]){
				l=j;
				break;
			}
		}
		for(int j=s1.size()-1;j>=0;j--){
			if(s1[j]!=s2[j]){
				r=j;
				break;
			}
		}
		string str1,str2;
		for(int j=l;j<=r;j++){
			str1+=s1[j];
			str2+=s2[j];
		}
		m[str1]=str2;
		c[{str1,str2}]++;
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		int l=0,r=0;
		for(int j=0;j<s1.size();j++){
			if(s1[j]!=s2[j]){
				l=j;
				break;
			}
		}
		for(int j=s1.size()-1;j>=0;j--){
			if(s1[j]!=s2[j]){
				r=j;
				break;
			}
		}
		string str1,str2;
		for(int j=l;j<=r;j++){
			str1+=s1[j];
			str2+=s2[j];
		}
		cout<<c[{str1,str2}]<<endl;
	}
	return 0;
}
