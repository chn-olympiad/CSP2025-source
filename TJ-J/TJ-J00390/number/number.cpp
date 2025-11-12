#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int num=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]+=s[i]-'0';
			num++;
		}		
	}
	for(int i=0;i<num;i++){
		if(a[i]<=a[i+1]){
			swap(a[i],a[i+1]);
		}		
	}
	for(int i=0;i<num;i++){
		if(a[i]<a[i+1]){
			swap(a[i],a[i+1]);
		}		
	}
	for(int i=0;i<num;i++){
		if(a[i]<a[i+1]){
			swap(a[i],a[i+1]);
		}		
	}		
	for(int i=0;i<num;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

