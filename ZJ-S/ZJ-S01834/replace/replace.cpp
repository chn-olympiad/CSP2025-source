#include<bits/stdc++.h>
#define P 991147
using namespace std;
int n,q,L1,L2,ss;
unsigned long long p[5000001],ht[3][5000001],hs[200001][3];
string t[3],s[200001][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	p[0]=1;
	for(int i=1;i<=5000000;i++)p[i]=p[i-1]*P;
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i][1]>>s[i][2],L1+=s[i][1].length();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2;j++){
			for(int k=0;k<s[i][j].length();k++){
				hs[i][j]+=p[k+1]*s[i][j][k];
			}
		}
	}
	if(L1<=1000){
		for(;q;q--){
			cin>>t[1]>>t[2];
			if(t[1].length()!=t[2].length()){
				cout<<0<<'\n';
				continue;
			}
			for(int j=1;j<=2;j++)for(int k=0;k<t[1].length();k++)ht[j][k+1]=ht[j][k]+p[k+1]*t[j][k];
			ss=0;
			for(int i=1;i<=n;i++){
				for(int k=0;k<t[1].length()-s[i][1].length()+1;k++){
					ss+=((ht[1][k+s[i][1].length()]-ht[1][k])==hs[i][1]*p[k]&&(ht[1][t[1].length()]-hs[i][1]*p[k]+hs[i][2]*p[k])==ht[2][t[2].length()]);
				}
			}
			cout<<ss<<'\n';
		}
		return 0;
	}
	for(;q;q--)cout<<0<<'\n';
	return 0;
}

