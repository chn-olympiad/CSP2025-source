#include<bits/stdc++.h>
using namespace std;
string s;
int len,max1=-1,a[1000005],ai=1,f[1000005],maxi,sum;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=sizeof(s)-1;
	for(int i=0;i<=len;i++){
		if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0'){
			a[ai]=s[i]-48;
			ai++;
		}
	}
	ai--;
	//sort(a+1,a+1+ai);
	for(int i=1;i<=ai;i++){
		for(int j=i;j<=ai;j++){
			if(a[i]<a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	for(int i=1;i<=ai;i++){
		sum=sum*10+a[i];
	}
	/*for(int i=ai;i>=1;i--){
		sum=sum*10+a[i];
	}*/
	cout<<sum;
	return 0;
} 
