#include<bits/stdc++.h>
using namespace std;
string s;
long long ton[10];
bool flag=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')
			ton[s[i]-'0']++;
	for(int i=9;i>=0;i--)
		if(ton[i]!=0)
		{
			if(i==0&&flag==0)break;
			else flag=1;
			while(ton[i]!=0)
			{
				cout<<i;
				ton[i]--;
			}
		}
	if(flag==0)cout<<0<<endl;
	return 0;
}
//#Shang4Shan3Ruo6Shui4