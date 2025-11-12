#include<bits/stdc++.h>
using namespace std;
string a;
int ar[1000010],c;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> a;
	for(int i=0;i<a.length();i++){
		if(a[i]>='0'&&a[i]<='9'){
			ar[c]=a[i]-48;
			c++;
		}
	}
	sort(ar,ar+c);
	for(int i=c-1;i>=0;i--){
		cout << ar[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
