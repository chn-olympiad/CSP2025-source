#include <iostream>
#include <string>
#define mod1 998244353
using namespace std;
unsigned n,q;
struct node{
	string str[2];
	unsigned lena,lenb;
	unsigned __int128 hash1,hash2;
}s[200005],t;
unsigned posb[200005][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for(unsigned i=1;i<=n;i++){
		cin >> s[i].str[0] >> s[i].str[1];
		for(s[i].lena=0;s[i].lena<s[i].str[0].size() && s[i].str[0][s[i].lena]==s[i].str[1][s[i].lena];s[i].lena++);
		for(s[i].lenb=s[i].str[0].size()-1;s[i].lenb>=s[i].lena && s[i].str[0][s[i].lenb]==s[i].str[1][s[i].lenb];s[i].lenb--);
		s[i].hash2=s[i].hash1=0;
		for(unsigned j=0;j<=s[i].str[0].size();j++){
			if(j<s[i].lena || j>s[i].lenb)continue;
			s[i].hash1*=26,s[i].hash2*=26;
			s[i].hash1+=s[i].str[0][j]-'a',s[i].hash2+=s[i].str[1][j]-'a';
		}
	}
	while(q--){
		cin >> t.str[0] >> t.str[1];
		if(t.str[0].size()!=t.str[1].size()){
			printf("0\n");
			continue;
		}
		for(t.lena=0;t.lena<t.str[0].size() && t.str[0][t.lena]==t.str[1][t.lena];t.lena++);
		for(t.lenb=t.str[0].size()-1;t.lenb>=t.lena && t.str[0][t.lenb]==t.str[1][t.lenb];t.lenb--);
		t.hash2=t.hash1=0;
		for(unsigned j=t.lena;j<=t.lenb;j++){
			t.hash1*=26,t.hash2*=26;
			t.hash1+=t.str[0][j]-'a',t.hash2+=t.str[1][j]-'a';
		}
		unsigned ans=0;
		for(int i=1;i<=n;i++){
			if(s[i].hash1==t.hash1 && s[i].hash2==t.hash2){
				bool check=1;
				if(s[i].lena>t.lena || s[i].str[0].size()-s[i].lenb>t.str[0].size()-t.lenb)check=0;
				for(unsigned j=0;j<s[i].lena && check;j++){
					if(s[i].str[0][j]!=t.str[0][t.lena-s[i].lena+j])check=0;
				}
				for(unsigned j=s[i].lenb+1;j<s[i].str[0].size() && check;j++){
					if(s[i].str[0][j]!=t.str[0][t.lenb+j-s[i].lenb])check=0;
				}
				if(check)ans++;
			}
		}
		printf("%u\n",ans);
	}
	return 0;
}
