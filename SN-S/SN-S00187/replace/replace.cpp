#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,q,slen[200010];
string s1[200010],s2[200010],jx[200010],jy[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		slen[i]=s1[i].size();
	}
	for(int i=1;i<=q*2;i++){
		cin>>jx[i]>>jy[i];
		string d=jx[i],b=jy[i];
		int sum=0;
		for(int j=1;j<=jx[i].size();i++){
			for(int f=1;f<=n;f++){
				ll ans=0;
				string jj=s1[f],jg=s2[f];
				for(int g=j;g<j+slen[f];g++){
					if(d[g]!=jj[g]||jg[g]!=b[g]||d!=jj||b!=jg){
						ans=1;
						break;
					}
				}
				if(ans==0) sum++;
			}
		}
		if(sum!=0) cout<<sum+1<<"\n";
		else cout<<sum<<"\n";
	}
	return 0;
}
