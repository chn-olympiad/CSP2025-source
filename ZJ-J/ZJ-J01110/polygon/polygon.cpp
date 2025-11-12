#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
long long ans=0;
int anss[2005];
void dfs(int depth,int maxx,int cnt,int k,int last){
	if(k>2 && cnt>maxx*2 && last==1){
		ans++;
	}
	if(depth>n) return;
	dfs(depth+1,max(maxx,a[depth]),cnt+a[depth],k+1,1);
	dfs(depth+1,maxx,cnt,k,0);
}
void op(int x){
	int pos=2000;
	anss[1]=1;
	for(int i=1;i<=x;i++){
		for(int j=1;j<=2000;j++){
			anss[j]*=2;
		}
		for(int j=1;j<=2000;j++){
			if(anss[j]>9){
				anss[j+1]+=anss[j]/10;
				anss[j]%=10;
			}
		}
	}
	anss[1]=anss[1]-1-n-n*(n-1)/2;
	for(int i=1;i<=2000;i++){
		if(anss[i]<0){
			int r=abs(anss[i]);
			if(r%10==0){
				anss[i+1]=anss[i+1]-r/10;
				anss[i]=0;  
			}
			else{
				anss[i+1]=anss[i+1]-r/10-1;
				anss[i]=10-r%10;
			}
		}
	}
	while(anss[pos]==0 && pos>1) pos--;
	for(int i=pos;i>=1;i--){
		cout<<anss[i];
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n<=20){
		dfs(1,0,0,0,0);
		cout<<ans;
	}
	else op(n);
	return 0;
}
