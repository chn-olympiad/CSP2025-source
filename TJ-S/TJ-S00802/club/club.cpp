#include <bits/stdc++.h>
using namespace std;
int t,n,c,con;
struct S{
	int a;
	int b;
	int c;
};
S s[10001];
int arr[10001];
int arr1[10001];
int arr2[10001];
int arr3[10001];

int fun(int num)
{
	if(arr[num]==0)
	{
		return s[num].a;
	}
	else if(arr[num]==1)
	{
		return s[num].b;
	}
	else if(arr[num]==2)
	{
		return s[num].c;
	}
}

bool cmp(S aa,S bb)
{
	return aa.a>bb.a;
}
bool x(int aa,int bb)
{
	return s[aa].a>s[bb].a;
}
bool y(int aa,int bb)
{
	return s[aa].b>s[bb].b;
}
bool z(int aa,int bb)
{
	return s[aa].c>s[bb].c;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset(s,0,sizeof(s));
		memset(arr1,0,sizeof(arr1));
		memset(arr2,0,sizeof(arr2));
		memset(arr3,0,sizeof(arr3));
		for(int i=0;i<n;i++)
		{
			cin>>s[i].a>>s[i].b>>s[i].c;
			if(s[i].a>s[i].b&&s[i].a>s[i].c)
			{
				arr[i]=0;
			}
			else if(s[i].b>s[i].a&&s[i].b>s[i].c)
			{
				arr[i]=1;
			}
			else if(s[i].c>s[i].b&&s[i].c>s[i].a)
			{
				arr[i]=2;
			}
			arr1[i]=i;
			arr2[i]=i;
			arr3[i]=i;
			
			sort(s,s+n,cmp);
			sort(arr1,arr1+n,x);
			sort(arr2,arr2+n,y);
			sort(arr3,arr3+n,z);
		}
		//cout<<s[0].a<<" "<<s[0].b<<" "<<s[0].c;

		//cout<<arr2[1]<<" "<<arr3[0];
		if(s[arr2[0]].b==0&&s[arr3[0]].b==0)
		{
			for(int i=0;i<n/2;i++)
			{
				con+=s[i].a;
			}
		}
		
		else if(n==2)
		{
			
			if(arr[0]!=arr[1])
			{
				for(int i=0;i<2;i++)
				{
					con+=fun(i);
				}
			}
			else
			{
				if(arr[0]==0)
				{
					con=max(max(max(s[0].a+s[1].b,s[0].a+s[1].c),s[1].a+s[0].b),s[1].a+s[0].c);
				}
				if(arr[0]==1)
				{
					con=max(max(max(s[0].b+s[1].a,s[0].b+s[1].c),s[1].b+s[0].a),s[1].b+s[0].c);
				}
				if(arr[0]==2)
				{
					con=max(max(max(s[0].c+s[1].b,s[0].c+s[1].a),s[1].c+s[0].b),s[1].c+s[0].a);
				}
			}
		}
		
		else 
		cout<<con<<endl;
		
	}
	
	return 0;
}

