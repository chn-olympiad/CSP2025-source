#include<bits/stdc++.h>
using namespace std;
//RP++
int n,q;
pair<string,string> s[1145141];
string s1,s2;
int find(string x,string y){
	int res=1,i;
	for(i=0;i+y.length()-1<x.length();i++){
		res=0;
		for(int j=i;j<i+y.length();j++){
			if(x[j]!=y[j-i]){
				res=1;
				break;
			}
		}
		if(!res) return i;
	}
	return -1;
}
string rp(string x,int l,string y){
	for(int i=l;i<l+y.length();i++){
		x[i]=y[i-l];
	}
	return x;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s[i].first>>s[i].second;
	}
	while(q--){
		cin>>s1>>s2;
		if(s1.length()!=s2.length()){
			cout<<0<<endl;
			continue;
		}
		int flag=0;
		for(int i=0;i<n;i++){
			if(find(s1,s[i].first)!=-1){
				flag=1;
				break;
			}
		}
		if(!flag){
			cout<<0<<endl;
			continue;
		}
		int cnt=0;
		for(int i=0;i<n;i++){
			int a=find(s1,s[i].first);
			string c=rp(s1,find(s1,s[i].first),s[i].second);
			if(a!=-1&&c==s2){
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
} 