#include<bits/stdc++.h>
using namespace std;
int ans,len[200005];
string a[200005],b[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		len[i]=a[i].size();}
	if(m==1||n<=1000)
		while(m--){
			ans=0;
			string x,y;
			cin>>x>>y;
			int s=x.size();
			for(int i=1;i<=n;i++){
				for(int k=0;k<s-len[i]+1;k++)
					for(int j=0;j<len[i];j++){
						if(a[i][j]!=x[k+j]) break;
						if(j==len[i]-1){
							for(int l=0;l<len[i];l++)
								x[k+l]=b[i][l];
							if(x==y) ans++;
							for(int l=0;l<len[i];l++)
								x[k+l]=a[i][l];}}}
			cout<<ans<<"\n";}
	else for(int i=1;i<=m;i++) cout<<0<<"\n";
	return 0;
}