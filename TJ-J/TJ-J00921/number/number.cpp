#include <bits/stdc++.h>
#include <algorithm> 
using namespace std;
string s;
int arr[1000005];
int a=0;
int b=0;
bool cmp(int p,int b){
	return p>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	cin>>s;
	int lenth = s.size();
	if(lenth==1){
		cout<<s;
		return 0;
	}
	for(int i=0;i<lenth;i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			b++;
			arr[b]=s[i]-48;
		}
 	}
 	sort(arr+1,arr+1+b,cmp);
 	for(int i=1;i<=b;i++){
 		cout<<arr[i];
	}
	return 0;
}
