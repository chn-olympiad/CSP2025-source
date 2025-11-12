#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+10;
long long a[N],b[N]; 
int main(){
	string n;
	cin>>n;
	long long len=n.size(),x=0;
	for(long long i=0;i<len;i++){
		if(n[i]>='0'&&n[i]<='9'){
			a[x]=n[i]-48;
			x++;
		}
	}
	sort(a,a+x+1);
	for(long long i=x;i>0;i--){
		cout<<a[i];
	}
	return 0;
} 
