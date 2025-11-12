#include<bits/stdc++.h>
using namespace std;
int arr[1000005];
int main(){
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout); 
    string s;
    int k=0;
    cin>>s;
    for(int i=0;i<=s.size();i++){
    	if(s[i]>=48&&s[i]<=58){
    		arr[k]=s[i]-48;
    		k++;
		}
	}
    sort(arr,arr+k);
    for(int i=k-1;i>=0;i--){
    	cout<<arr[i];
	}
    return 0;
} 


