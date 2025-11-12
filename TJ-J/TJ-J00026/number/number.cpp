#include<bits/stdc++.h>
using namespace std;
int n,num=0,arr[1000005];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0' && s[i]<='9'){
			num++;
			arr[num]=s[i]-'0';
		}
	}
	sort(arr+1,arr+num+1);
	for(int i=num;i>=1;i--){
		cout<<arr[i];
	}
	return 0;
}
