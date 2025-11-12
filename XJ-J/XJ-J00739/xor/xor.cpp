#include <bits/stdc++.h>
using namespace std;
int n,k,a[500001],c=0,q=0,p=0;
long long m=0;
int z(int a){
	int i=0,s=0;
	while(a!=0){
		s+=(a%10)*jc(2,i);
		i++;
	}
	return s;
}
int x(int a,int b){
	int d=0;
	if(a%10==b%10){
		p++;
	}else{
		d+=1*jc(10,p);
	}
}
int l(int a,int b){
	if(a==0){
		return 0;
	}else{
		q++;
		return l(a/2,a%2*jc(2,q)+b);
	}
}
int jc(int a,int b){
	int s=1;
	if(b==0&&a!=0){
		return 1;
	}else if(a!=0){
		for(int i=0;i<b;i++){
			s*=a;
		}
		return s;
	}else{
		return 0;
	}
	
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	//
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			for(int r=i;r<j;r+=2){
				m=x(m,l(r,0));
				if(z(m)==k){
					c++;
				}
			}
		}
	}
	cout<<c;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
