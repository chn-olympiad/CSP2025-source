//SN-J01159  马启源   西安市曲江第一中学
#include<bits/stdc++.h>

using namespace std;

string a;

int j=0,o=0;

int m[10000000]={0};

int n[10000000]={0};

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>a;
	
	if(a.length()==1&&(a=="0"||a=="1"||a=="2"||a=="3"||a=="4"||a=="5"||a=="6"||a=="7"||a=="8"||a=="9"))
	{
		cout<<a;
		return 0;
	}
	
	for(int i=0;i<a.length();i++)
	{
		
		if(a[i]-'0'==0||a[i]-'0'==1||a[i]-'0'==2||a[i]-'0'==3||a[i]-'0'==4||a[i]-'0'==5||a[i]-'0'==6||a[i]-'0'==7||a[i]-'0'==8||a[i]-'0'==9)
		{
			//cout<<a[i];
			
			m[j]=a[i]-'0';
			j++;
			
			//cout<<m[j];
		}
	}
	
//	for(int i=0;i<j;i++)
//	{
//		cout<<m[i];
//	}

	sort(m,m+j,greater<int>());
	
	for(int i=0;i<j;i++)
	{
		
		cout<<m[i];
	}
	
	return 0;
 } 
