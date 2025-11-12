#include<bits/stdc++.h>
using namespace std;

int n,m;
int knx[510];
char hl[510];
int pat[510];
int ytc[510];
long long ans=0;

int main(){
	//从后往前
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("\n%s",hl+1);
	for(int i=1;i<=m;i++){
		scanf("%d",&pat[i]);
		ytc[i]=ytc[i-1];
		if(hl[i-1]=='0')ytc[i]+=1;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=998244353;
		}
		printf("%lld",ans);
		return 0;
	}
		
	for(int i=n;i>=1;i--){
		if(hl[i-1]=='0')continue;
		for(int j=1;j<=n;j++){
			if(pat[j]<=ytc[i]){
				knx[i]++;
			}
		}
	}for(int i=n;i>=1;i--){
		if(knx[i]!=0){
			ans*=knx[i];
			ans%=998244353;
		}
	}
	printf("%lld",ans);
	return 0;
}