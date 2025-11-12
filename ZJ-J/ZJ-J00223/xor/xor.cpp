#include<bits/stdc++.h>//I LOVE CCF
#define int long long//I LOVE CCF
using namespace std;//I LOVE CCF
inline int read() {//I LOVE CCF
	int x=0,f=1;//I LOVE CCF
	char c=getchar();//I LOVE CCF
	while(c<'0'||c>'9') {//I LOVE CCF
		if(c=='-')f=-1;//I LOVE CCF
		c=getchar();//I LOVE CCF
	}//I LOVE CCF
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();//I LOVE CCF
	return x*f;//I LOVE CCF
}//I LOVE CCF
int n,k,sum;//I LOVE CCF
int a[500005];//I LOVE CCF
signed main() {//I LOVE CCF
	freopen("xor.in","r",stdin);//I LOVE CCF
	freopen("xor.out","w",stdout);//I LOVE CCF
	n=read(),k=read();//I LOVE CCF
	for(int i=1;i<=n;i++)a[i]=read();//I LOVE CCF
	int last=a[1];//I LOVE CCF
	for(int i=2;i<=n;i++){//I LOVE CCF
		if(last==k){//I LOVE CCF
			sum++;//I LOVE CCF
			last=a[i];//I LOVE CCF
		}
		else last^=a[i];
	}
	if(last==k)sum++;
	cout<<sum<<'\n';
	return 0;
}


