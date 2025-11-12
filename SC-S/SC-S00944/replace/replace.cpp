#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string s[N][2],t[N][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		int len=s1.size();
		int p=0;
		while(s1[p]==s2[p]) p++;
		for(int i=p;i<len;i++){
			s1[i-p]=s1[i];
			s2[i-p]=s2[i];
		}
		len-=p;
		p=len-1;
		while(s1[p]==s2[p]) p--;
		len=p+1;
		for(int j=0;j<len;j++){
			s[i][0]+=s1[j];
			s[i][1]+=s2[j];
		} 
	}
	for(int i=1;i<=q;i++){
		string t1,t2;
		int ans=0;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<'\n';
			continue;
		}
		int len=t1.size();
		int p=0;
		while(t1[p]==t2[p]) p++;
		for(int i=p;i<len;i++){
			t1[i-p]=t1[i];
			t2[i-p]=t2[i];
		}
		len-=p;
		p=len-1;
		while(t1[p]==t2[p]) p--;
		len=p+1;
		for(int j=0;j<len;j++){
			t[i][0]+=t1[j];
			t[i][1]+=t2[j];
		}
		for(int j=1;j<=n;j++){
			if(t[i][0]==s[j][0]&&
			t[i][1]==s[j][1]) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}