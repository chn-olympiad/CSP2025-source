#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],num0,num1;
bool isit1=1,isit2=1;
int read(){
	int res=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res*f;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]!=1) isit1=0;
		if(a[i]>1) isit2=0;
	}
	if(isit1&&k==0){
		cout<<n/2;
		return 0;
	}
	if(isit2&&(k==1||k==0)){
		for(int i=1;i<=n;i++){
			if(a[i]==0) num0++;
			else num1++;
		}
		if(k==1){
			cout<<min(num1,num0);
			return 0;
		}else{
			cout<<num1/2+num0/2;
			return 0;
		}
	}
}
