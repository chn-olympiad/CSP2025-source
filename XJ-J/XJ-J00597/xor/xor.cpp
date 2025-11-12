#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,k,p=0,f=0,ans=0;
int a;
int vaa[N][20];
int s[20],b[20],vis[20];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	p=0;
	while(k>0){
		s[p]=k%2;
		k=k/2;
		p++;
	}
	p--;
	for(int j=19,pp=0;pp<=p;j--,pp++){
		b[j]=s[pp];
	}
	for(int i=0;i<n;i++){
		cin>>a;
		p=0;
		while(a>0){
			s[p]=a%2;
			a=a/2;
			p++;
		}
		p--;
		for(int j=19,pp=0;pp<=p;j--,pp++){
			vaa[i][j]=s[pp];
		}
		for(int j=0;j<20;j++) vis[j]=(vis[j]+vaa[i][j])%2;
		f=0;
		for(int j=0;j<20;j++) if(vis[j]!=b[j]){ f=1;break;}
		if(f==0){
			ans++;
			memset(vis,0,sizeof(vis));
		}
	}
	cout<<ans;
	return 0;
}
