#include<iostream>
#include<iomanip>
using namespace std;



int main()
{
	freopen("number.in","r",sb)
	freopen("number.out","w",out)
	string sb;
	int dxxk;
	int jntm[];
	for(int i=1;i<=len(sb);i++)
	{
		if(sb[i]==9 || sb[i]==8 || sb[i]==7 || sb[i]==6 || sb[i]==5 || sb[i]==4 || sb[i]==3 || sb[i]==2 || sb[i]==1 || sb[i]==0)
		{
			cin>>jntm[i];
		}
		
	}
	for(int i=1;i<=len(jntm);i++)
	{
		if(jntm[i]>jntm[i+1])
		{
			dxxk=jntm[i];
			jntm[i]=jntm[i+1];
			jntm[i+1]=dxxk;
		}
		cout<<jntm;
	}
	return 0;
}
