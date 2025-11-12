#include<bits/stdc++.h>
using namespace std;
long long n,q,ans;
int nn[20005];
string t1[20005],t2[20005],tt1,tt2;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(long long i=1;i<=n;i++){
		cin>>t1[i]>>t2[i];
		t1[i]=" "+t1[i];
		t2[i]=" "+t2[i];
		nn[i]=t1[i].size()-1;
	}
	for(long long i=1;i<=q;i++){
		ans=0;
		cin>>tt1>>tt2;
		int l=tt1.size();
		if(tt1.size()!=tt2.size()){
			cout<<"0\n";
			continue;
		}
		tt1=" "+tt1;
		tt2=" "+tt2;
		int lll,rrr;
		for(int j=1;j<=n;j++){
			if(tt1[j]!=tt2[j]){
				lll=j;
				break;
			}
		}
		for(int j=n;j>=1;j--){
			if(tt1[j]!=tt2[j]){
				rrr=j;
				break;
			}
		}
		for(register int j=1;j<=n;j++){
			for(register int k=1;k<=l-nn[j]+1;k++){
				if(k>lll||nn[j]+k-1<rrr) continue;
				bool f=0;
				for(register int l=1;l<=nn[j];l++){
					int ttt=l+k-1;
					if(tt1[ttt]!=t1[j][l]||tt2[ttt]!=t2[j][l]){
						f=1;
						break;
					}
				}
				if(f==0){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
