#include<bits/stdc++.h>
using namespace std;
int len,a[10000],sum=0,num=0,c=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]=='0'){
			a[i]=0;
			num++;
		}
		else if(s[i]=='1'){
			a[i]=1;
		}
		else if(s[i]=='2'){
			a[i]=2;
		}
		else if(s[i]=='3'){
			a[i]=3;
		}
		else if(s[i]=='4'){
			a[i]=4;
		}
		else if(s[i]=='5'){
			a[i]=5;
		}
		else if(s[i]=='6'){
			a[i]=6;
		}
		else if(s[i]=='7'){
			a[i]=7;
		}
		else if(s[i]=='9'){
			a[i]=9;
		}
		else if(s[i]=='8'){
			a[i]=8;
		}
	}
	for(int i=0;i<len;i++){
		if(a[i]!=0){
			cout<<a[i];
		}
	}
	if(num!=0){
		for(int i=0;i<num;i++){
		    cout<<"0";
	    }
	}
//for(int i=0;i<num;i++){
//	cout<<a[i];
//}
	return 0;
}
	
	
