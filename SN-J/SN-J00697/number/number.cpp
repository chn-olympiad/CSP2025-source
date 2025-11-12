#include<bits/stdc++.h>
using namespace std;
string a;
long long t=0,b[1000050];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int u=a.size();
	for(int i=0;i<u;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[t]=a[i]-'0';
			t++;
		}
	}
	sort(b,b+t);
	for(int i=t-1;i>=0;i--){
		cout<<b[i];
	}
	return 0;
}  
