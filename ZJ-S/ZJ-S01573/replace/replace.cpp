#include<bits/stdc++.h>
#include<string.h>
using namespace std;
long long mod=998244353,n,q,ans;
string p1[200005],p2[200005],q1[200005],q2[200005];
string strca(string s,int l,int r){
	string s1;
	for(int i=l,j=0;i<r;i++,j++)s1[j]=s[i];
	return s;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>p1[i]>>p2[i];
	for(int i=1;i<=q;i++)cin>>q1[i]>>q2[i];
	for(int i=1;i<=q;i++){
		for(int j=1;j<q1[i].size();j++){
			for(int k=j;k<q1[i].size();k++){
				string x=strca(q1[i],0,j),y=strca(q1[i],j,k-j),z=strca(q1[i],k,q1[i].size());
				string xa=strca(q2[i],0,j),ya=strca(q2[i],j,k),za=strca(q2[i],k,q1[i].size());
				for(int l=1;l<=n;l++){
					int ccccc=0;
					if(x==xa||x!=xa&&x==p1[l]&&xa==p2[l])ccccc++;
					if(y==ya||y!=ya&&y==p1[l]&&ya==p2[l])ccccc++;
					if(z==za||z!=za&&z==p1[l]&&za==p2[l])ccccc++;
					if(ccccc==3)ans++;
					ans%=mod;
				}
			}
		}
		cout<<ans<<endl;
		ans=0; 
	}
	return 0;
}