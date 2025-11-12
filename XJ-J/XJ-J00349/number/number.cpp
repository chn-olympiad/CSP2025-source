#include<bits/stdc++.h>
using namespace std;
int app(int x,int y)
{
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int cnt_1[s.size()];
	int cnt_2=0;
	for(int a=0;a<s.size();a++)
	{
		if((int)s[a]>=48&&(int)s[a]<=57)
		{
			cnt_1[a]=int(s[a])-48;
			cnt_2+=1;
		}
		else
			cnt_1[a]=0;
	}
	
	sort(cnt_1,cnt_1+s.size(),app);
	for(int a=0;a<cnt_2;a++)
	{
		cout<<cnt_1[a];
	}
	
	return 0;
} 
