#include<bits/stdc++.h>
using namespace std;
long long a0,a1,a2,a3,a4,a5,a6,a7,a8,a9;
int main()
{
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s;
	while(cin>>s)
	{
		if(s=='0') a0++;
		else if(s=='1') a1++;
		else if(s=='2') a2++;
		else if(s=='3') a3++;
		else if(s=='4') a4++;
		else if(s=='5') a5++;
		else if(s=='6') a6++;
		else if(s=='7') a7++;
		else if(s=='8') a8++;
		else if(s=='9') a9++;
	}
	while(a9--) cout<<9;
	while(a8--) cout<<8;
	while(a7--) cout<<7;
	while(a6--) cout<<6;
	while(a5--) cout<<5;
	while(a4--) cout<<4;
	while(a3--) cout<<3;
	while(a2--) cout<<2;
	while(a1--) cout<<1;
	while(a0--) cout<<0;
}