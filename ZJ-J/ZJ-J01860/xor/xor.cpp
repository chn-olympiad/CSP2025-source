#include<bits/stdc++.h>
using namespace std;
long long int s[500005];
int vis[500005];
int main(){
	//Òì»òºÍ·ûºÅ ^ c=a^b;
	freopen("xor.in","r",stdin);
 	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int ans=0;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		s[i]=(s[i-1]^a);
		//cout<<s[i];
	}
	for(int i=1;i<=n;i++){
		for(int o=1;o+i-1<=n;o++){
			if(vis[o])continue;
			int xo;
			if(i!=1)xo=s[o+i-1]^s[o-1];
			else xo=s[o]^s[o-1];
			if(xo==k){
				bool ok=true;
				for(int j=o;j<=o+i-1;j++){
					if(vis[j]==1){
						ok=false;
						break;
					}
				}
				if(!ok)continue;
				for(int j=o;j<=o+i-1;j++)vis[j]=1;
				//cout<<o<<' '<<o+i-1<<' '<<xo<<'\n';
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}

