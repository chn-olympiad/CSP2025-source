#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
	
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int arr[10005]={};
	cin>>s;
   
  
    long long e=0;
    for(int i=0;i<=s.size();i++){
    	if(s[i]<='9'&&s[i]>='0'){
    		e++;
    		arr[e]=s[i]-'0';
		}
	}
	sort(arr+1,arr+s.size()+1,cmp);
	for(int i=1;i<=e;i++){
		cout<<arr[i];
	}
    fclose(stdin);
    fclose(stdout);
}
