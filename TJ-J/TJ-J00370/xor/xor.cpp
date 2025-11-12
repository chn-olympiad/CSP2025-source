#include<bits/stdc++.h>
using namespace std;
long long k=0,n=0;
const long long N=1e7+10;
int a[N]={0};
bool fl[N]={0},flag=false;
long long m=0;
long long yi(long long a,long long b){
	string a1="",b1="";
	long long t=0,c=0;
	long long m=a,n=b;
	while(m!=0){
		a1=char(m%2+48)+a1;
		m/=2;
		t++;
	}
	while(n!=0){
		b1=char(n%2+48)+b1;
		n/=2;
		c++;
	}
	if(t>c){
		for(int i=0;i<t-c;i++){
			b1='0'+b1;
		}
	}else{
		for(int i=0;i<c-t;i++){
			a1='0'+a1;
		}
	}
	long long max1=max(t,c);
	string w="";
	for(int i=0;i<max1;i++){
		if(a1[i]==b1[i]){
			w=w+'0';
		}else{
			w=w+'1';
		}
	}
	long long d=0,h=0,s=0;
	for(int i=max1-1;i>=0;i--){
		s=pow(2,d);
		if(w[i]=='1'){
			h+=s;
		}
		d++;
	}
	return h;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		fl[i]=0;
	}
	int hh=0;
	
	for(int j=0;j<n;j++){
		for(int x=n-1;x>=j;x--){
			
			flag=true;
			long long e=0;
			for(int y=j;y<=x;y++){
				if(fl[y]==1){
					flag=false;
					e=0;
					break;
				}
			}
			if(flag){
				for(int y=j;y<=x;y++){
					e+=yi(e,a[y]);
					fl[y]=1;
				}
				
			}
			
			
			if(e==k){
				m++;
			}else{
				for(int y=j;y<=x;y++){
					fl[y]=0;
				}
			}
			hh++;
		}
	}
	
	cout<<m;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
