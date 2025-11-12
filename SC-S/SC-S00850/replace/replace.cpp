#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,q;
ll ans;
string s[200005][2];
string c1,c2;
bool check1(string a,string b){
	if(b=="") return 1;
	ll lenb=b.size(),l=a.size()-b.size();
	for(ll i=0;i<b.size();i++){
		if(b[i]!=a[l]) return 0;
		l++; 
	}
	return 1;
}
bool check2(string a,string b){
	if(b=="") return 1;
	ll lenb=b.size(),l=0;
	for(ll i=0;i<b.size();i++){
		if(b[i]!=a[l]) return 0;
		l++; 
	}
	return 1;
}
string t[200005][4];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(ll i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	
	for(ll j=1;j<=n;j++){
		string okd1="",okd2="",oks1="",oks2="";
		string ch1=s[j][0],ch2=s[j][1];
		ll len1=ch1.size(),l1=-1,r1=-1;
		for(ll k=0;k<len1;k++){
			if(ch1[k]!=ch2[k]){
				r1=k;
				if(l1==-1) l1=k;
			}
		}
		for(ll k=l1;k<=r1;k++) okd1+=ch1[k],okd2+=ch2[k];
		for(ll k=0;k<l1;k++) oks1+=ch1[k];
		for(ll k=r1+1;k<len1;k++) oks1+=ch1[k];
		for(ll k=0;k<l1;k++) oks2+=ch2[k];
		for(ll k=r1+1;k<len1;k++) oks2+=ch2[k];
		t[j][0]=okd1,t[j][1]=okd2,t[j][2]=oks1,t[j][3]=oks2;
	}
	for(ll i=1;i<=q;i++){
		ans=0;
		cin>>c1>>c2;
		ll l=-1,r=-1;
		ll lenc=c1.size();
		for(ll j=0;j<lenc;j++){
			if(c1[j]!=c2[j]){
				r=j;
				if(l==-1) l=j;
			}
		}
		string d1="",d2="",s1="",s2="";
		for(ll j=l;j<=r;j++) d1+=c1[j],d2+=c2[j];
		for(ll j=0;j<l;j++) s1+=c1[j];
		for(ll j=r+1;j<lenc;j++) s1+=c1[j];
		for(ll j=0;j<l;j++) s2+=c2[j];
		for(ll j=r+1;j<lenc;j++) s2+=c2[j]; 
		for(ll j=1;j<=n;j++){
			if(d1==t[j][0] and d2==t[j][1] and check1(s1,t[j][2]) and check2(s2,t[j][3])){
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//4 2
//xabcx xadex
//ab cd
//bc de
//aa bb
//xabcx xadex