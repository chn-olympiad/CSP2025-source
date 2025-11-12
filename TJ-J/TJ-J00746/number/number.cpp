#include<bits/stdc++.h>
using namespace std;
string s[1001];
int a[1001];
int n;
bool cmp(int a,int b){
	if(a>b){
		return 1;
	}
	else{
		return 0;
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=n;i++){
		cin>>s[i];
		n++;
	}
	for(int i=1;i<=n;i++){
		if(s[i]=='0' or s[i]=='1' or s[i]=='2' or s[i]=='3' or s[i]=='4' or s[i]=='5' or s[i]=='6' or s[i]=='7' or s[i]=='8' or s[i]=='9'){
			a[i]=s[i];
		}
	}
	sort(a+1,a+1+a.size,cmp);
	for(int i=1;i<=a.size;i++){
		couit<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;	
} 
