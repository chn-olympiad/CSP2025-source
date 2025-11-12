#include<bits/stdc++.h>
using namespace std;
int nu[200000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a=0,sum=0,b=1,jh,jj,jz;
	cin>>s;
	jz=s.size();
	int mass=s[1];
	for(int i=0;i<=s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			sum++;
		}
	}
	jj=sum;
	for(int i=0;i<=s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			b=1;
			for(int j=1;j<=sum-1;j++){
				b*=10;
			}
			if(s[i]==49)a+=1*b;
			if(s[i]==50)a+=2*b;
			if(s[i]==51)a+=3*b;
			if(s[i]==52)a+=4*b;
			if(s[i]==53)a+=5*b;
			if(s[i]==54)a+=6*b;
			if(s[i]==55)a+=7*b;
			if(s[i]==56)a+=8*b;
			if(s[i]==57)a+=9*b;
			sum--;
		}
	}

	for(int i=1;i<=jj;i++){
		nu[i]=a%10;
		a/=10;
	}
	for(int i=1;i<=jj;i++){
		for(int j=1;j<=jj;j++){
			if(nu[j]<nu[j+1]){
				jh=nu[j+1];

				nu[j+1]=nu[j];
				nu[j]=jh;
			}
		}
	}
	if(jz==1){
		cout<<nu[1];
	}
	else{
		for(int i=1;i<=jj;i++){
		cout<<nu[i];
	}
	}


	return 0;
}