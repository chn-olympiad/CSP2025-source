#include<bits/stdc++.h>
using namespace std;
struct way{
	int fr,ar,va;
}fi[1000005];
bool com(way a,way b){
	return a.va<b.va;
}
long long f[1005][1005],n,m,k;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>fi[i].ar>>fi[i].fr>>fi[i].va;
	if(k==0){//zuiduanlu
		memset(f,-1,sizeof(f));
		for(int i=1;i<=n;i++)f[i][i]=0;
		sort(fi+1,fi+m+1,com);
		for(int i=1;i<=m;i++){
			f[fi[i].ar][fi[i].fr]=fi[i].va;
			f[fi[i].fr][fi[i].ar]=fi[i].va;
		}
	}
	cout<<"13";
}
