#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define endl '\n'
using namespace std;
const int MAXN=5e6+5;
const int base=131;
int n,q;
ull ans,hsh1[MAXN][3],hsh2[MAXN],pw[MAXN];
string s[MAXN][3],t1,t2;
ull get_hsh1(string s){
	ull res=0;
	for(int i=0;i<s.size();i++){
		res=res*base+s[i]-'0';
	}
	return res;
}
void get_hsh2(string s){
	for(int i=0;i<s.size();i++){
		hsh2[i]=hsh2[i-1]*base+s[i]-'0';
	}
} 
void init(){
	pw[0]=1;
	for(int i=1;i<MAXN;i++){
		pw[i]=pw[i-1]*base;
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>q;
	init();
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		hsh1[i][1]=get_hsh1(s[i][1]);
		hsh1[i][2]=get_hsh1(s[i][2]);
	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		int len1=t1.size();
		get_hsh2(t1);
		ull tmp=get_hsh1(t2);
		for(int i=1;i<=n;i++){
			int len2=s[i][1].size();
			for(int l=0;l+len2-1<len1;l++){
				if(hsh2[l+len2-1]-hsh2[l-1]*pw[len2]==hsh1[i][1]){
					ull res=hsh2[len1-1]-hsh1[i][1]*pw[l]+hsh1[i][2]*pw[l];
					if(res==tmp) ans++;
				}
			}
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
