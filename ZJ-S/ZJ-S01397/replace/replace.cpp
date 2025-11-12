#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,q,ans=0;
string s[200005][3],w[200005][3];
int main(){   
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);  
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>w[i][1]>>w[i][2];
		w[i][1]=' '+w[i][1];
		w[i][2]=' '+w[i][2];
	}
		for(int i=1;i<=q;i++){
			ans=0;
			cin>>s[i][1]>>s[i][2];
			s[i][1]=' '+s[i][1];
			s[i][2]=' '+s[i][2];
			for(int j=1;j<=n;j++){
				int r=0,l=1;
				bool flag=false;
				for(int ij=1;ij<=s[i][1].size();ij++){
					if(l==w[i][1].size()){
						r=ij;
						flag=true;
						break;
					}
//					cout<<(s[i][1][ij]==w[i][1][l])<<"\n";
					if(s[i][1][ij]==w[i][1][l]){
						l++;
					}else{
						l=1;
					}
					
				}
				if(flag){
					string x=s[i][1];
					for(int ij=r-l+1;ij<=r;ij++){
						x[ij]=w[i][2][ij-(r-l)];
					}
					if(x==s[i][2]){
						ans++;
					}					
				}

//				cout<<x<<"\n";
//				cout<<l<<" "<<r<<"\n";
			}
	cout<<ans<<"\n";
		}	

	return 0;
}
/*
Ren5Jie4Di4Ling5%

4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

1000 2000
*/