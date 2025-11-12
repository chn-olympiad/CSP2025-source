#include<bits/stdc++.h>
//int main!!!!
//T1 
using namespace std;
const int N=2e5+100;
const int base=31;
const int mod1=1e9+7;
const int mod2=1e9+9;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int n,q;
string s[N][2];

struct node{
	int h1,h2;
};
node p[N][2];
node hash(string str){
	int num=str.length();
	int res1=0,res2=0;
	int c=base;
	for(int i=0;i<num;i++){
		res1=(res1+c*(str[i]-'0'))%mod1;
		c*=c;
	}
	c=base;
	for(int i=num-1;i>=0;i--){
		res2=(res2+c*(str[i]-'0'))%mod2;
		c*=c;
	}
	return {res1,res2};
}
node hash2(string str,int l,int r){
	int num=str.length();
	int res1=0,res2=0;
	int c=base;
	for(int i=l;i<=r;i++){
		res1=(res1+c*(str[i]-'0'))%mod1;
		c*=c;
	}
	c=base;
	for(int i=r;i>=l;i--){
		res2=(res2+c*(str[i]-'0'))%mod2;
		c*=c;
	}
	return {res1,res2};
}
bool check(node aa,node bb){
	return (aa.h1==bb.h1&&aa.h2==bb.h2);
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();q=read();
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		p[i][0]=hash(s[i][0]);
		p[i][1]=hash(s[i][1]);
	}
	/*while(q--){
		string ss;
		cin>>ss;
		node p1=hash2(ss,2,4);
		node p2=p[1][0];
		cout<<p1.h1<<" "<<p2.h1<<" "<<p1.h2<<" "<<p2.h2<<" "<<check(p1,p2)<<"\n";
	}*/
	string ss;
	//cout<<hash2(ss,1,0).h1;
	while(q--){
		int ans=0;
		string str1,str2;
		cin>>str1>>str2;
		for(int i=1;i<=n;i++){
			int cnt=s[i][0].length();
			for(int l=0;l+cnt-1<str1.length();l++){
				int r=l+cnt-1;
				if(check(hash2(str1,l,r),p[i][0])){
					//cout<<"1"<<endl;
					node hash1l=hash2(str1,0,l-1);
					node hash2l=hash2(str2,0,l-1);
					node hash1r=hash2(str1,r+1,str1.length()-1);
					node hash2r=hash2(str2,r+1,str2.length()-1);
					node hash2m=hash2(str2,l,r);
					//cout<<check(hash1l,hash2l)<<" "<<check(hash1r,hash2r)<<" "<<check(hash2m,p[i][1])<<"\n";
					if(check(hash1l,hash2l)&&check(hash1r,hash2r)&&check(hash2m,p[i][1]))ans++;
				}
			}
		}
		cout<<ans<<"\n";
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
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
