#include<bits/stdc++.h>
using namespace std;

int n,q;
string s1,s2;
map<string,string>mp;

string get1(int l,int r){
	string tmp="";
	for (int i=l;i<=r;i++) tmp+=s1[i];
	return tmp;
}

string get2(int l,int r){
	string tmp="";
	for (int i=l;i<=r;i++) tmp+=s2[i];
	return tmp;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	while (n--){
		cin>>s1>>s2;
		mp[s1]=s2;
	}
	while (q--){
		cin>>s1>>s2;
		int len=s1.size(),l=len-1,r=0,ans=0;
		if (s2.size()!=len){
			cout<<0<<"\n";
			continue;
		} 
		for (int i=0;i<len;i++){
			if (s1[i]!=s2[i]) l=min(l,i),r=max(r,i);
		}
		for (int i=l;i>=0;i--){
			int k=max(i,r);
			string t1=get1(i,k),t2=get2(i,k);
			for (int j=k;j<=len;j++){
				if (mp[t1]==t2) ans++;
				t1+=s1[j+1],t2+=s2[j+1];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}


