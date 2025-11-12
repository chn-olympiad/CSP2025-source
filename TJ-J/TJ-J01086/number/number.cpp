#include<bits/stdc++.h>
using namespace std;

int main(){
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.length();
	int k=1;
	int arr[n+1]={};
	for(int i=1;i<=n;i++){
		if(s[i-1]=='1'||s[i-1]=='2'||s[i-1]=='3'||s[i-1]=='4'||s[i-1]=='5'||s[i-1]=='6'||s[i-1]=='7'||s[i-1]=='8'||s[i-1]=='9'||s[i-1]=='0'){
			char a=s[i-1];
			arr[k]=a-'0';
			k++;
		}
	}
	for(int i=1;i<k;i++){
		for(int j=1;j<k-i;j++){
			if(arr[j]<arr[j+1]){
				swap(arr[j],arr[j+1]);
			}
		}
	}
	for(int i=1;i<k;i++){
		cout<<arr[i];
	}
	
	return 0;
}
