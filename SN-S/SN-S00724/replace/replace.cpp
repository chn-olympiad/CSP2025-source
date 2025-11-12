#include<bits/stdc++.h>
using namespace std;
int T,n,num;
struct Book{
	string s1,s2;
}s[10005];
string a,b;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    cin>>n>>T;
    for(int i=1;i<=n;i++)
    {
    	cin>>s[i].s1>>s[i].s2;
	}
    while(T--)
    {
    	num=0;
    	cin>>a>>b;
    	for(int i=0;i<a.size();i++)
    	{
    		for(int j=1;j<=n;j++)
			{
    			if(a[i]==s[j].s1[0])
    			{
					//	cout<<s[j].s1;
					string s3=s[j].s1,s4,s5=a;
				
					for(int k=i;k<s3.size()+i;k++)
					{
						s4+=a[k];
					}
					//	cout<<" "<<s4<<endl;
				    if(s4==s3)
				    {
				    	int o=0;
				    	//cout<<s4<<endl;
				    	for(int k=i;k<s3.size()+i;k++)
					    {
					    	s5[k]=s[j].s2[o++];
					    }
					  //  cout<<s5<<endl;
					   
					}
					if(b==s5){
						num++;
					}
				}
				
			}
		}
		cout<<num<<endl;
	}
    return 0;
}
