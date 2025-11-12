#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int n=a.length();
	int a1[1000001]={};
	int a2=0;
	for(int i=0;i<n;i++){
		if(a[i]=='0'){
			a1[a2]=0;
			a2++;
		}if(a[i]=='1'){
			a1[a2]=1;
			a2++;
		}if(a[i]=='2'){
			a1[a2]=2;
			a2++;
		}if(a[i]=='3'){
			a1[a2]=3;
			a2++;
		}if(a[i]=='4'){
			a1[a2]=4;
			a2++;
		}if(a[i]=='5'){
			a1[a2]=5;
			a2++;
		}if(a[i]=='6'){
			a1[a2]=6;
			a2++;
		}if(a[i]=='7'){
			a1[a2]=7;
			a2++;
		}if(a[i]=='8'){
			a1[a2]=8;
			a2++;
		}if(a[i]=='9'){
			a1[a2]=9;
			a2++;
		}
	}sort(a1,a1+a2);
	while(a2){
		a2--;
		cout<<a1[a2];
	}
}
