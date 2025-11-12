#include<bits/stdc++.h>
using namespace std;
string ejz(int x){
	string y="";
	while(x){
		if(x%2==1){
			y='1'+y;
			x/=2;
		}
		else if(x%2==0){
			y='0'+y;
			x/=2;
		}
	}
	if(y==""){
		y+='0';
		return y;
	}
	return y;
	
}
string yh(string s1,string s2){
	if(s1=="x"||s2=="x")return "x";
	string ans="";
	int l1=s1.size(),l2=s2.size();
	int j=abs(l1-l2),i1=0,i2=0;
	if(l1<l2){
		i2=j;
		for(int i=0;i<(l2-l1);i++){
			ans+=s2[i];
		}
	}
	else if(l1>l2){
		i1=j;
		for(int i=0;i<(l1-l2);i++){
			ans+=s1[i];
		}
	}char nu;
	while(i1<l1&&i2<l2){
		nu=(s1[i1])==(s2[i2])?'0':'1';
		ans+=nu;
		i1++;
		i2++;
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a;
	cin>>n>>k;
	int an[n],bn[n],flag=1;
	for(int i=0;i<n;i++){
		cin>>a;
		an[i]=a;
		bn[i]=a;
		if(i!=0){
			if(an[i]!=an[i-1])flag=0;
		}
	}
	int sum=0;
	if(flag){
		if(k==a){
			cout<<n;
			return 0;
		}
		if(k==0){
			cout<<n/2;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	string as[n],bs[n],ks=ejz(k);
	for(int z=0;z<n;z++){
		as[z]=ejz(an[z]);	
		if(as[z]==ks){
			sum++;
			as[z]='x';
		}
		bs[z]=as[z];
	}
	for(int z=2;z<=n;z++){
		for(int t=0;t<n-z+1;t++){
			if(bs[t]=="x")continue;
			bs[t]=yh(bs[t],as[t+z-1]);
			if(bs[t]==ks){
				sum++;
				bs[t]="x";
				for(int v=t;v<t+z;v++)as[v]="x";
			}
		}
	}
	cout<<sum;
	return 0;
}
