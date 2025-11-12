#include<bits/stdc++.h>//20pts
#define int long long
#define INF 1145141919810
using namespace std;
int n,q;
string s1[320001],s2[320001];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	for(int sylorz=1;sylorz<=q;sylorz++){
		string t1,t2,dif1="",dif2="";
		cin>>t1>>t2;
		int l,r;
		for(int i=0;i<t1.size();i++)
			if(t1[i]!=t2[i]){
				l=i;
				break;
			}
		for(int i=t1.size()-1;i>=0;i--)
			if(t1[i]!=t2[i]){
				r=i;
				break;
			}
		for(int i=l;i<=r;i++)
			dif1+=t1[i];
		for(int i=l;i<=r;i++)
			dif2+=t2[i];
		int ans=0;
		for(int i=1;i<=n;i++){
			int kl=t1.find(s1[i]);
			int kr=kl+s1[i].size()-1;
			if(t1.find(s1[i])==t2.find(s2[i])&&t1.find(s1[i])<INF&&kl<=l&&r<=kr)
				ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}