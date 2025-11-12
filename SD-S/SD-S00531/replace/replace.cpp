/*
Wrong Code :(

#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
string s1[214514],s2[214514];
int sl[214514],sr[214514],slen[214514];
int hs1[214514],hs2[214514],hsl[214514],hsr[214514],dnu[214514];
int usel[214514],user[214514];
const int base=71,mod=1e18+7;
int hstr(string s){
	int sum=0;
	for(int i=0;i<s.size();i++){
		sum=(sum*base+(s[i]-' '))%mod;
	}
	return sum;
}
main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		if(s1[i]==s2[i]){
			dnu[i]=1;
			continue;
		}
		s1[i]=" "+s1[i]+" ";
		s2[i]=" "+s2[i]+" ";
		int len=s1[i].size()-2;slen[i]=len;
		int l=0,r=len+1;
		while(s1[i][l]==s2[i][l]&&l<=len)l++;
		while(s1[i][r]==s2[i][r]&&r>=1)r--;
		sl[i]=l,sr[i]=r;
		hs1[i]=hstr(s1[i].substr(l,r-l+1));
		hs2[i]=hstr(s2[i].substr(l,r-l+1));
		if(l!=0)hsl[i]=hstr(s1[i].substr(1,l-1));
		if(r!=len+1){
			string x=s1[i].substr(r+1);
			x=x.substr(0,x.size()-1);
			hsr[i]=hstr(x);
		}
	}
	for(int i=1;i<=q;i++){
		string t1,t2;
		cin>>t1>>t2;
		t1=" "+t1+" ";
		t2=" "+t2+" ";
		int len=t1.size()-2;
		if(len!=t2.size()-2){cout<<0<<endl;continue;}
		for(int j=1;j<=len;j++)usel[j]=user[j]=-1;
		int l=0,r=len+1;
		while(t1[l]==t2[l]&&l<=len)l++;
		while(t1[r]==t2[r]&&r>=1)r--;
		int hmid=hstr(t1.substr(l,r-l+1));
		int hmid2=hstr(t2.substr(l,r-l+1));
		int ans=0;
		for(int j=1;j<=n;j++){
			if(dnu[i])continue;
			if(hmid!=hs1[j]||hmid2!=hs2[j])continue;
			int hl=0,hr=0;
			if(usel[sl[j]-1]==-1){
				if(l>sl[j]-1)hl=hstr(t1.substr(l-sl[j]+1,sl[j]-1));
			}
			else hl=usel[sl[j]-1];
			if(user[slen[j]-sr[i]]==-1){
				if(r!=len+1)hr=hstr(t1.substr(r+1,slen[j]-sr[i]));
			}
			else hr=user[slen[j]-sr[i]];
			if(hsl[j]==hl&&hsr[j]==hr)ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
string s1[214514],s2[214514];
int sl[214514],sr[214514],slen[214514];
string hs1[214514],hs2[214514],hsl[214514],hsr[214514];
int dnu[214514];
int usel[214514],user[214514];
const int base=71,mod=1e18+7;
int hstr(string s){
	int sum=0;
	for(int i=0;i<s.size();i++){
		sum=(sum*base+(s[i]-' '))%mod;
	}
	return sum;
}
main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		if(s1[i]==s2[i]){
			dnu[i]=1;
			continue;
		}
		s1[i]=" "+s1[i]+" ";
		s2[i]=" "+s2[i]+" ";
		int len=s1[i].size()-2;slen[i]=len;
		int l=0,r=len+1;
		while(s1[i][l]==s2[i][l]&&l<=len)l++;
		while(s1[i][r]==s2[i][r]&&r>=1)r--;
		sl[i]=l,sr[i]=r;
		hs1[i]=s1[i].substr(l,r-l+1);
		hs2[i]=s2[i].substr(l,r-l+1);
	}
	for(int i=1;i<=q;i++){
		string t1,t2;
		cin>>t1>>t2;
		t1=" "+t1+" ";
		t2=" "+t2+" ";
		int len=t1.size()-2;
		if(len!=t2.size()-2){cout<<0<<"\n";continue;}
		int l=0,r=len+1;
		while(t1[l]==t2[l]&&l<=len)l++;
		while(t1[r]==t2[r]&&r>=1)r--;
		string hmid=t1.substr(l,r-l+1);
		string hmid2=t2.substr(l,r-l+1);
		int ans=0;
		for(int j=1;j<=n;j++){
//			if(dnu[i])continue;
			if(hmid!=hs1[j]||hmid2!=hs2[j])continue;
			if(l<sl[j])continue;
			if(len-r<slen[j]-sr[j])continue;
			int x=1,y=l-sl[j]+1;
			bool flag=true;
			for(;x<=slen[j];x++,y++){
				if(s1[j][x]!=t1[y]){
					flag=false;
					break;
				}
			}
			if(flag)ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
// give me 50 pts plz! qwq!
