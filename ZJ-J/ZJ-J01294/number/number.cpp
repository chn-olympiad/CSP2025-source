#include<iostream>
#include<string>
using namespace std;
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[10]={};
	cin>>s;
	for(int i=0;i<s.size();i=i+1){
		if(s[i]>='0' && s[i]<='9'){
			a[s[i]-'0']=a[s[i]-'0']+1;
		}
	}
	for(int i=9;i>=0;i=i-1){
		while(a[i]>0){
			cout<<i;
			a[i]=a[i]-1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
