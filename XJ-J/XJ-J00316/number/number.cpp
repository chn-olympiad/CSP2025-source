#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s; 
	int arr1[s.size()]={0};
	int num=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			arr1[i]=s[i]-'0';
			num+=1;
		}
	}for(int j=0;j<s.size();j++){
		for(int i=0;i<s.size();i++){
		    int temp_a;
		    if(arr1[i]<arr1[i+1]){
			    temp_a=arr1[i];
			    arr1[i]=arr1[i+1];
			    arr1[i+1]=temp_a;
		    }
	    }
	}
	for(int i=0;i<num;i++){
		cout<<arr1[i];
	}
	return 0;
}
