#include<bits/stdc++.h>
using namespace std;
string a[10000],b[10000];
int isin(string v,string s){
	for(int i=0;i<s.length()-v.length()+1;i++){
		int d=0;
		for(int j=0;j<v.length();j++){
			if(v[j]==s[i+j]){
				d++;
			}
			else break;
		}
		if(d==v.length()) return i;
	}
	return -1;
}
int dif(string v,string s){
	int d1=0;
	for(int i=0;i<v.length();i++){
		if(v[i]!=s[i]) d1++;
	}
	return d1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=q;i++){
		string w,e;
		int num=0;
		cin>>w>>e;
		for(int i=1;i<=n;i++){
			int b1=isin(b[i],e),a1=isin(a[i],w);
			if(a1==-1 or b1==-1) continue;
			else{
				if(a1==b1&&dif(a[i],b[i])==dif(w,e)) num++;
			}
			
		}
		cout<<num<<endl;
	}
	return 0;
}
