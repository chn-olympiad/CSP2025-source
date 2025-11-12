#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
string a;
int b[MAXN];
int k;
int main(){
//	freopen("number","r",in);
//	freopen("number","w",out); 
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>=48&&a[i]<=57){
			b[k++]=a[i]-48;
		}
	}
	sort(b,b+k);
	for(int i=k-1;i>=0;i--){
		cout<<b[i];
	}
//	freclose("number",in);
//	freclose("number",out);
	return 0;
} 
