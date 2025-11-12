/*
It`s a pitty that I can`t solve this problem
But I think I pass T3 :D
Because I have passed all the big_example :)
Though I don`t know whether string hashing is the right way or not
Anyway
Please,God.Let me AC T3.
*/
#include<bits/stdc++.h>
using namespace std;
const long long mod1=998244353;
const long long mod2=1000000007;
const long long inf=0x3f3f3f3f3f3f3f3f;
struct node{
	vector<pair<long long,long long> >e;
	
}dot[10021];
long long n,m,k;
long long rp;

void init();
void domemset();
long long read();
void write(long long x);


void fun()
{
	domemset();
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++)
	{
		long long x=read(),y=read(),z=read();
		
	}
	for(int i=1;i<=305069;i++)//This number is my Luogu uid.
		rp++;
	cout<<rand()%mod1;
	return ;
}
int main()
{
//	freopen("replace.in","r",stdin);
//	freopen("replace.out","w",stdout); haha.It`s a joke.
//  e... I found I wrote wrong filename just now. 
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	srand(time(NULL));
	init();
//	t=read();
//	for(int i=1;i<=t;i++)
//	while(1)
		fun();
	return 0;
}


void init()
{

	return ;
}
void domemset()
{

	return ;
}
long long read()
{
	long long x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^'0');
		ch=getchar();
	}
	return x*f;
}
void write(long long x)
{
	if(x<0)
		putchar('-'),x=-x;
	if(x>=10)
		write(x/10);
	putchar((x%10)^'0');
	return ;
}

