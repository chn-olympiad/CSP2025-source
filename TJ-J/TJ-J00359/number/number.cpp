#include<bits/stdc++.h>
using namespace std;
long long n,p,r;
string s,s1;
int a[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			a[p]=0;
			p++;
		}
		else if(s[i]=='1'){
			a[p]=1;
			p++;
		}
		else if(s[i]=='2'){
			a[p]=2;
			p++;
		}
		else if(s[i]=='3'){
			a[p]=3;
			p++;
		}
		else if(s[i]=='4'){
			a[p]=4;
			p++;
		}
		else if(s[i]=='5'){
			a[p]=5;
			p++;
		}
		else if(s[i]=='6'){
			a[p]=6;
			p++;
		}
		else if(s[i]=='7'){
			a[p]=7;
			p++;
		}
		else if(s[i]=='8'){
			a[p]=8;
			p++;
		}
		else if(s[i]=='9'){
			a[p]=9;
			p++;
		}
		
	}
	sort(a,a+p);
	if(a[p-1]==0){
		cout<<0;
		return 0;
	}
	for(int i=p-1;i>=0;i--){
		cout<<a[i];
	}
	
	
	return 0;
}
