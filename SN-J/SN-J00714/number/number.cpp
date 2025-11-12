#include<bits/stdc++.h>
using namespace std;
string a;
int b[100000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int t=1;
	for(int i=0;i<=a.size();i++){
		if(a[i] > '0'&& a[i] < '9'){
			b[t]=int(a[i]+1-'1');
			t++;
		}
		if(a[i] == '0'|| a[i] == '9'){
			b[t]=int(a[i]+1-'1');
			t++;
		}
	}
	sort(b+1,b+t);
	for(int j=t-1;j>=1;j--){
		cout<<b[j];
	}
	return 0;
		
}
