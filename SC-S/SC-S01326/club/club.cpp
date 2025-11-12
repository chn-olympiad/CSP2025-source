#include<bits/stdc++.h>
using namespace std;
int s[100010][5],n,t,f[5][5][100010];
unsigned long long maxx;
int main(){
	ios::sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		
	
		for(int x=1;x<=n;x++)
			for(int j=1;j<=3;j++)
				cin>>s[x][j];
				
				
		for(int x=1;x<=n;x++){
			int tmp=-1;
			for(int j=1;j<=3;j++)
				tmp=max(tmp,s[x][j]);
			maxx+=tmp;
		}
				
		cout<<maxx<<"\n";
		maxx=0;
	}
	return 0;
}