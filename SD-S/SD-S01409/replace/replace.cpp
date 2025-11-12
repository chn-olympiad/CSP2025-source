#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int T,n,q,flag=0;
	string a[10010][5];
	string t1,t2,t;
	int l1,l2,s1,s2,ans=0;
	cin>>n>>q;
	cout<<q<<endl;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][1]>>a[i][2];
		//cout<<a[i][1]<<endl<<a[i][2]<<endl;
	}
	while(q--)
	{
		ans=0;
		cin>>t1>>t2;
		l1=t1.size(),l2=t2.size();
		if(l1!=l2)
		{
			cout<<"0"<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			s1=a[i][1].size();
			
			s2=a[i][2].size();
			if(s1>l1)
			{
				continue;
			}
			for(int j=0;j<l1;j++)
			{
				//cout<<t[j];
				flag=0;
				t=t1;
				for(int k=j;k<s1+j;k++)
				{
					if(a[i][1][k-j]!=t[k])
					{
						flag=1;
						break;
					}
					t[k]=a[i][2][k-j];
				}
				if(flag==0&&t==t2)
				{
					ans++;
				}
			}
			//cout<<endl;
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

