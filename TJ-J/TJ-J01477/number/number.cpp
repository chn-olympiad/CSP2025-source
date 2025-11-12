#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int arr[10]={0},sum=0;
	int len=s.length();
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			arr[s[i]-48]++;
		} 
	}
	
	
	for(int i=9;i>=0;i--)
	{
		if(arr[i]>0){
			for(int j=0;j<n;j++) cout<<char(i+'0');
		}
	}
	
	return 0;
} 
