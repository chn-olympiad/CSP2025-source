//SN-J00629 杨济铭 西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=0;
	for(int i=0;i<s.length();i++){
		if(s[i]<=57&&s[i]>=48){
			n++;
		}
	}
	int a[n],b=0;
	for(int i=0;i<s.length();i++){
		if(s[i]<=57&&s[i]>=48){
			a[b]=s[i]-48;
			b++;
		}
	}
	int f=1;
	while(f){
		f=0;
		for(int i=1;i<n;i++){
			if(a[i]>a[i-1]){
				f=1;
				int t=a[i-1];
				a[i-1]=a[i];
				a[i]=t;
			}
		}
	}
	for(int i=0;i<n;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
