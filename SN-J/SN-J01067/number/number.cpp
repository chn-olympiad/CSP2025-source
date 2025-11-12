//SN-J01067  郭思辰  西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
string a,s,d;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<=a.size();i++){
		if(a[i]>='a'&&a[i]<='z'){
			d[i]=a[i];
	 	}else{
			s[i]=a[i];
		}
	}
	
	for(int i=0;i<=a.size();i++){
		if(a.size()==1){
			cout<<a[i];
			return 0;
		}
	}
	for(int i=0;i<=a.size();i++){
		cout<<s[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
