#include<bits/stdc++.h>
using namespace std;
long long s[1000005];
int main(){
	freopen("number","r",stdin);
	freopen("number","w",stdout);
	int n;
	cin>>s[n];
	int a[n];
	for(int i=1;i<=10;i++){
		if(s[i]<=9 && s[i]>=1){
			s[i]=a[i];
		}
	}
	sort(a+1,a+n+1);
	cout<<a;
	    
	fclose(stdin);
	fclose(stdout);    
	return 0;    
} 
   
