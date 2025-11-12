#include<bits/stdc++.h> 
using namespace std;
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	string s;
    int a[100],j=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<=57&&s[i]>=48){
			a[j]=int(s[i]);
			j++;
		}
	}
	sort(a,a+j);
	for(int i=j-1;i>=0;i--){
		cout<<a[i]-48;
	}
	//fclose("number.in");
	//fclose("number.out");
	return 0;
}
