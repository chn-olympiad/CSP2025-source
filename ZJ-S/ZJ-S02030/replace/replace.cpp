#include<bits/stdc++.h>
using namespace std;

long long n,x,t,e,m,q,ans=0,s,b,c,f[100010][5];
map<string ,string> mp;
string ss,sss,aa,bb;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	
	for(int i=1;i<=n;i++){
		cin>>ss>>sss;
		
		mp[ss]=sss;
	}//sort(mp+1,mp+1+n,cmp);
	
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>aa>>bb;
		s=0;
		int len=aa.length();
		for(int i=0;i<len;i++){
			for(int j=0;j<len;j++){
				if(aa[x]!=bb[x])s++;
			}}
		
		for(int i=0;i<len;i++){
			for(int j=s+i;j<len;j++){
				ss="";sss="";
				for(int k=i;k<=j;k++){
					ss+=aa[k];sss+=bb[k];
				}
				
				if(mp[ss]!=""&&mp[ss]==sss){
					ans++;cout<<ss<<"----\n";
				}
			}
		}cout<<ans<<"\n";
	}
	return 0;
}
/*



bool cmp(string aa,string bb){
	return aa.length()>=bb.length();
}


for(int j=i+1;j<=len;j++){
				ss="";
				for(int k=1;k<=j;k++){
					ss+=aa[k];
				}
				cout<<ss<<"----\n";
				if(check(ss,a)==true)
			}

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

