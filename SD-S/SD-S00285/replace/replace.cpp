#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,l,ll,rr,ls[200009],rs[200009],f,da;
string s1[200009],s2[200009],t1,t2;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		l=s1[i].size();
		for(int j=0;j<l;j++){
			if(s1[i][j]!=s2[i][j]){
				ls[i]=j;
				for(int k=l-1;k;k--){
					if(s1[i][k]!=s2[i][k]){
						rs[i]=k;
						break;
					}
				}
				break;
			}
		}
	}
	while(q--){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<"0\n";
			continue;
		}
		l=t1.size();da=0;
		for(int i=0;i<l;i++){
			if(t1[i]!=t2[i]){
				ll=i;
				for(int j=l-1;j;j--){
					if(t1[j]!=t2[j]){
						rr=j;
						break;
					}
				}
				break;
			}
		}
//		cout<<ll<<" "<<rr<<"\n";
		for(int i=1,xx;i<=n;i++){
			xx=s1[i].size();f=0;
			if(xx<rr-ll+1 or rs[i]-ls[i]+1!=rr-ll+1 or ll<ls[i] or rr+xx-rs[i]>l)continue;
//			cout<<i<<" ";
			for(int j=ll-ls[i],jj=0;j<rr+xx-rs[i] and jj<xx;j++,jj++){
				if(t1[j]!=s1[i][jj] or t2[j]!=s2[i][jj]){
					f=1;break;
				}
			}
			if(!f)da++;
		}
//		cout<<"\n";
		cout<<da<<"\n";
	}
	return 0;
}

