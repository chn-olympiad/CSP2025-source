#include<bits/stdc++.h>
using namespace std;
struct node
{
	int a=0,b=0,c=0,num;
	int fl=-1;
};
bool ch1(node x,node y)
{
	return x.a>y.a;
}
bool ch2(node x,node y)
{
	return x.b>y.b;
}
bool ch3(node x,node y)
{
	return x.c>y.c;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		node s[n+5];
		int f1=0,f2=0,f3=0;
		int len=n/2;
		node ex1[n+5],ex2[n+5],ex3[n+5];
		for(int i=1;i<=n;i++)
		{
			cin>>s[i].a>>s[i].b>>s[i].c;
			ex1[i].a=s[i].a;
			ex2[i].b=s[i].b;
			ex3[i].c=s[i].c;
			ex1[i].num=ex2[i].num=ex3[i].num=i;
		}
		sort(ex1+1,ex1+1+n,ch1);
		sort(ex2+1,ex2+1+n,ch2);
		sort(ex3+1,ex3+1+n,ch3);
		for(int i=1;i<=len;i++)
		{
			if(ex1[i].a>s[ex1[i].num].b && ex1[i].a>s[ex1[i].num].c && s[ex1[i].num].fl==-1&&ex1[i].a-ex1[i+1].a<=ex1[i].a-s[ex1[i].num].b&&ex1[i].a-ex1[i+1].a<=ex1[i].a-s[ex1[i].num].c)
			{
				f1+=ex1[i].a;
				s[ex1[i].num].fl=1;
			}
			if(ex2[i].b>s[ex2[i].num].a && ex2[i].b>s[ex2[i].num].c && s[ex2[i].num].fl==-1&&ex2[i].b-ex2[i+1].b<=ex2[i].b-s[ex2[i].num].a&&ex2[i].b-ex2[i+1].b<=ex2[i].b-s[ex2[i].num].c)
			{
				f1+=ex2[i].b;
				s[ex2[i].num].fl=2;
			}
			if(ex3[i].c>s[ex3[i].num].b && ex3[i].c>s[ex3[i].num].a && s[ex3[i].num].fl==-1&&ex3[i].c-ex3[i+1].c<=ex3[i].c-s[ex3[i].num].a&&ex3[i].c-ex3[i+1].c<=ex3[i].c-s[ex3[i].num].b)
			{
				f3+=ex3[i].c;
				s[ex3[i].num].fl=3;
			}
		}
		cout<<f1+f2+f3<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}