#include<bits/stdc++.h> 
#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

bool cmp(int x,int y)
{
	return x>=y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	int arr[len];	
	int sum=0;
	for(int a=0;a<s.size();a++)
	{
		if(s[a]>='0'&&s[a]<='9')
		{
			arr[sum]=((int)(s[a]))-48;
			sum++;
		}
	}
	sort(arr,arr+sum+1,cmp);
	for(int a=0;a<sum;a++)
	{
		if(arr[a]>=0&&arr[a]<=9&&arr[a]>=arr[a+1])
			cout<<arr[a];
	}

	return 0;
} 
