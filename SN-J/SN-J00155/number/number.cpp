#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[100]={},sh=0,c;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[sh]=int(s[i])-48;
			sh++;
		}
	}
	for(int i=0;i<sh;i++){
		for(int j=i+1;j<sh;j++){
			if(a[i]<a[j]){
				c=a[i];
				a[i]=a[j];
				a[j]=c;
			}
		}
	}
	int xam=0,max=1;
	for(int i=1;i<=sh;i++){
		for(int j=1;j<=sh-i;j++){
			max=max*10;
		}
		xam+=max*a[i-1];
		max=1;
	}
	cout<<xam;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
