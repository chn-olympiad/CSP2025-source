#include<bits/stdc++.h>
using namespace std;
int n,T,i,ans1,ans2,ans3,fl,l,j,ans,t,w;
string s1,s2,df1,df2,s,sa[5006666];
map<string,int> mp1,mp2;
string fan(string s){
	int i=0;
	string s1="";
	for(i=s.size()-1;i>=0;i--)
		s1+=s[i];
	return s1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>T;
	for(i=1;i<=n;i++){
		cin>>s1>>s2;
		mp1[s1]=i;
		mp2[s2]=i;
	}
	while(T--){
		cin>>s1>>s2;
		l=s1.size();
		ans1=ans2=ans3=0;
		if(s1.size()!=s2.size()){
			cout<<0<<"\n";
			continue ;
		}
		fl=0;
		for(i=0;i<l;i++)
			if(s1[i]!=s2[i]){
				if(fl==0) fl=1,t=i;
				w=i;
			}
		df1="";df2="";
		for(i=t;i<=w;i++) df1+=s1[i],df2+=s2[i];
		s="";
		for(i=t-1;i>=0;i--)
			s+=s1[i],sa[i]=fan(s),ans1+=(((mp1[fan(s)+df1]==mp2[fan(s)+df2])&&mp1[fan(s)+df1]!=0) ? 1 : 0);
		s="";
		for(i=w+1;i<l;i++)
			s+=s1[i],sa[i]=s,ans2+=(((mp1[df1+s]==mp2[df2+s])&&mp1[df1+s]!=0) ? 1 : 0);
		for(i=0;i<t;i++){
			for(j=w+1;j<l;j++){
				ans3+=(((mp1[sa[i]+df1+sa[j]]==mp2[sa[i]+df2+sa[j]])&&mp1[sa[i]+df1+sa[j]]!=0) ? 1 : 0);
			}
		}
		cout<<ans1+ans2+ans3+(((mp1[df1]==mp2[df2])&&mp1[df1]!=0) ? 1 : 0)<<"\n";
	}
	return 0;
}

