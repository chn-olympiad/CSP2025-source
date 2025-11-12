#include <bits/stdc++.h>

using namespace std;

struct stu
{
	int a1,a2,a3,id;
	
};
stu f1[100010];
stu f2[100010];
stu f3[100010];
int is [100010];
int n,t1,t2,t3;
bool cmp1(stu x,stu y)
{
	return  x.a1 < y.a1;
}

bool cmp2(stu x,stu y)
{
	return  x.a2 < y.a2;
}

bool cmp3(stu x,stu y)
{
	return  x.a3 < y.a3;
}
int sea()
{
	int cnt = 0;
	int d1 = 0,d2 = 0,d3 = 0;
	sort(f1+1,f1+n+1,cmp1);
	sort(f2+1,f2+n+1,cmp2);
	sort(f3+1,f3+n+1,cmp3);
	for(int i = 1;i <= n;i++)
	{
		
	}
	for(int i = 1;i <= n;i++)
	{
		d1= 1;d2= 1;d3=1;
		while(is[f1[d1].id] == 1) d1++;
		while(is[f2[d2].id] == 1) d2++;
		while(is[f3[d3].id] == 1) d3++;
		if(f1[d1].a1 > f2[d2].a2 && f1[d1].a1 >  f3[d3].a3)
		{
			
			is[f1[d1].id] = 1;
			cnt += f1[d1].a1;
			t1++;
			//cnt+=sea();
		}
		if(f2[d2].a2 > f1[d1].a1 && f2[d2].a2 >  f3[d3].a3)
		{
			
			is[f2[d2].id] = 1;
			cnt += f2[d2].a2;
			t2++;
			//cnt+=sea();
		}
		if(f3[d3].a3 > f1[d1].a1 && f3[d3].a3 >  f2[d2].a2 )
		{
			
			is[f3[d3].id] = 1;
			cnt += f3[d3].a3;
			t3++;
			//cnt+=sea();
		}
	}
	return cnt;
}
int main()
{
	freopen("club1.in","r",stdin);
	freopen("club.out","w",stdout);
	int t = 0;
	memset(f1,0,sizeof f1);
	memset(f2,0,sizeof f2);
	memset(f3,0,sizeof f3);
	memset(is,0,sizeof is);
	cin >> t;
	for(int l = 1;l <= t;l++)
	{
		cin >> n;
		for(int i = 1;i <= n;i++)
		{
			cin >> f3[i].a1 >> f3[i].a2 >> f3[i].a3;
			f3[i].id = i;
			f1[i].a1 = f3[i].a1;
			f1[i].a2 = f3[i].a2;
			f1[i].a3 = f3[i].a3; 
			f1[i].id = i;
			
			f2[i].a1 = f3[i].a1;
			f2[i].a2 = f3[i].a2;
			f2[i].a3 = f3[i].a3; 
			f2[i].id = i; 
			
			
		}
		//cout << n /2<< endl;
		cout <<sea() << endl;
		memset(f1,0,sizeof f1);
		memset(f2,0,sizeof f2);
		memset(f3,0,sizeof f3);
		memset(is,0,sizeof is);
	}
	return 0;
}

