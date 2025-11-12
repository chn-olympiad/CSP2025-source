#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!(ch>='0'&&ch<='9')){
		if(ch=='-')	f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
void write(int x){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x>9)	write(x/10);
	putchar(x%10+'0');
	return ;
}
const int N=510;
int x[N],c[N],k[N];
const int M=998244353;
int pow(int a,int b){
	int ans=1;
	while(b){
		if(a%2==1)	ans=(ans%M*a%M)%M;
		a=(a%M*a%M)%M;
		b>>=1;
	}
	return ans;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n=read(),m=read();
	string s;
	cin>>s;
	bool f=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0')	f=1;
	}
	for(int i=1;i<=n;i++)	c[i]=read();
	if(f==0){
		int k=n,f=0;
		for(int i=1;i<=n;i++){
			if(c[i]==0){
				k--;
				f++;
			}
		}
		int t=pow(2,k),t2=pow(2,f);
		t%=M;
		t2%=M;
		cout<<t*t2%M;
		return 0;
	}
	if(m==n){
		cout<<0;
		return 0;
	}
	if(m==1){
		cout<<pow(2,n);
		return 0;
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='0')	x[i]=x[i-1]+1;
		else	x[i]=x[i-1];
	}
	for(int i=1;i<=n;i++)	k[i]=i;
	int ans=0;
	int cnt=0,j=0;
	for(int i=1;i<=n;i++){
		if(cnt>=c[k[i]])	cnt++;
		else{
			if(s[i-1]=='0')	cnt++;
			else	 j++;
		}
	}
	if(j>=m)ans=(ans%M+1%M)%M;;
	cnt=0,j=0;
	while(next_permutation(k+1,k+n+1)){
		int cnt=0,j=0;
		for(int i=1;i<=n;i++){
			if(cnt>=c[k[i]])	cnt++;
			else{
				if(s[i-1]=='0')	cnt++;
				else	 j++;
			}
		}
		if(j>=m){
			//for(int i=1;i<=n;i++)	cout<<k[i]<<" ";
			ans=(ans%M+1%M)%M;
			//cout<<endl;
		}
	}
	write(ans%M);
	return 0;
}

