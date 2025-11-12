#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c,maxx;
}mb[100010];
vector<node> a1;
vector<node> b1;
vector<node> c1;
long long ans_f = 0;
int n;
void dfs(int pos,int xuan,int a1,int b1,int c1,long long ans)
{
	if(pos==n)
	{
		if(xuan==1)
		{
			ans_f = max(mb[pos].a+ans,ans_f);
		}else if(xuan==2)
		{
			ans_f = max(mb[pos].b+ans,ans_f);
		}else
		{
			ans_f = max(mb[pos].c+ans,ans_f);
		}
	}
	long long ans1 = 0;
	if(xuan==1)
	{
		ans1 = mb[pos].a;
	}else if(xuan==2)
	{
		ans1 = mb[pos].b;
	}else
	{
		ans1 = mb[pos].c;
	}
	
	if(a1<n/2)
	{
		dfs(pos+1,1,a1+1,b1,c1,ans1+ans);
	}
	if(b1<n/2)
	{
		dfs(pos+1,2,a1,b1+1,c1,ans1+ans);
	}
	if(c1<n/2)
	{
		dfs(pos+1,3,a1,b1,c1+1,ans1+ans);
	}
}
bool cmp1(node &temp1,node &temp2)
{
	if(temp1.a==temp2.a)
	{
		if(temp1.b<temp1.c)
		{
			temp1.maxx = 3;
		}else
		{
			temp1.maxx = 2;
		}
		if(temp2.b<temp2.c)
		{
			temp2.maxx = 3;
		}else
		{
			temp2.maxx = 2;
		}
		return max(temp1.b,temp1.c)<max(temp2.b,temp2.c);
	}
	else{
		return temp1.a>temp2.a;
	}
}
bool cmp2(node &temp1,node &temp2)
{
	if(temp1.b==temp2.b)
	{
		if(temp1.a<temp1.c)
		{
			temp1.maxx = 3;
		}else
		{
			temp1.maxx = 1;
		}
		if(temp2.a<temp2.c)
		{
			temp2.maxx = 3;
		}else
		{
			temp2.maxx = 1;
		}
		return max(temp1.a,temp1.c)<max(temp2.a,temp2.c);
	}
	else{
		return temp1.b>temp2.b;
	}
}
bool cmp3(node &temp1,node &temp2)
{
	if(temp1.c==temp2.c)
	{
		if(temp1.b<temp1.a)
		{
			temp1.maxx = 1;
		}else
		{
			temp1.maxx = 2;
		}
		if(temp2.b<temp2.a)
		{
			temp2.maxx = 1;
		}else
		{
			temp2.maxx = 2;
		}
		return max(temp1.a,temp1.b)<max(temp2.a,temp2.b);
	}
	else{
		return temp1.c>temp2.c;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--)
	{	
		cin >> n;
		if(n<=10)
		{
			ans_f = 0;
		
		for(int i = 1;i<=n;i++)
		{
			cin >> mb[i].a >> mb[i].b >> mb[i].c;
		}
		dfs(1,1,1,0,0,0);
		dfs(1,2,0,1,0,0);
		dfs(1,3,0,0,1,0);
		cout << ans_f<<endl;
		}
		else
		{
		long long ans = 0;
		cin >> n;
		node kong;
		kong.a = 0;
		kong.b = 0;
		kong.c = 0;
		kong.maxx = 0;
		memset(mb,0,sizeof(mb));
		a1.clear();
		b1.clear();
		c1.clear();
		for(int i = 1;i<=n;i++)
		{
			cin >> mb[i].a >> mb[i].b >> mb[i].c;
			if(mb[i].a>max(mb[i].b,mb[i].c))
			{
				mb[i].maxx = 1;
				a1.push_back(mb[i]);
			}
			else if(mb[i].b>max(mb[i].a,mb[i].c))
			{
				mb[i].maxx = 2;
				b1.push_back(mb[i]);
			}else
			{
				mb[i].maxx = 3;
				c1.push_back(mb[i]);
			}
		}
		if(a1.size()>n/2)
		{
			sort(a1.begin(),a1.end(),cmp1);
			int len_a = a1.size();
			for(int i = n/2;i<len_a;i++)
			{
				int next = a1[i].maxx;
				if(a1[i].maxx == 2)
				{
					b1.push_back(a1[i]);
					ans-=a1[i].a;
				}else
				{
					c1.push_back(a1[i]);
					ans-=a1[i].a;
				}
			}
		}if(b1.size()>n/2)
		{
			sort(b1.begin(),b1.end(),cmp2);
			int len_b = b1.size();
			for(int i = n/2;i<len_b;i++)
			{
				int next = b1[i].maxx;
				if(b1[i].maxx == 1)
				{
					a1.push_back(b1[i]);
					ans-=b1[i].b;
				}else
				{
					c1.push_back(b1[i]);
					ans-=b1[i].b;
				}
			}
		}if(c1.size()>n/2)
		{
			sort(c1.begin(),c1.end(),cmp3);
			int len_c = c1.size();
			for(int i = n/2;i<len_c;i++)
			{
				int next = c1[i].maxx;
				if(c1[i].maxx == 1)
				{
					a1.push_back(c1[i]);
					ans-=c1[i].c;
				}else
				{
					b1.push_back(c1[i]);
					ans-=c1[i].c;
				}
			}
		}
		int len_a1 = a1.size();
		int len_b1 = b1.size();
		int len_c1 = c1.size();
		for(int i = 0;i<len_a1;i++)
		{
//			cout << a1[i].a << a1[i].b << a1[i].c << endl; 
			ans+=a1[i].a;
		}
//		cout << endl;
		for(int i = 0;i<len_b1;i++)
		{
//			cout << b1[i].a << b1[i].b << b1[i].c << endl; 
			ans+=b1[i].b;
		}
//		cout << endl;
		for(int i = 0;i<len_c1;i++)
		{
//			cout << c1[i].a << c1[i].b << c1[i].c << endl; 
			ans+=c1[i].c;
		}
//		cout << endl;
		cout << ans << endl;
		}
	}
	return 0;
 } 
