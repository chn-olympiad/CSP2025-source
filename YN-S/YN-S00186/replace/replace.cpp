#include<bits/stdc++.h>
#define NN 40005
using namespace std;
string s1[NN],s2[NN];
string a,b;
bool check(int j,int l,int r,int ll){
	for(int i=0;i<l;i++)if(a[i]!=b[i])return false;
	for(int i=l;i<=r;i++)if(a[i]!=s1[j][i-l])return false;
	for(int i=l;i<=r;i++)if(b[i]!=s2[j][i-l])return false;
	for(int i=r+1;i<ll;i++)if(a[i]!=b[i])return false;
	return true;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	for(int i=1;i<=q;i++){
		cin>>a>>b;
		int ans=0;int ll=a.size();
		for(int j=1;j<=n;j++){
			int l=s1[j].size();
			for(int k=0;k+l-1<ll;k++){
				if(check(j,k,k+l-1,ll))ans++;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}