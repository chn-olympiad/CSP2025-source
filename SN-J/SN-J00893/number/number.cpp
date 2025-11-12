#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number2.in","r",stdin);
	freopen("number2.out","w",stdout);
	long long n=0;
	long long m;
	int x;
	int s[1000];
	int a[1000];
	cin>>s[x];
	
	for(int i=0;i<=1000;i++){
		if(s[i]%2==1||s[i]%2==0||s[i]%2==2){
			
			a[i]=s[i];
			
		}
		
		else if(i>x){
			
			break;
			
		}
		
	}
	
	for(int i=1;i<=1000;i++){
		
		if(a[i]>a[n]){
			
			m=a[i];
			a[i]=a[n];
			a[n]=m;
			n++;
			
		}
		cout<<a[i];
	}
	return 0;
}
