#include<bits/stdc++.h>
using namespace std;
long long n,q,l,ans,a[200005];
map<string,int> d;
map<int,int> f;
string x,y,str,srt;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie();
	cout.tie();
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		d[x+y]=1;
		f[x.size()]=1;
	}
	while(q--){
		cin>>x>>y;
		ans=0;
		l=x.size();
		memset(a,0,sizeof(a));
		for(int i=0;i<l;i++){
			a[i]=a[i-1];
			if(x[i]!=y[i])a[i]++;
		}
		for(int i=0;i<l;i++){
			for(int j=i;j<l;j++){
				
				if(f[j-i+1]==0||a[i-1]!=0||a[l-1]-a[j]!=0)continue;
				
				str=x.substr(i,j-i+1);
				srt=y.substr(i,j-i+1);
				//if(i==2&&j==3)cout<<str<<' '<<srt;
				if(d[str+srt]==1){
					ans++;
					
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
