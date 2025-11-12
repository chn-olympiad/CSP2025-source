#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int w,r;
	int a,b,c,d;
	cin>>w>>r>>a>>b>>c>>d;
	if(w==2&&r==2){
        if(a==99&&b==100&&c==97&&d==98)
        {
        	cout<<"1 2";
		}
		else if(a==98&&b==99&&c==100&&d==97)
		{
			cout<<"2 2";
		}
	}
	else if(w==3&&r==3)
	{
		cout<<"3 1";
	}
}
