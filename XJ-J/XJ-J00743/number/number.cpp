#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int n=s.length();
    if(n==1)
    {
    	cout<<s;
    	return 0;
	}
    int arr[n]={0},xb=0;
	int count=0; 
    for(int a=0;a<n;a++)
    {
    	if(s[a]=='0')
    		count++;
        if(s[a]=='1'||s[a]=='2'||s[a]=='3'||s[a]=='4'||s[a]=='5'||s[a]=='6'||s[a]=='7'||s[a]=='8'||s[a]=='9')
        {
            arr[xb]=int(s[a])-48;
            xb++;
        }
    }
   sort(arr,arr+n);
    for(int a=n-1;a>0;a--)
    {
    	if(arr[a]!=0)
    	{
	        cout<<arr[a];
		}
    }
    for(int a=0;a<count;a++)
		cout<<"0";
    return 0;
}
