#include<bits/stdc++.h>
using namespace std;
bool c(int x,int y)
{
	return x>y;
}
int a[1000000],cnt;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	for(int q=0;q<1000000;q++) a[q]=-1;
    string s;
    cin>>s;

	for(int q=0;q<s.size();q++)
	{
		if(s[q]>='0'&&s[q]<='9')
		{
			a[q]=s[q]-48;cnt++;
		}
	}
	sort(a,a+s.size(),c);
	for(int q=0;q<cnt;q++) cout<<a[q];
    fclose(stdin);
    fclose(stdout);
	return 0;
}
