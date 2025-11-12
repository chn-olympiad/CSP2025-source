#include<bits/stdc++.h>
using namespace std;
int y_t[1000006],y_num=0;
signed main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	string y_a;
	cin>>y_a;
	if(y_a.size()==1)
	{
		cout<<int(y_a[1]);
		return 0; 
	}
	for(int i=0;i<y_a.size();i++)
	{
		y_t[i]=int(y_a[i]);
		if(y_t[i]==0)
		{
			if(y_num==0)
			{
				y_num+=10;
			} 
			else
			{
				y_num*=10;			
			}
		}
		else
		{
			y_num+=y_t[i]*(10*i);
		}
	}
	cout<<y_num;
	return 0;
}
