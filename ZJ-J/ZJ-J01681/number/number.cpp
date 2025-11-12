#include<bits/stdc++.h>
using namespace std;
string s;
int arr[1000010];
bool is_num(char c){
	if(c>=48 and c<=57){
		return 1;
	}
	return 0;
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int j=1;
	for(int i=0;i<s.size();i++){
		if(is_num(s[i])){
			arr[j]=s[i]-'0';
			j++;
		}
	}
	sort(arr+1,arr+1+j,cmp);
	for(int i=1;i<j;i++){
		cout<<arr[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
