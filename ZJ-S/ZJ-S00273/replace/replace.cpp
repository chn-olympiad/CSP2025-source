#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
struct node{
	string s1,s2;
	friend bool operator < (node x,node y){
		if(x.s1==y.s1)return x.s2<y.s2;
		return x.s1<y.s1;
	}
};
map <node,int> m;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		int len=s1.size();
		bool f=0;
		string a="",b="";
		for(int j=0;j<len;j++){
			if(f){
				if(s1[j]==s2[j])break;
				a+=s1[j],b+=s2[j];
			}else{
				if(s1[j]!=s2[j]){
					f=1;
					j--;
				}
			}
		}
		m[node{a,b}]++;
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int len1=t1.size(),len2=t2.size();
		if(len1!=len2){
			cout<<0<<endl;
			continue;
		}
		bool f=0;
		string a="",b="";
		for(int j=0;j<len1;j++){
			if(f){
				if(t1[j]==t2[j])break;
				a+=t1[j],b+=t2[j];
			}else{
				if(t1[j]!=t2[j]){
					f=1;
					j--;
				}
			}
		}
		cout<<m[node{a,b}]<<endl;
	}
	return 0;
}
