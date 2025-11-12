#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	char s[1000001]={0};
	cin>>s;
	int n=0;
	int a[1000001]={0};
	n=strlen(s);
	int m=0;
	for(int i=0;i<n;i++){
		if (s[i]<=57 && s[i]>=48){
			a[m]=int(s[i])-48;
			m++;
		}
	}
	int c=0;
	int q=0;
	int ans[1000000]={0};
	for(int i=0;i<n;i++){
		if(c<=a[i]){
			ans[q]=a[i];
			c=a[i];
			q++;
		}
	}
	for(int i=0;i<n;i++){
		cout<<ans[i];
	}
	
	return 0;
} 
