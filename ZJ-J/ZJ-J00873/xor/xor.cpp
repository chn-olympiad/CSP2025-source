#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001];
long long mx=-1;
vector<pair<int,int>> g;
bool f[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int sxo=0;
		for(int j=i;j<=n;j++){
			sxo^=a[j];
			if(sxo==k)g.push_back({i,j});
		}
	}
	for(int i=0;i<g.size();i++){
		memset(f,0,sizeof(f));
		long long s=1;
		for(int j=g[i].first;j<=g[i].second;j++)f[j]=1;
		for(int j=0;j<g.size();j++){
			bool fl=1;
			for(int k=g[j].first;k<=g[j].second;k++)
				if(f[k]==1){
					fl=0;
					break;
				}
			if(fl){
				s++;
				for(int k=g[j].first;k<=g[j].second;k++)f[k]=1;
			}
		}
		mx=max(mx,s);
	}
	cout<<mx;
	fclose(stdin);fclose(stdout);
}
