#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,q;
string s[400010];
string a,b;
int cz(string sk,int l,int r,string skr){
	int siz=a.size();
	for(int i=1;i<=2*n;i+=2){
		if(sk==s[i+1]&&skr==s[i]){
			bool p=true;
			for(int i=0;i<siz;i++){
				if(i>=l&&i<=r){
					continue;
				}
				else{
					if(b[i]!=a[i]){
						p=false;
						break;
					}
				}
			}
			if(p){
				return 1;	
			}
		}
	}
	return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n*2;i+=2){
		cin>>s[i]>>s[i+1];
	} 
	while(q--){
		int ans=0;
		cin>>a>>b;
		string ank="";
		string anks="";
		int siz=b.size();
		for(int i=0;i<siz;i++){
			for(int j=i;j<siz;j++){
				ank+=b[j];
				anks+=a[j];
				if(cz(ank,i,j,anks)==1){
					ans++;
					cout<<ank<<"\n";
				}
			}
			ank="";
			anks="";
		}
		cout<<ans<<"\n";
	}
	return 0;
}
