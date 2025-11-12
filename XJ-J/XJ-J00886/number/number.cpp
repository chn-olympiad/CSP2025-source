#include<bits/stdc++.h> 
using namespace std;
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
    getline(cin,s);
	long long len=s.size(),arr[1001],j=0;
	for(long long i=0;i<=len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			int a=s[i],b='0';
			arr[j]=a-b;
			j++;
		}
	}
    sort(arr,arr+j);
    j--;
	for(;j>=0;j--){
		cout<<arr[j];
	}
	
	return 0;
}
