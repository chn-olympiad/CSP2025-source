#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
int n,a[maxn],ans;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
void DFS(int Max,int Maxi,int step,int sum){
	if(step==Maxi){
		if(sum>Max)ans=(ans+1)%998244353;
		return;
	}
	for(int i=step+1;i<=Maxi;i++)DFS(Max,Maxi,i,sum+a[step]);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)DFS(a[i]*2,i+1,0,0);
	printf("%d\n",ans);
	return 0;
}