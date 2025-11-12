#include<bits/stdc++.h>
using namespace std;
bool KMP(string t,string p,string s,string r){
//	cout<<t<<" "<<p<<" "<<s<<" "<<r<<endl;
	string tmps;
	for(int i=0;i<t.size();i++) tmps+=' ';
	for(int i=0;i<t.size()-p.size()+1;i++){
		int tmp=i,suc=0;
		for(int j=0;j<p.size();j++){
			if(t[tmp]==p[j]){
				tmp++;suc++;
			}else break;
		}
		if(suc==p.size()){
			for(int j=i;j<=i+suc;j++){
				tmps[j]=t[j];t[j]=s[j-i];
			}
			cout<<t<<endl;
			if(t==r) return 1;
			for(int j=i;j<=i+suc;j++) t[j]=tmps[j];
		}
	}
	return 0;
}
int n,q;
string s1[200005],s2[200005];
int main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	for(int i=1;i<=q;i++){
		string t1,t2;cin>>t1>>t2;
		int ans=0;
		for(int j=1;j<=n;j++){
			ans+=KMP(t1,s1[j],s2[j],t2);
		}
		cout<<ans<<endl;
	}
	return 0;
}
