#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int MOD=998244353;
#define LL long long
int in(){
	char cc=getchar();
	int aa=0,bb=1;
	while(cc<'0'||cc>'9'){
		if(cc=='-')	bb=-1;
		cc=getchar();
	}
	while(cc>='0'&&cc<='9'){
		aa=aa*10+cc-'0';
		cc=getchar();
	}
	return aa*bb;
}
void out(LL aa){
	if(aa<0){
		aa=-aa;
		putchar('-');
	}
	if(aa<=9)	putchar(aa+'0');
	else{
		out(aa/10);
		putchar(aa%10+'0');
	}
	return ;
}

int x[N],c[N];
bool b[N];
bool f1(int n,int m){
	int yes=0,no=0;
	for(int i=1;i<=n;i++){//x[i]
		if(b[i]==0)	no++;
		else{
			if(no>=c[x[i]])	no++;
			else{
				yes++;
				if(yes>=m)	return 1;
			}
		}
	}
	if(yes>=m)	return 1;
	else return 0;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n=in(),m=in();
	if(n<=18){
		LL ans=0;
		for(int i=1;i<=n;i++){
			char cx=getchar();
			if(cx=='0')	b[i]=0;
			else b[i]=1;
			x[i]=i;
		}
		for(int i=1;i<=n;i++)	c[i]=in();
		LL len=1;
		for(int i=1;i<=n;i++)	len*=i;
		while(len--){
			if(f1(n,m)){
				ans++;
				ans%=MOD;
			}
			next_permutation(x+1,x+n+1);
		}
		out(ans);
	}
	else if(m==1){
		LL ans=0;
		int first=-1;
		for(int i=1;i<=n;i++){
			char cx=getchar();
			if(cx=='0')	b[i]=0;
			else{
				b[i]=1;
				if(first==-1)	first=i;
			}	
		}
		LL k=1;
		for(LL i=1;i<n;i++){
			k*=i;
			k%=MOD;
		}
		for(int i=1;i<=n;i++){
			c[i]=in();
			if(first!=-1&&c[i]>=first){
				ans+=(int)k;
				ans%=MOD;
			}
		}
		out(ans);
	}
	else if(m==n){
		LL ans=0;
		for(int i=1;i<=n;i++){
			char cx=getchar();
			if(cx=='0'){
				b[i]=0;
				putchar('0');
				return 0;
			}
			else{
				b[i]=1;
			}	
		}
		for(int i=1;i<=n;i++){
			c[i]=in();
			if(c[i]==0){
				putchar('0');
				return 0;
			}
		}
		LL k=1;
		for(LL i=1;i<=n;i++){
			k*=i;
			k%=MOD;
		}
		out(k);
	}
	else{
		int ans=0;
		for(int i=1;i<=n;i++){
			char c=getchar();
			if(c=='0')	b[i]=0;
			else b[i]=1;
		}
		int k=n;
		for(int i=1;i<=n;i++){
			c[i]=in();	
			if(c[i]==0)	k--;
		}
		if(k<m){
			putchar('0');
			return 0;
		}
		LL len=1;
		for(int i=1;i<=k;i++){
			len*=i;
			len%=MOD;
		}
		out(len);
	}
}
