#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);	
	string s;
	cin>>s;
	int scd=s.size();
	if(scd==1){
		cout<<s;
		return 0;
	}
	else if(scd>1)
	{
		while(scd--)
		{
			for(int i=1;i<=scd;i++)
			{
				if(s[i]>=1&&s[i]<=9)
					cout<<s[i];
				else
				{
					cout<<s;
					return 0;
				}
					
			}
				
		}
			
	}			
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
