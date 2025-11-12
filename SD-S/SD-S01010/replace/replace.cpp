#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!(c>='0'&&c<='9')){if(c=='-') f=-1;c=getchar();}
	while((c>='0'&&c<='9')){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
	return x*f;
}
string s[200500][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n=read(),q=read();
	for(int i=1;i<=n;++i){
		cin>>s[i][0]>>s[i][1];
	}
	while(q--){
		string s1,s2,ss1;
		cin>>s1>>s2;
		ss1=s1;
		int sum=0;
		for(int i=1;i<=n;++i){
			for(int j=0;j<=(int)s1.size()-(int)s[i][0].size();++j){
				bool a=1;
				for(int k=0;k<s[i][0].size();++k){
					if(s[i][0][k]!=s1[k+j]){
						a=0;
						break;
					}
					s1[k+j]=s[i][1][k];
				}
				if(a==1&&s1==s2){
					++sum;
				}
				s1=ss1;
			}
		}
		cout<<sum<<'\n';
	}
}


