#include<bits/stdc++.h>
using namespace std;

long long c,r,a[1000],cr,wei,n,ansl,ansr;
inline long long read(){
	long long ans=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return ans*f;
}
int main(){
	freopen("seat.in","r", stdin);
	freopen("seat.out","w",stdout);
	c=read();
	r=read();
	cr=c*r;
	for(int i=0;i<cr;i++){
		a[i]=read();
	}
	wei=a[0];
	sort(a,a+c*r);
	for(int i=0;i<cr;i++){
		if(a[i]==wei){
			wei=cr-i;
			break;
		} 
	}
	n=wei%r;
	if(n!=0)ansl=wei/r+1;
	else ansl=wei/r;	
	

	if(ansl%2==1){
		if(n==0) ansr=r;
		else ansr=n;
	}
	else ansr=r-n+1;
	cout <<  ansl << " " << ansr;
	
	return 0;
}

