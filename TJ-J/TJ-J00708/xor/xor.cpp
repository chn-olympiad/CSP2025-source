#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],b;
string ejz(long long x){
	string s="";
	while(x){
		s+=x%2+'0';
		x/=2;
	}
	return s;
}
long long jze(string s){
	long long x;
	for(int i=0;i<s.size();i++){
		x+=(s[i]-'0')*pow(2,i);
	}
	return x;
}
long long yh(long long x,long long y){
	string mx,my,ma=ejz(a[x]);
	for(int i=x;i<=y;i++){
	    string s="";
		mx=ma;
		my=ejz(a[i]);
		if(mx.size()>my.size())swap(mx,my);
		for(int j=0;j<mx.size();j++){
			if(mx[j]==my[j])s+='0';
			else s+=1;
		}
		for(int j=mx.size();j<my.size();j++){
			if(my[j]=='0')s+='0';
			else s+='1';
		}
		ma=s;
	}
	return jze(ma);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==k)b++;
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){ 
			if(yh(i,j)==k)b++;
		}
	}
	cout<<b;
	return 0;
}
