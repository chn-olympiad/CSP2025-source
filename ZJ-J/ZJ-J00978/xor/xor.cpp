#include<bits/stdc++.h>
using namespace std;
int n;
long long k;
long long yh[500005],a[500005];
long long b[500005];
bool vis[500005];
long long f(long long q,long long h){
	char qq[50],hh[50],answer[50];
	for(int i=1;i<=40;i++){
		qq[i]='0';
		hh[i]='0';
	}
	int wzq=0;
	while(q>0){
		char c;
		if(q%2==0)c='0';
		else c='1';
		qq[++wzq]=c;
		q/=2;
	}
	int wzh=0;
	while(h>0){
		char c;
		if(h%2==0)c='0';
		else c='1';
		hh[++wzh]=c;
		h/=2;
	}
	int wz=max(wzq,wzh);
	for(int i=wz;i>=1;i--){
		if((qq[i]=='1'&&hh[i]=='0')||(qq[i]=='0'&&hh[i]=='1')){
			answer[i]='1';
		}
		else{
			answer[i]='0';
		}
	}
	long long ans=0,mol=2;
	for(int i=wz;i>=1;i--){
		if(i==wz&&answer[i]=='1'){
			ans++;
			continue;
		}
		if(answer[i]=='1')ans=ans+mol;
		mol*=2;
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(i>=2)yh[i]=f(a[i-1],a[i]);
		b[i]=b[i-1]+yh[i];	
	}
	if(k==0){
		printf("%d",n/2);
		return 0;
	}
	int cnt=0;
	for(int l=1;l<=n;l++){
		if(b[l]==1){
			int x=l+1;
			while(b[l]!=1)x++;
			l=x+1;
		}
		for(int r=l;r<=n;r++){
			if(b[r]-b[l+1]==k){
				b[r]=1;
				b[l]=1;
				cnt++;
			}
		}
	}
	printf("%d",cnt);
	return 0;
}
/*
4 3
2 1 0 3
*/
