#include<bits/stdc++.h>
using namespace std;
int a[100001];
int j=0;
string s;
cmp(int a,int b){
	if(a>=b){
		return 1;
	} 
	return 0;
}
int main()
{	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]-'0'==1){
			a[j]=1;
			j++;
		}
		if(s[i]-'0'==2){
			a[j]=2;
			j++;
		}
		if(s[i]-'0'==3){
			a[j]=3;
			j++;
		}
		if(s[i]-'0'==4){
			a[j]=4;
			j++;
		}
		if(s[i]-'0'==5){
			a[j]=5;
			j++;
		}
		if(s[i]-'0'==6){
			a[j]=6;
			j++;
		}
		if(s[i]-'0'==7){
			a[j]=7;
			j++;
		}
		if(s[i]-'0'==8){
			a[j]=8;
			j++;
		}
		if(s[i]-'0'==9){
			a[j]=9;	
			j++;
		}
		if(s[i]-'0'==0){
			a[j]=0;	
			j++;
		}
	}
	sort(a,a+j,cmp);
	for(int i=0;i<j;i++){
		cout<<a[i];
	}
	return 0;
}
