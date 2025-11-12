#include <bits/stdc++.h>
using namespace std;
int bao1,bao2,xx,i,j,n,T,ans;
string a,b,x,y;
map<string,bool>f1,f2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>T;
	for(i=1;i<=n;i++) cin>>a>>b,f1[a]=1,f2[b]=1;
	while(T--){
		ans=0;
		bao1=bao2=-1;
		cin>>x>>y;
		xx=x.size();
		for(i=0;i<xx;i++)
			if(x[i]!=y[i]){
				bao1=i;
				break;
			}
		for(i=xx-1;i>=0;i--)
			if(x[i]!=y[i]){
				bao2=i;
				break;
			}
		for(i=0;i<=bao1;i++)
			for(j=bao2;j<xx;j++)
				if(f1[x.substr(i,j-i+1)]==1&&f2[y.substr(i,j-i+1)]==1)
					ans++;
		cout<<ans<<"\n";
	}
	return 0;
}

//25+ TLE
