#include<bits/stdc++.h>
using namespace std;
int n,k;
long long sum[500005];
int a[500005];
int p[25];
long long answer=0;
void pw(){
	p[0]=1;
	for(int i=1;i<=21;i++){
		p[i]=p[i-1]*2;
	}
	return;
}
int xorr(int a,int b){
	if(a<b)swap(a,b);
	int er[25];
	int ind=0,ans=0;
	while(b>=1){
		int wa=a%2;
		int wb=b%2;
		ind++;
		if(wa!=wb){
			er[ind]=1;
		}else{
			er[ind]=0;
		}
		a/=2;
		b/=2;
	}
	while(a>=1){
		int wa=a%2;
		ind++;
		if(wa==1){
			er[ind]=1;
		}else{
			er[ind]=0;
		}
		a/=2;
	}
	for(int i=ind;i>=1;i--){
		ans+=er[i]*p[i-1];
	}
	return ans;
}
void dfs(int l,long long cnt){
	if(l>n){
		answer=max(answer,cnt);
		return;
	}
	for(int r=l;r<=n;r++){
		if(sum[r]+sum[l-1]==k){
			dfs(r+1,cnt+1);
			//break;//no more 
		}
	}
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	sum[1]=0;
	pw();
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(i==1){
			sum[1]=a[i]; 
			//cout<<sum[i]<<" ";
			continue;
		}
		sum[i]=xorr(sum[i-1],a[i]);//qianzuihe?
		//cout<<sum[i]<<" ";
	}
	//cout<<"\n"<<abs(sum[5]+sum[2-1]);!!!!
	dfs(1,0);
	printf("%lld",answer);
	return 0;
}
