#include<bits/stdc++.h>
using namespace std;
string b;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>b;
	if(b.size()==1){
		cout<<b[0]<<endl;
		return 0;
	}
	long long x=0;
	long long a[b.size()-1]={0};
	for(long long i=0;i<b.size();i++){
		if(b[i]=='0'||b[i]=='1'||b[i]=='2'||b[i]=='3'||b[i]=='4'||b[i]=='5'||b[i]=='6'||b[i]=='7'||b[i]=='8'||b[i]=='9'){
			a[x]=b[i]-48;
			x++;
		}
	}
	sort(a,a+x);
	for(long long i=x-1;i>=0;i--){
		cout<<a[i];
	}
	
	
	
	return 0;
} 
