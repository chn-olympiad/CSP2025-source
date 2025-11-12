#include<bits/stdc++.h>
using namespace std;

long long n,q,ans,l,r;
char s[200005][3],t[200005][3],x[200005][3],y,z[200005][3],yw[200005][3],sn[200005][3]; 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int j=1;j<=q;j++){
		cin>>t[j][1]>>t[j][2];
	}
	for(int i=1;i<=n;i++){
		y[i][1]=s[l][r];
		if(y=s[i][1]){
			yw[200005][3]=s[i][2];
		}
		s[i][1]=x+y+z;
		if(x+yw[i][2]+z==s[i][2]){
			ans++;
		}
	}
	fclose(stdin);
	fclose(stdout);
	cout<<ans;
	return 0;
}
