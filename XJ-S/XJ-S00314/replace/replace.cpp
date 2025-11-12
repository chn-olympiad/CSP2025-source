#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,q,l,r,f=1,cnt,ans;
string a[maxn][5],s1,s2,fr,to;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2];
	}
	while(q--){ans=0;
		cin>>s1>>s2;
		for(int i=1;i<=s1.length();i++){
			if(s1[i]!=s2[i]){
				l=i;break;
			}
		}
		for(int i=1;i<=s1.length();i++){
			if(s1[i]!='a'||s1[i]!='b'){
				f=0;break;
			}
		}
		for(int i=s1.length();i>=1;i--){
			if(s1[i]!=s2[i]){
				r=i;break;
			}
		}
		for(int i=l;i<=r;i++){
			fr+=s1[i];
			to+=s2[i];
		}
		if(f==0){cnt=(r-l+1);
			for(int i=1;i<=n;i++){
				
				if(a[i][1].length()>=cnt){
					for(int j=1;j<=a[i][1].length();j++){
						if(a[i][1][j]=='b'){
							l=i;break;
						}
					}
					for(int j=1;j<=a[i][2].length();j++){
						if(a[i][2][j]=='b'){
							r=i;break;
						}
					}
					if(r-l+1==cnt) ans++;
				}
			}
			cout<<ans<<'\n';
		}else{
			cout<<0<<'\n';
		}
		
		
	}
	return 0;
}
/*
4 1
ab aa
a b
aaab baaa
aaba abaa
aaaaaabaaa aaabaaaaaa
*/
