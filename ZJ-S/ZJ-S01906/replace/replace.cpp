#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
int n,q;
unsigned long long has[1000005][2],h[1000005][2],f[1000005];
string str[10005][2];
void gethash(string x,int flag){
	int len=x.size();
	h[0][flag]=x[0]-'a';
	for(int i=1;i<len;i++){
		h[i][flag]=h[i-1][flag]*26+x[i]-'a';
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>str[i][0]>>str[i][1];
	f[0]=1;for(int i=1;i<=10000;i++) f[i]=f[i-1]*26;
	for(int i=1;i<=n;i++){
		int len=str[i][0].size();
		has[i][0]=str[i][0][0]-'a';
		for(int j=1;j<len;j++){
			has[i][0]*=26;has[i][0]+=str[i][0][j]-'a';
		}
		has[i][1]=str[i][1][0]-'a';
		for(int j=1;j<len;j++){
			has[i][1]*=26;has[i][1]+=str[i][1][j]-'a';
		}
	}
	while(q--){
		string a,b;
		cin>>a>>b;
		gethash(a,0);gethash(b,1);
		if(a.size()!=b.size()){
			cout<<0<<endl;
			continue;
		}
		int l=-1,r=-1;
		for(int i=0;i<a.size();i++){
			if(a[i]!=b[i]){
				if(l==-1) l=i;
				r=i;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<a.size();j++){
				if(j<=l&&j+str[i][0].size()-1>=r&&j+str[i][0].size()-1<a.size()&&(h[j+str[i][0].size()-1][0]-(j==0?0:h[j-1][0])*f[str[i][0].size()])==has[i][0]&&(h[j+str[i][1].size()-1][1]-(j==0?0:h[j-1][1])*f[str[i][0].size()])==has[i][1]){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
