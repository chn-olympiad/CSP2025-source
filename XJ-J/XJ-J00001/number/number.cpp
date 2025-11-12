#include<bits/stdc++.h>

using namespace std;
string a;
int sum=0,a1[100001],x=0,pf=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]=='0'||a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9'){
			a1[x]=a[i]-'0';
			x++;
		}
	}
	sort(a1,a1+x);
	sum+=a1[0];
	for(int i=1;i<x;i++){
		if(a1[i]==0){
			sum*=10;
		}
		pf*=10;
		sum+=a1[i]*pf;
	} 
	cout<<sum;
	return 0;
} 
