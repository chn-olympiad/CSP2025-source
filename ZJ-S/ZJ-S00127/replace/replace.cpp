#include<bits/stdc++.h>
using namespace std;
string s1,s2;
string t1[200005],t2[200005];
int n,q;
int found(string sa,string sb){
	int len=sa.size();
	for(int i=0;i<len;i++){
		if(sa[i]==sb[0]){
			int flag=1;
			for(int j=0;j<sb.size();j++){
				if(sa[i+j]!=sb[j]){
					flag=0;
					break;
				}
			}
			if(flag==1)return i;
		}
	}
	return -1;
}
string change(string s,string ta,string tb){
	for(int i=0;i<s.size();i++){
		if(s[i]==ta[0]){
			for(int j=0;j<ta.size();j++){
				s[i+j]=tb[j];
			}
			return s;
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>t1[i]>>t2[i];
	}
	for(int t=1;t<=q;t++){
		cin>>s1>>s2;
		int cnt=0;
		if(s1.size()!=s2.size()){
			cout<<0<<endl;
			continue;
		}
		int len=s1.size();
		for(int i=1;i<=n;i++){
			if(found(s1,t1[i])==-1||!found(s2,t2[i])==-1){
				continue;
			}
			if(found(s1,t1[i])==found(s2,t2[i])){
				if(change(s1,t1[i],t2[i])==s2)cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
