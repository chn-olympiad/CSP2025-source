#include <bits/stdc++.h>
using namespace std;
struct stru{
	string sa,sb;
	int c,d,e;
};
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,q;cin>>n>>q;
	stru s1[n];
	stru s2[q];
	for (int i=0;i<n;i++){
		cin>>s1[i].sa>>s1[i].sb;s1[i].e=s1[i].sa.size();
			for (int j=0;j<s1[i].e;j++){
				if (s1[i].sa[j]=='b'){
					s1[i].c=j;break;
				}
			}
			for (int j=0;j<s1[i].e;j++){
				if (s1[i].sb[j]=='b'){
					s1[i].d=j;break;
				}
			}
	}
	for (int i=0;i<q;i++){
		cin>>s2[i].sa>>s2[i].sb;s2[i].e=s2[i].sa.size();
			for (int j=0;j<s2[i].e;j++){
				if (s2[i].sa[j]=='b'){
					s2[i].c=j;break;
				}
			}
			for (int j=0;j<s2[i].e;j++){
				if (s2[i].sb[j]=='b'){
					s2[i].d=j;break;
				}
			}
			int ans=0;
			for (int j=0;j<n;j++){
				if(s1[j].e>s2[j].e)continue;
				else if(s2[i].sa.size()!=s2[i].sb.size())continue;
				else{
	if(s2[i].c>=s1[i].c&&s2[i].d>=s1[i].d&&(s2[i].e-1-s2[i].c)>=(s1[i].e-1-s1[i].c)&&(s2[i].e-1-s2[i].d)>=(s1[i].e-1-s1[i].d))ans++;
				}
			}
			cout<<ans<<endl;
	}
	return 0;
}
