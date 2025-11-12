#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int arr[123456];
	int main()
	{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	int j=0;
	for(int i=0;i<=n;i++){
		if(s[i]>='0'and s[i]<='9'){
			arr[j++]=s[i]-'0';
			j++;
		}
	}
	sort(arr+1,arr+j+1);
	for(int i=j;i>1;i--){
		cout<<arr[i];
	}
	return 0;
}
