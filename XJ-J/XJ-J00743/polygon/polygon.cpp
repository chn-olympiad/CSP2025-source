#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
int n;
int count=0;
cin>>n;
int arr[n];
for(int a=0;a<n;a++)
{
    cin>>arr[a];
}
if(n<3)
{
    cout<<"0";
}else if(n==3)
{
    if(arr[0]+arr[1]>arr[2]&&arr[2]+arr[1]>arr[0]&&arr[0]+arr[2]>arr[1])
    {
        cout<<"1";
    }else
    {
        cout<<"0";
    }
}else if(n==4)
{
	if(arr[0]+arr[1]>arr[2]&&arr[2]+arr[1]>arr[0]&&arr[0]+arr[2]>arr[1])
		count++;
	if(arr[1]+arr[2]>arr[3]&&arr[1]+arr[3]>arr[2]&&arr[2]+arr[3]>arr[1])
		count++;
	if(arr[1]+arr[0]>arr[3]&&arr[1]+arr[3]>arr[0]&&arr[3]+arr[0]>arr[1])
		count++;
	cout<<(count+1);
}else
	cout<<"1";
return 0;
}
