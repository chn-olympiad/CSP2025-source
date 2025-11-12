#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int B=46;
const int mod=998244353;
string s[N][2];
long long H[N][2];
long long b[5000010];
long long H1[2][5000010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	b[0]=1;
	for(int i=1;i<=5000000;i++){
		b[i]=(b[i-1]*B)%mod;
	}
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		int sz=s[i][0].size();
		H[i][0]=s[i][0][0]-'a';
		for(int j=1;j<sz;j++){
			H[i][0]=(H[i][0]*B%mod+s[i][0][j]-'a')%mod;
		}
		H[i][1]=s[i][1][0]-'a';
		for(int j=1;j<sz;j++){
			H[i][1]=(H[i][1]*B%mod+s[i][1][j]-'a')%mod;
		}
	}
	string a,b;
	while(q--){
		cin>>a>>b;
		int sz=a.size();
		H1[0][0]=a[0]-'a';
		for(int i=1;i<sz;i++){
			H1[0][i]=(H1[0][i-1]*B%mod+a[i]-'a')%mod;
		}
		H1[1][0]=b[0]-'a';
		for(int i=1;i<sz;i++){
			H1[1][i]=(H1[1][i-1]*B%mod+b[i]-'a')%mod; 
		}
		int l=0,r=n-1;
		while(a[l]==b[l]){
			l++;
		}
		while(r>=l&&a[r]==b[r]){
			r--;
		}
		if(n<=100){
			long long ans=0;
			for(int i=1;i<=n;i++)if((int)s[i][0].size()>=r-l+1){
				if(r<l){
					for(int j=0;j+(int)s[i][0].size()<=sz;j++){
						int L=j,R=j+s[i][0].size()-1;
						long long x0=0,y0=(H1[0][sz-1]-H1[0][R]*b[sz-1-R]%mod+mod)%mod,x1=0,y1=(H1[1][sz-1]-H1[1][R]*b[sz-1-R]%mod+mod)%mod;
						if(L>0){
							x0=H1[0][L-1];
							x1=H1[1][L-1];
						}
						if((x0+H[i][0]*b[j]%mod+y0)%mod==H1[0][sz-1]&&(x1+H[i][1]*b[j]%mod+y1)%mod==H1[1][sz-1]){
							ans++;
						}
					}
				}else{
					for(int j=max(0,r-(int)s[i][0].size()+1);j<=l&&j+(int)s[i][0].size()<=sz;j++){
						int L=j,R=j+s[i][0].size()-1;
						long long x0=0,y0=(H1[0][sz-1]-H1[0][R]*b[sz-1-R]%mod+mod)%mod,x1=0,y1=(H1[1][sz-1]-H1[1][R]*b[sz-1-R]%mod+mod)%mod;
						if(L>0){
							x0=H1[0][L-1];
							x1=H1[1][L-1];
						}
						if((x0+H[i][0]*b[j]%mod+y0)%mod==H1[0][sz-1]&&(x1+H[i][1]*b[j]%mod+y1)%mod==H1[1][sz-1]){
							ans++;
						}
					}
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
//4 2
//xabcx xadex
//ab cd
//bc de
//aa bb
//xabcx xadex
//aaaa bbbb

