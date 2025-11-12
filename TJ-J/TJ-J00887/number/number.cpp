#include <bits/stdc++.h>
using namespace std;
int main (){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	if(s.size()==1){
		cout<<s;
		return 0;
	}
	int a[s.size()+10]={};
	long long t=0;
	for(int i=0;i<=s.size()-1;i++){
		if(s[i]=='0'){
			a[t]=0;
			t+=1;
		}
		if(s[i]=='1'){
			a[t]=1;
			t+=1;
		}
		if(s[i]=='2'){
			a[t]=2;
			t+=1;
		}
		if(s[i]=='3'){
			a[t]=3;
			t+=1;
		}
		if(s[i]=='4'){
			a[t]=4;
			t+=1;
		}
		if(s[i]=='5'){
			a[t]=5;
			t+=1;
		}
		if(s[i]=='6'){
			a[t]=6;
			t+=1;
		}
		if(s[i]=='7'){
			a[t]=7;
			t+=1;
		}
		if(s[i]=='8'){
			a[t]=8;
			t+=1;
		}
		if(s[i]=='9'){
			a[t]=9;
			t+=1;
		}
	}
	int cnt=0;
	int w=0;
	for(int i=0;i<t;i++){
		cnt=0;
		for(int j=0;j<t;j++){
			if(a[j]>=cnt){
				cnt=a[j];
				w=j;
			}
		}
		cout<<cnt;
		a[w]=0; 
	}
	return 0;
}
