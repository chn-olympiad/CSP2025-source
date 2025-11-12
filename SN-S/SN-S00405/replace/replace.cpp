#include<bits/stdc++.h>
using namespace std;
int n,q,m,l,r,ans,a[200005];
string s[2][200005],t[2];
void p(){
	ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=min(m-a[i]+1,l+1);j++){
			if(j+a[i]-1<r-1){
				continue;
			}
			int u=1;
			for(int k=j;k<=j+a[i]-1;k++){
				if(s[0][i][k-j+1]!=t[0][k]||s[1][i][k-j+1]!=t[1][k]){
					u=0;
					break;
				}
			}
			ans+=u;
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[0][i]>>s[1][i];
		a[i]=s[0][i].size();
		s[0][i]=' '+s[0][i];
		s[1][i]=' '+s[1][i];
	}
	for(int i=1;i<=q;i++){
		cin>>t[0]>>t[1];
		m=t[0].size();
		t[0]=' '+t[0];
		t[1]=' '+t[1];
		l=0;
		for(int j=1;j<=m;j++){
			if(t[0][j]==t[1][j]){
				l++;
			}
			else{
				break;
			}
		}
		r=m+1;
		for(int j=m;j>=1;j--){
			if(t[0][j]==t[1][j]){
				r--;
			}
			else{
				break;
			}
		}
		p();
	}
}
