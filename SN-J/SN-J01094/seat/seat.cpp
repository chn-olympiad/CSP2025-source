//考号：SN-J01094 学校：富平县实验中学 姓名：陈佳豪
#include<bits/stdc++.h>
using namespace std;
int main()
{  
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int n,m,a[9],s=1;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	    cin>>a[i];
	for(int i=1;i<m;i++)
	{
		if(a[0]<a[i])
		  s++;
	}
	cout<<s;
	return 0;
}
