#include<bits/stdc++.h>
using namespace std;
int a[1000001];
bool cmp1(int x,int y)
{
	if(x>=y)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	//s='290es1q0';
	int le=s.length(),i=0;
	for(int p=0;p<le;p++)
	{
		if(s[p]>='0'&&s[p]<='9')
		{
			cout<<431<<endl;
			if(s[p]=='0')	
				a[i]=0;		
			if(s[p]=='1')		
				a[i]=1;		
			if(s[p]=='2')		
				a[i]=2;		
			if(s[p]=='3')		
				a[i]=3;		 
			if(s[p]=='4')		
				a[i]=4;		 
			if(s[p]=='5')		
				a[i]=5;		 
			if(s[p]=='6')		
				a[i]=6;		 
			if(s[p]=='7')
				a[i]=7;		 	
			if(s[p]=='8')		
				a[i]=8;
			if(s[p]=='9')		   
				a[i]=9;	
			i++;	
		}	
	}
	sort(a,a+le,cmp1);
	int mp=0;
	for(int j=0;j<i;j++)
	{
		mp=mp*10+a[j];
	}
	cout<<mp<<" "<<" ";
	//fclose(stdin);
	//fclose(stdout);
	//cout<<9348798;
	return 0;
}
