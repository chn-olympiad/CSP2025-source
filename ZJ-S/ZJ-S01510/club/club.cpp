#include<bits/stdc++.h>
using namespace std;
long long t;
long long n;
struct man{
	long long x,y,z;
};
man people[100009];
man pp[100009];
bool cmpp(man a,man b)
{
	return a.x>b.x;
}
long long tonton[3];
long long res = 0;
long long firs[100009];
long long secon[100009];
long long thir[100009];
long long cnt_1,cnt_2,cnt_3;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(long long kd = 0;kd<t;kd++)
	{
		scanf("%lld",&n);
		for(long long i = 1;i<=n;i++)
		{
			scanf("%lld %lld %lld",&people[i].x,&people[i].y,&people[i].z);
			if(people[i].x>=people[i].y&&people[i].x>=people[i].z)
			{
				pp[i].x = people[i].x;
				pp[i].y = 0;
				pp[i].z = max(people[i].y,people[i].z)-pp[i].x;
			}
			else if(people[i].y>=people[i].x&&people[i].y>=people[i].z)
			{
				pp[i].x = people[i].y;
				pp[i].y = 1;
				pp[i].z = max(people[i].x,people[i].z)-pp[i].x;
			}
			else{
				pp[i].x = people[i].z;
				pp[i].y = 2;
				pp[i].z = max(people[i].y,people[i].x)-pp[i].x;
			}	
		}
		sort(pp+1,pp+1+n,cmpp);
		for(long long i = 1;i<=n;i++)
		{
			res+=pp[i].x;
			tonton[pp[i].y]++;
			if(pp[i].y == 0)
			{
				firs[cnt_1++] = pp[i].z;
			}
			else if(pp[i].y == 1)
			{
				secon[cnt_2++] = pp[i].z;
			}
			else if(pp[i].y == 2)
			{
				thir[cnt_3++] = pp[i].z;
			}
		}
		if(cnt_1>0)
		{
			sort(firs,firs+cnt_1);
		}
		
		if(cnt_2>0)
		{
			sort(secon,secon+cnt_2);
		}
		
		if(cnt_3>0)
		{
			sort(thir,thir+cnt_3);
		}
		cnt_1--;
		cnt_2--;
		cnt_3--;
		while(tonton[0]>(n/2))
		{
			res+=firs[tonton[0]-1];
			tonton[0]--;
		}
		while(tonton[1]>(n/2))
		{
			res+=secon[tonton[1]-1];
			tonton[1]--;
		}
		while(tonton[2]>(n/2))
		{
			res+=thir[tonton[2]-1];
			tonton[2]--;
		}
		
		cout << res << endl;
		res = 0;
		tonton[0] = tonton[1] = tonton[2] = 0;
		for(int i = 0;i<=cnt_1+1;i++)
		{
			firs[i] = 0;
		}
		for(int i = 0;i<=cnt_2+1;i++)
		{
			secon[i] = 0;
		}
		for(int i = 0;i<=cnt_3+1;i++)
		{
			thir[i] = 0;
		}
		cnt_1 = cnt_2 =cnt_3 = 0;
	}
	return 0;
}
