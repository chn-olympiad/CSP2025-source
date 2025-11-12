#include <bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;
/*!@#$%^&*~~ Boundary Line ~~*&^%$#@!*&^%$#@!*/
const int N=2e6+5,Mod=1333331;
int n,m;
int mul[N];
int hsh1[N];
int hsh2[N];
int hsh3[N];
int a[N],b[N];
map<PII,int> mp;
bool flag=0;
/*!@#$%^&*~~ Boundary Line ~~*&^%$#@!*&^%$#@!*/
int get(string s){
	int ans=0;
	for(int i=0;i<(int)s.size();i++){
		if(s[i]!='a' && s[i]!='b') flag=1;
		ans=(ans*31+(s[i]-'a'+1))%Mod;
	}
	return ans;
}
void init(){
	string s1,s2;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		mp[{get(s1),get(s2)}]++;
		hsh3[i]=get(s1);
		for(int j=0;j<s2.size();j++){
			if(s2[j]=='b')
				a[i]=j,b[i]=s1.size()-j-1;
		}
	}
	mul[0]=1;
	for(int i=1;i<N;i++){
		mul[i]=mul[i-1]*31%Mod;
	}
}
void init2(string s,int *hsh){
	hsh[0]=0;
	for(int i=0;i<(int)s.size();i++){
		hsh[i+1]=(hsh[i]*31+s[i]-'a'+1)%Mod;
	}
}
int get(int l,int r,int *hsh){
	return (hsh[r]-hsh[l-1]*mul[r-l+1]%Mod+Mod)%Mod;
}
/*!@#$%^&*~~ Boundary Line ~~*&^%$#@!*&^%$#@!*/
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	init();
	string t1,t2;
	while(m --> 0){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<'\n';
			continue;
		}
		init2(t1,hsh1);
		init2(t2,hsh2);
		int len=t1.size();
		t1=' '+t1,t2=' '+t2;
		if(flag==0){
			int p=0;
			for(int i=1;i<=len;i++)
				if(t2[i]=='b')
					p=i;
			int ans=0;
			for(int i=1;i<=n;i++){
			    if(p-a[i]<=0 || p+b[i]>len) continue;
				if(get(1,p-a[i]-1,hsh1)==get(1,p-a[i]-1,hsh2) && get(p+b[i]+1,len,hsh1)==get(p+b[i]+1,len,hsh2))
					ans+=(hsh3[i]==get(p-a[i],p+b[i],hsh1));
			}
			cout<<ans<<'\n';
			continue;
		}
		int ans=0,mx1=0,mx2=n+1;
		for(int i=1;i<=len;i++){
			if(t1[i]!=t2[i])
				break;
			mx1=i;
		}
		for(int i=len;i>=1;i--){
			if(t1[i] != t2[i])
				break;
			mx2=i;
		}
		for(int i=1;i<=mx1+1;i++){
			for(int j=mx2-1;j<=len;j++){
				if(i>j) continue;
				ans+=mp[{get(i,j,hsh1),get(i,j,hsh2)}];
			}
		}
		cout<<ans<<'\n';
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

3 4
a b
b c
c d
aa bb
aa b
a c
b a

首先，我们可以知道，如果t1,t2长度不相同，则一定为0
首先先确定t1,t2不相同的位置，
暴力思路：
用KMP or Hash
*/