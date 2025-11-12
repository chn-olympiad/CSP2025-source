#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

const int maxn=1e4+5,maxq=1e6+5;
int n,q;
string s[maxn][3];
string l[maxq][3];
bool A=true;

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	if(q!=1)A=false;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2]; 
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		string temp="";
		cin>>l[i][1]>>l[i][2];
		int size1=l[i][1].size(),size2=l[i][2].size();
		for(int j=0;j<size1;j++){
			if(j>0)temp+=l[i][1][j-1];
			string tot=temp;
			for(int k=1;k<=n;k++){
				tot=temp;
				bool b=true;
				for(int x=0;x<s[k][2].size();x++){
					if(l[i][1][x+j]!=s[k][1][x]){
						b=false;
						break;
					}
					tot+=s[k][2][x];
				}
				if(b==false)continue;
				for(int k=tot.size();k<size1;k++){
					tot+=l[i][1][k];
				}
				if(tot==l[i][2])ans++;
			}
		}
		cout<<ans<<endl;
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


*/
