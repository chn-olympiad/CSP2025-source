#include<bits/stdc++.h>
using namespace std;
struct data{
	int l,r,far;
};
int n,k,a[500005],ans;
bool vis[500005];
int read(){
	char c=getchar();
	int f=1,num=0;
	if(c<'0' || c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0' && c<='9'){
		num=num*10+c-'0';
		c=getchar();
	}
	return num*f;
}
int powk(int a,int b){
	if(b==0) return 1;
	int re=1;
	while(b>1){
		if(b%2==1){
			re*=a;
		}
		a*=a;
		b/=2;
	}
	return a*re;
}
int xor1(int a,int b){
	int a1[22],b1[22];
	memset(a1,0,sizeof(a1));
	memset(b1,0,sizeof(b1));
	while(a>0){
		a1[++a1[0]]=a%2;
		a/=2;
	}
	while(b>0){
		b1[++b1[0]]=b%2;
		b/=2;
	}
//	for(int i=1;i<=a1[0];i++) cout<<a1[i];
//	cout<<'\n';
//	for(int i=1;i<=b1[0];i++) cout<<b1[i];
//	cout<<'\n';
	a1[0]=max(a1[0],b1[0]);
	for(int i=1;i<=max(a1[0],b1[0]);i++){
		a1[i]=(!a1[i])|(!b1[i]);
	}
//	for(int i=1;i<=a1[0];i++) cout<<a1[i];
//	cout<<'\n';
	int num=0;
	while(a1[a1[0]]==0) a1[0]--;
//		for(int i=1;i<=a1[0];i++) cout<<a1[i];
//	cout<<'\n';
	for(int i=1;i<=a1[0];i++){
		num+=a1[i]*powk(2,i-1);
	}
	return num;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			if(vis[j]==1 || vis[j+i-1]==1) continue;
			int num=a[j];
			bool flag=1;
			for(int q=j+1;q<=j+i-1;q++){
				if(vis[q]==1){
					flag=0;
					break;
				}
				num=xor1(num,a[q]);
			}
			if(flag){
				if(num==k){
					ans++;
					for(int q=j;q<=j+i-1;q++){
						vis[q]=1;
					}
				}
			}
		}
	}
	cout<<ans<<'\n';
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/
