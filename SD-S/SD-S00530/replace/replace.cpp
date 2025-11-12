#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,q,cnt,joei;
string s[N][2];
string x,y;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++)
	{
		string P[N];
		cin>>x>>y;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<x.length();j++)
			{
				string p="",q="";
				p=x.substr(j,s[i][1].length());
				q=y.substr(j,s[i][2].length());
				string head="",okn2="",okn3="",okn4="";
				head=x.substr(0,j+1);
				string u=head+p;
				string tail="";
				if(u.length()<x.length())
				{
					tail=x.substr(u.length(),x.length()-p.length()-head.length());
				}
				string okn=head+q+tail;
				okn2=q+tail;
				okn3=head+q;
				okn4=q;
				if(okn.length()==y.length())
				{
					joei++;
				}
				else
				{
					okn="";
				}
				if(okn2.length()==y.length())
				{
					joei++;
				}
				else
				{
					okn2="";
				}
				if(okn3.length()==y.length())
				{
					joei++;
				}
				else
				{
					okn3="";
				}
				if(okn4.length()==y.length())
				{
					joei++;
				}
				else
				{
					okn4="";
				}
				joei=0;
				//cout<<"head:   "<<head<<endl;
				//cout<<"tail    "<<tail<<endl;
				//cout<<"all     "<<okn<<endl;//
				if((p==s[i][1])&&(q==s[i][2])&&((okn==y)||(okn2==y)||(okn3==y)||(okn4==y)))
				{
					P[++cnt]=s[i][1];
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}

