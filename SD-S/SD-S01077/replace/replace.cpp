#include <iostream>
#include <cstring>
#include <string>
#define ull unsigned long long
using namespace std;
const int base=131;
int n,q,sz[200005];
ull m1[200005],m2[200005],o1[5000005],o2[5000005],bs[5000005];
string s1[200005],s2[200005],t1,t2;
ull hs(string s){
	int i,sz=s.size();
	ull res=0;
	for(i=0;i<sz;i++){
		res=res*base+(s[i]-'a');
	}
	return res;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int i,j,szz,s_,e_,ans1=0;
	cin>>n>>q;
	for(i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		sz[i]=s1[i].size();
		m1[i]=hs(s1[i]),m2[i]=hs(s2[i]);
	}
	bs[0]=1;
	for(i=1;i<=5000000;i++){
		bs[i]=bs[i-1]*base;
	}
	while(q--){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<"0\n";
			continue;
		}
		if(n*q>1000000000){
			cout<<"0\n";
			continue;
		}
		szz=t1.size(),s_=0,e_=0,ans1=0;
		for(i=0;i<szz;i++){
			o1[i+1]=o1[i]*base+(t1[i]-'a');
			o2[i+1]=o2[i]*base+(t2[i]-'a');
			if(t1[i]!=t2[i]){
				e_=i+1;
				if(!s_) s_=i+1;
			}
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=szz-sz[i]+1;j++){
				if((o1[j+sz[i]-1]-o1[j-1]*bs[sz[i]]==m1[i])&&(o2[j+sz[i]-1]-o2[j-1]*bs[sz[i]]==m2[i])&&(j<=s_&&e_<=j+sz[i]-1)){
					ans1++;
				}
			}
		}
		cout<<ans1<<'\n';
	}
	
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
