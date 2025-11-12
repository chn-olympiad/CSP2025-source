#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7;
long long a[maxn];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	
	cin>>s;
	long long len=s.length();
	long long m=0,j=0;
	for(int i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9'){
			if(s[i]=='0') a[j]=0;
			if(s[i]=='1') a[j]=1;
			if(s[i]=='2') a[j]=2;
			if(s[i]=='3') a[j]=3;
			if(s[i]=='4') a[j]=4;
			if(s[i]=='5') a[j]=5;
			if(s[i]=='6') a[j]=6;
			if(s[i]=='7') a[j]=7;
			if(s[i]=='8') a[j]=8;
			if(s[i]=='9') a[j]=9;
			m++;
			j++;
		}
	}
	long long n=m;
	long long step;
	while(m--){
		for(int i=0;i<n;i++){
			if(a[i]<=a[i+1]){
				step=a[i];
				a[i]=a[i+1];
				a[i+1]=step;
			}
			step=0;
		}	
	}
	for(int i=0;i<n;i++){
		cout<<a[i];
	}
	return 0;
}
