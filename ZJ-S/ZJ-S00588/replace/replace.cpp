#include <bits/stdc++.h>
#define ri register int
using namespace std;

inline int read(){
	int ret=0,f=1; char c;
	while(!isdigit(c=getchar())) if(c=='-') f=-1;
	while(isdigit(c)) ret=(ret<<1)+(ret<<3)+(c^48),c=getchar();
	return ret*f;
}

int n,q,pos[200010][2];
string s[200010][2],ss,s1,s2;
bool flag,f;
int tot;

int replace(int sub){
	int ans=0;
	ss=s[sub][0];
	for(ri i=0;i<s1.size();i++){
		f=1;
		for(ri j=i;j<i+ss.size();j++) f&=s1[j]==ss[j-i];
		if(f){
			string sn=s1;
			for(ri j=i;j<i+ss.size();j++) sn[j]=s[sub][1][j-i];
			if(sn==s2) ans++;
		}
	}
	return ans;
}

int l,ans;

int find(string str){
	l=str.size();
	for(ri i=0;i<l;i++) if(str[i]=='b') return i;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);

	cin>>n>>q;
	for(ri i=0;i<n;i++) cin>>s[i][0]>>s[i][1];
	flag=1,tot=0;
	string sss;
	for(ri l=0;l<10;l++){
		sss=s[l][1],tot=0;
		for(ri i=0;i<sss.size();i++){
			if(sss[i]!='a'){
				if(sss[i]=='b') tot++;
				else flag=0;
			}
		}
		flag&=(tot==1);
	}
	if(flag) for(ri i=0;i<n;i++) pos[i][0]=find(s[i][0]),pos[i][1]=find(s[i][1]);
		
	int sub1,sub2;
		
	while(q--){
		cin>>s1>>s2;
		ans=0;
		if(s1.size()<=2000 && s2.size()<=2000){
			for(ri i=0;i<n;i++) ans+=replace(i);
			cout<<ans<<'\n';
			continue;
		}
		sub1=find(s1),sub2=find(s2);
		for(ri i=0;i<n;i++)
			if(pos[i][0]>=sub1 && s[i][0].size()-pos[i][0]>=s1.size()-sub1 && pos[i][1]>=sub2 && s[i][1].size()-pos[i][1]>=s2.size()-sub2) ans++;
		
		cout<<ans<<'\n';
	}

	return 0;
}/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/
