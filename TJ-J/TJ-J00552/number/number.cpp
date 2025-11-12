#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	char a[1000010]="";
	int b=0,c=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			b++;
			a[b]=s[i];
		}	 
	}
	for(int i=0;i<s.size();i--){
		c++;
	}
	sort(a,a+b+1);
	for(int i=b;i>0;i--){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
