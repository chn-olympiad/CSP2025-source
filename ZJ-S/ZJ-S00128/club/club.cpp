#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int de1[N],de2[N],de3[N];
struct FZH
{
	int a,b,c,id;
	int cha;
	
}score[N];
int mymax(int a,int b,int c)
{
	return max(a,max(b,c)); 
}
int mysecond(int a,int b,int c)
{
	if(a>b && a>c)
	{
		if(b>c) return b;
		else return c;	
	} 
	else if(b>c&&b>a)
	{
		if(a>c) return a;
		else return c; 
	}
	else if(c>a&&c>b)
	{
		if(b>a) return b;
		else return a;
	}
	else
	{
		if(a==b) return a;
		else if(a==c) return a;
		else return b;
	}
}
bool cmp(int a,int b)
{
	return score[a].cha>score[b].cha;
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
		int c1=0,c2=0,c3=0;
		long long sum=0;
		for(int i=1;i<=n;i++)
		{
			cin>>score[i].a>>score[i].b>>score[i].c;
			
			score[i].cha=abs(mymax(score[i].a,score[i].b,score[i].c)-mysecond(score[i].a,score[i].b,score[i].c));
			//cout<<mymax(score[i].a,score[i].b,score[i].c)<<" ";
			//cout<<mysecond(score[i].a,score[i].b,score[i].c)<<endl;
			//cout<<"score "<<i<<" "<<score[i].cha<<endl;
			sum+=mymax(score[i].a,score[i].b,score[i].c);
			score[i].id=i;
			if(score[i].a>=score[i].b && score[i].a>=score[i].c)  de1[++c1]=score[i].id;
			else if(score[i].b>=score[i].a && score[i].b>=score[i].c)  de2[++c2]=score[i].id;
			else if(score[i].c>=score[i].a && score[i].c>=score[i].b)  de3[++c3]=score[i].id;
			
		}		
		if(c1>n/2)
		{
			sort(de1+1,de1+c1+1,cmp);
			while(c1>n/2)
			{
				sum-=score[de1[c1]].cha;
				c1--;				
			}
		}
		else if(c2>n/2)
		{
			sort(de2+1,de2+c2+1,cmp);
			while(c2>n/2)
			{
				sum-=score[de2[c2]].cha;
				c2--;				
			}			
		}
		else if(c3>n/2)
		{
			sort(de3+1,de3+c3+1,cmp);
			while(c3>n/2)
			{
				sum-=score[de3[c3]].cha;
				c3--;				
			}				
		}
		cout<<sum<<endl;
	}
	return 0;	
} 
