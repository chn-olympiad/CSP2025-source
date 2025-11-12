#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n,q,ans;
string a[N][2],t[N][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i][0];
		cin>>a[i][1];
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][0];
		cin>>t[i][1];
		ans=0;
		for(int j=1;j<=n;j++){
			if(t[i][0].find(a[j][0])!=-1){
				string k=t[i][0];
				k.replace(k.find(a[j][0]),a[j][0].size(),a[j][1]);
				if(k==t[i][1]){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
