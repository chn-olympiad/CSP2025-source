#include<bits/stdc++.h>
using namespace std;
int cmp(int x , int y )
{
	if(x < y)
	return x > y;
}
string s ;

int a[100009] , o = 0 , n;

int main()
{
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin >> s ;
	
	n = s.size();


	for(int i = 0 ; i < n  ; i++)
	{
		if( (s[i] > '0' or s[i] == '0')  and (s[i] < '9' or s[i] == '9') )
		{
			a[++o] = s[i] - '0';
		}
	}
	
	
	sort(a+1,a+o+1,cmp);
	
	
	for(int i = 1 ; i <= o ; i++)
	{
		cout << a[i] ;
	}
	
	
	return 0;
 } 
