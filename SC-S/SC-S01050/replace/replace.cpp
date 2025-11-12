#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int len[200001];
int az[200001],bz[200001];
int ay[200001],by[200001];
string a[200001],b[200001];
string x,y;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=n;i++){
		len[i]=a[i].length();
		for(int j=0;j<len[i];j++){
			if(a[i][j]=='b'){
				az[i]=j;
				ay[i]=len[i]-j-1;
			}
			if(b[i][j]=='b'){
				bz[i]=j;
				by[i]=len[i]-j-1;
			}
		}
	}
	while(m--){
		cin>>x>>y;
		int lenx=x.length();
		int leny=y.length();
		if(lenx!=leny){
			cout<<0<<'\n';
			continue;
		}else{
			ans=0;
			int xz=0,xy=0,yz=0,yy=0;
			for(int i=0;i<lenx;i++){
				if(x[i]=='b'){
					xz=i;
					xy=lenx-i-1; 
				}
				if(y[i]=='b'){
					yz=i;
					yy=lenx-i-1;
				}
			}
			int der=xz-yz;
			for(int i=1;i<=n;i++){
				int dd=az[i]-bz[i];
				if(dd==der && xz>=az[i] && xy>=ay[i] && yz>=bz[i] && yy>=by[i]){
					ans++;
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
} 