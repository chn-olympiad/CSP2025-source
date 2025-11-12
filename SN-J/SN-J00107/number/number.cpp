#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int num;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int b=0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='0'){
			a[i]=0;
			b++;
		}
		else if(s[i]=='1'){
			a[i]=1;
			b++;
		}
		else if(s[i]=='2'){
			a[i]=2;
			b++;
		}
		else if(s[i]=='3'){
			a[i]=3;
			b++;
		}
		else if(s[i]=='4'){
			a[i]=4;
			b++;
		}
		else if(s[i]=='5'){
			a[i]=5;
			b++;
		}
		else if(s[i]=='6'){
			a[i]=6;
			b++;
		}
		else if(s[i]=='7'){
			a[i]=7;
			b++;
		}
		else if(s[i]=='8'){
			a[i]=8;
			b++;
		}
		else if(s[i]=='9'){
			a[i]=9;
			b++;
		}
	}
		for(int j=0;j<b;j++){
			if(a[j]<a[j+1]){
				int q=a[j];
				a[j]=a[j-1];
				a[j-1]=q;
			}
		}
		
	for(int i=0;i<b;i++){
		cout<<a[i];
	}
	return 0;
} 
