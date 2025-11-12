#include <bits/stdc++.h>
using namespace std;
string s;
int arr[1000010]={};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int j=1;
	for(int i=0;i<s.size();i++){
		if((int)s[i]<97){
			arr[j]=(int)s[i];
			j++;
		}
	}
	sort(arr+1,arr+j);
	for(int i=j-1;i>0;i--){
		cout<<arr[i]-48;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
