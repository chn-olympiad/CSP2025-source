#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,q;
string s1[201000],s2[201000],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	while(q--){
		cin>>t1>>t2;
		int L1=t1.size(),L2=t2.size();
		if(L1!=L2){
			cout<<0<<endl;
			continue;
		}
		int ans=0,l=L1,r=-1;
		for(int i=0;i<L1;i++)
			if(t1[i]!=t2[i]){
				l=i;
				break;
			}
		for(int i=L1-1;i>=0;i--)
			if(t1[i]!=t2[i]){
				r=i;
				break;
			}
		for(int i=0;i<=l;i++)	
			for(int j=1;j<=n;j++){
				int L=s1[j].size();
				if(i+L<L1+1&&i+L>=r+1){
					bool f=true;
					for(int k=0;k<L;k++)
						if(s1[j][k]!=t1[i+k]||s2[j][k]!=t2[i+k]){
							f=false;
							break;
						}
					if(f)
						ans++;
				}
			}
		cout<<ans<<endl;
	}
	return 0;
}
