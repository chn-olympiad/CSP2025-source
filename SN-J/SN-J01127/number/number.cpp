#include<bits/stdc++.h>
using namespace std;
int s[1000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int e=a.size();
	for(int i=0;i<=e;i++){
		if(a[i]=='1'){
			s[i]=1;	
		}
		else if(a[i]=='2'){
			s[i]=2;
				
		}
		else if(a[i]=='3'){
			s[i]=3;	
		}
		else if(a[i]=='4'){
			s[i]=4;	
		}
		else if(a[i]=='5'){
			s[i]=5;	
		}
		else if(a[i]=='6'){
			s[i]=6;	
		}
		else if(a[i]=='7'){
			s[i]=7;	
		}
		else if(a[i]=='8'){
			s[i]=8;	
		}
		
		else if(a[i]=='9'){
			s[i]=9;	
		}
		else if(a[i]=='0'){
			s[i]=0;
		}
		else{
			s[i]=-1;
		}
	}
	sort (s,s+e+1);
	for(int w=e;w>=1;w--){
		if(s[w]!=-1){
			cout<<s[w];
		}
	}
	return 0;
}

