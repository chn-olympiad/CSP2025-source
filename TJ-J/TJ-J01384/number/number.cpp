#include<bits/stdc++.h>
using namespace std;
char a[100001];
char c[100001];
int n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=0;;i++){
		cin>>a[i];
		break;
		
	}
	for(int i=0;;i++){
			if((a[i]=='0'||a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9')||a[i+1]=='0'||a[i+1]=='1'||a[i+1]=='2'||a[i+1]=='3'||a[i+1]=='4'||a[i+1]=='5'||a[i+1]=='6'||a[i+1]=='7'||a[i+1]=='8'||a[i+1]=='9'){
				c[i]=a[i];
			}
		break;	}
		c[i]=<int>c[i];	
	sort(c,c+1);
	for(int i=0;;i++){
		cout<<c[i];
		break; 
	}

	return 0;
} 
