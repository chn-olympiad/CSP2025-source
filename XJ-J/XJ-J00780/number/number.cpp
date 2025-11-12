#include<bits/stdc++.h>
using namespace std;
string b[10000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int sum=1;
	string a;
	cin>>a;
	for(int i = 0;i<=a.length()+1;i++){
		if(a[i]=='0'){
			sum++;
			b[i]=a[i];
		}
		else if(a[i]=='1'){
			sum++;
			b[i]=a[i];
		}
		else if(a[i]=='2'){
			sum++;
			b[i]=a[i];
		}
		else if(a[i]=='3'){
			sum++;
			b[i]=a[i];
		}
		else if(a[i]=='4'){
			sum++;
			b[i]=a[i];
		}
		else if(a[i]=='5'){
			sum++;
			b[i]=a[i];
		}
		else if(a[i]=='6'){
			sum++;
			b[i]=a[i];
		}
		else if(a[i]=='7'){
			sum++;
			b[i]=a[i];
		}
		else if(a[i]=='8'){
			sum++;
			b[i]=a[i];
		}
		else if(a[i]=='9'){
			sum++;
			b[i]=a[i];
		}
	}
	sum++;
	sort(b,b+sum+1);
	for(int i = sum;i>=1;i--){
		cout<<b[i];
	}
	return 0;
} 

