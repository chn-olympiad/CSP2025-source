#include<bits/stdc++.h>
using namespace std;
int n,m;
string stra[100005],strb[100005],strc,strd;
long long max(long long a,long long b){
	return a>b?a:b;
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>stra[i]>>strb[i];
	}
	for(int u=1; u<=m; u++) {
		cin>>strc>>strd;
		long long ans=0;
		long long l=0,r=strc.size();
		while(strc[l]==strd[l])l++;
		while(strc[r]==strd[r])r--;
		for(int i=1; i<=n; i++) {
			for(int j=max(r-stra[i].size()-1,0); j<l+stra[i].size()+1; j++) {
				bool flag=1;
				for(int k=j; k-j<stra[i].size(); k++) {
					if(strc[k]!=stra[i][k-j]){
						flag=0;
						continue;
					}
				}
//				cout<<stra[i]<<endl;
				if(flag){
					string stre=strc;
					for(int k=j;k-j<stra[i].size();k++){
						stre[k]=strb[i][k-j];
					}
//					cout<<stre<<" "<<strd<<endl;
					if(stre==strd)ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
