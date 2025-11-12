#include<iostream>
#include<string>
#include<cmath> 
using namespace std;
int num[500000],k,n,all=0;
int de(int a,int b){
	long long w,l=0,l_1=0,e=0;
	string x,y;
	while(a>0){
		w=a%2;
		a/=2;
		l++;
	}
	for(int i=0;i<l;i++){
		if(x==""&&w%10==0){
			w/=10;
		}else{
			x+=w%10;
			w/=10;
		}
	}
	while(b>0){
		w=b%2;
		b/=2;
		l_1++;
	}
	for(int i=0;i<l_1;i++){
		if(y==""&&w%10==0){
			w/=10;
		}else{
			y+=w%10;
			w/=10;
		}
	}
	int now;
	if(l>l_1){
		for(int i=0;i<l_1;i++){
			if(x[i]==1&&y[i]==1){
				x[i]=0;
			}else if(x[i]==0&&y[i]==0){
				x[i]=0;
			} else{
				x[i]=1;
			}
		}
		now=l;
	}else{
		for(int i=0;i<l;i++){
			if(x[i]==1&&y[i]==1){
				y[i]=0;
			}else if(x[i]==0&&y[i]==0){
				y[i]=0;
			} else{
				y[i]=1;
			}
		}
		now=l_1;
		x=y;
	}
	for(int i=0;i<now;i++){
		e+=pow(2,i)*(x[i]-'0');
	}
	return e;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	int c=0;
	for(int z=1;z<n;z++){
		for(int i=0;i<n;i++){
			c=num[i];
			for(int j=0;j<z;j++){
				c=de(c,num[j]);
			}
			if(c==k){
				all++;
			}
		}
	}
	cout<<all;
	return 0;
} 
