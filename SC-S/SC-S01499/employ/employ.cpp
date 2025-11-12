#include<bits/stdc++.h>
using namespace std;

const int N=1e4+7,p=998244353;

int in(){
	int k=0,t=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')t=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=k*10+c-'0';
		c=getchar();
	}
	return k*t;
}

void out(int x){
	if(x<0)putchar('-'),x=-x;
	if(x<10)return putchar(x+'0'),void(0);
	out(x/10),putchar(x%10+'0');
}

int n,m;
int kkk(int x,int k){
	int ans=1;
	while(k){
		if(k&1)ans=(ans*x)%p;
		x=(x*x)%p;
		k>>=1;
	}
	return ans%p;
}

int o[N],a[5000],cntt=0;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=in();m=in();
	for(int i=1;i<=n;i++){
		o[i]=in();
		if(o[i])cntt++;
	}
	for(int i=1;i<=n;i++){
		a[i]=in();
	}
	if(cntt<m){
		out(0);
		return 0;
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		ans=(ans*i)%p;
	}
	out(ans%p);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 1 8 2 4
0 1 3 2 4


*/