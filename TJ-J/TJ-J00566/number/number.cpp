#include<bits/stdc++.h>
using namespace std;
int s;
int ge,shi,bai,qian,a1,a2,a3,a4;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	if(s>1000&&s<10000)
	{
	ge=s%10;
	shi=s%100/10;
	bai=(s/10)%100/10;
	qian=(s/10)%1000/100;
	if(ge>shi&&ge>bai&&ge>qian)
	{
		a1=ge;
	}else if(shi>ge&&shi>bai&&shi>qian)
	{
		a1=shi;
	}else if(bai>ge&&bai>shi&&bai>qian)
	{
		a1=bai;
	}else if(qian>bai&&qian>ge&&qian>shi)
	{
		a1=qian;
	}//第一位 
	if(ge<shi&&ge>bai&&ge>qian)
	{
		a2=ge;
	}else if(shi<ge&&shi>bai&&shi>qian)
	{
		a2=shi;
	}else if(bai<ge&&bai>shi&&bai>qian)
	{
		a2=bai;
	}else if(qian<bai&&qian>ge&&qian>shi)
	{
		a2=qian;
	}//第二位
	if(ge<shi&&ge<bai&&ge>qian)
	{
		a3=ge;
	}else if(shi<ge&&shi<bai&&shi>qian)
	{
		a3=shi;
	}else if(bai<ge&&bai<shi&&bai>qian)
	{
		a3=bai;
	}else if(qian<bai&&qian<ge&&qian>shi)
	{
		a3=qian;
	} //第三位
	if(ge<shi&&ge<bai&&ge<qian)
	{
		a4=ge;
	}else if(shi<ge&&shi<bai&&shi<qian)
	{
		a4=shi;
	}else if(bai<ge&&bai<shi&&bai<qian)
	{
		a4=bai;
	}else if(qian<bai&&qian<ge&&qian<shi)
	{
		a4=qian;
	} 
	
		cout<<a1;
		cout<<a2;
		cout<<a3;
		cout<<a4;
		return 0;
	}
	if(s>=0&&s<10)
	{
		cout<<s;
		return 0;
	}
	if(s>=10&&s<100)
	{
			if(ge>shi&&ge>bai&&ge>qian)
		{
		a1=ge;
		}else if(shi>ge&&shi>bai&&shi>qian)
		{
		a1=shi;
		}else if(bai>ge&&bai>shi&&bai>qian)
		{
		a1=bai;
		}else if(qian>bai&&qian>ge&&qian>shi)
		{
		a1=qian;
		}//第一位 
		if(ge<shi&&ge>bai&&ge>qian)
		{
		a2=ge;
	}else if(shi<ge&&shi>bai&&shi>qian)
	{
		a2=shi;
	}else if(bai<ge&&bai>shi&&bai>qian)
	{
		a2=bai;
	}
	cout<<a1<<a2;
	}
	

	
	return 0;
}
