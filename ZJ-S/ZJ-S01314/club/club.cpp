#include<bits/stdc++.h>
using namespace std;
struct st
{
	int t1,t2,t3,m1,m2,m3;
}a[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i].t1 >> a[i].t2 >> a[i].t3;
			if(a[i].t1 >= a[i].t2 && a[i].t1 >= a[i].t3)
			{
				a[i].m1 = 1;
				if(a[i].t2 >= a[i].t3)
				{
					a[i].m2 = 2;
					a[i].m3 = 3;
				}
				else
				{
					a[i].m2 = 3;
					a[i].m3 = 2;
				}
			}
			else if(a[i].t2 >= a[i].t3)
			{
				a[i].m1 = 2;
				if(a[i].t1 >= a[i].t3)
				{
					a[i].m2 = 1;
					a[i].m3 = 3;
				}
				else
				{
					a[i].m2 = 1;
					a[i].m3 = 2;
				}
			}
			else
			{
				a[i].m3 = 3;
				if(a[i].t1 >= a[i].t2)
				{
					a[i].m2 = 1;
					a[i].m3 = 2;
				}
				else
				{
					a[i].m2 = 2;
					a[i].m3 = 1;
				}
			}
		}
		int s1[n+7],s2[n+7],s3[n+7],c1 = 0,c2 = 0,c3 = 0;
		for(int i = 1;i <= n;i++)
		{
			if(a[i].m1 == 1)
			{
				if(c1 < n/2)
				{
					c1++;
					s1[c1] = i;
					int x = c1;
					while(--x >= 1&&a[s1[x+1]].t1-a[s1[x+1]].t2 > a[s1[x]].t1-a[s1[x]].t2)
					{
						swap(s1[x],s1[x+1]);
					}
				}
				else
				{
					if(a[i].m2 == 2)
					{
						if(a[i].t1-a[i].t2 > a[s1[c1]].t1-a[s1[c1]].t2)
						{
							c2++;
							s2[c2] = s1[c1];
							s1[c1] = i;
							int x = c1;
							while(--x >= 1&&a[s1[x+1]].t1-a[s1[x+1]].t2 > a[s1[x]].t1-a[s1[x]].t2)
							{
								swap(s1[x],s1[x+1]);
							}
						}
						else 
						{
							c2++;
							s2[c2] = i;
						}
					}
					else 
					{
						int x = c1;
						while(--x >= 1&&a[s1[x+1]].t1-a[s1[x+1]].t3 > a[s1[x]].t1-a[s1[x]].t3)
						{
							swap(s1[x],s1[x+1]);
						}
						if(a[i].t1-a[i].t3 > a[s1[c1]].t1-a[s1[c1]].t3)
						{
							c3++;
							s3[c3] = s1[c1];
							s1[c1] = i;
						}
						else 
						{
							c3++;
							s3[c3] = i;
						}
						while(--x >= 1&&a[s1[x+1]].t1-a[s1[x+1]].t2 > a[s1[x]].t1-a[s1[x]].t2)
						{
							swap(s1[x],s1[x+1]);
						}
					}
				}
			}
			else if(a[i].m1 == 2)
			{
				if(c2 < n/2)
				{
					c2++;
					s2[c2] = i;
					int x = c2;
					while(--x >= 1&&a[s2[x+1]].t2-a[s2[x+1]].t1 > a[s2[x]].t2-a[s2[x]].t1)
					{
						swap(s2[x],s2[x+1]);
					}
				}
				else
				{
					if(a[i].m2 == 1)
					{
						if(a[i].t2-a[i].t1 > a[s2[c2]].t2-a[s2[c2]].t1)
						{
							c1++;
							s1[c1] = s2[c2];
							s2[c2] = i;
							int x = c2;
							while(--x >= 1&&a[s2[x+1]].t2-a[s2[x+1]].t1 > a[s2[x]].t2-a[s2[x]].t1)
							{
								swap(s2[x],s2[x+1]);
							}
						}
						else 
						{
							c1++;
							s1[c1] = i;
						}
					}
					else 
					{	
						int x = c2;
						while(--x >= 1&&a[s2[x+1]].t2-a[s2[x+1]].t3 > a[s2[x]].t2-a[s2[x]].t3)
						{
							swap(s2[x],s2[x+1]);
						}
						if(a[i].t2-a[i].t3 > a[s2[c2]].t2-a[s2[c2]].t3)
						{
							c3++;
							s3[c3] = s2[c2];
							s2[c2] = i;
						}
						else 
						{
							c3++;
							s3[c3] = i;
						}
						x = c2;
						while(--x >= 1&&a[s2[x+1]].t2-a[s2[x+1]].t1 > a[s2[x]].t2-a[s2[x]].t1)
						{
							swap(s2[x],s2[x+1]);
						}
					}
				}
			}
			else
			{
				if(c3 < n/2)
				{
					c3++;
					s3[c3] = i;
					int x = c3;
					while(--x >= 1&&a[s3[x+1]].t3-a[s3[x+1]].t1 > a[s3[x]].t3-a[s3[x]].t1)
					{
						swap(s3[x],s3[x+1]);
					}
				}
				else
				{
					if(a[i].m2 == 1)
					{
						if(a[i].t3-a[i].t1 > a[s3[c3]].t3-a[s3[c3]].t1)
						{
							c1++;
							s1[c1] = s3[c3];
							s1[c3] = i;
							int x = c3;
							while(--x >= 1&&a[s3[x+1]].t3-a[s3[x+1]].t1 > a[s3[x]].t3-a[s3[x]].t1)
							{
								swap(s3[x],s3[x+1]);
							}
						}
						else 
						{
							c1++;
							s1[c1] = i;
						}
					}
					else 
					{
						int x = c3;
						while(--x >= 1&&a[s3[x+1]].t3-a[s3[x+1]].t2 > a[s3[x]].t3-a[s3[x]].t2)
						{
							swap(s3[x],s3[x+1]);
						}
						if(a[i].t3-a[i].t2 > a[s3[c3]].t3-a[s1[c1]].t2)
						{
							c2++;
							s2[c2] = s3[c3];
							s3[c3] = i;
						}
						else 
						{
							c2++;
							s2[c2] = i;
						}
						x = c3;
						while(--x >= 1&&a[s3[x+1]].t3-a[s3[x+1]].t1 > a[s3[x]].t3-a[s3[x]].t1)
						{
							swap(s3[x],s3[x+1]);
						}
					}
				}
			}
		}
		int s = 0;
		for(int i = 1;i <= c1;i++)
		{
			s += a[s1[i]].t1;
		}
		for(int i = 1;i <= c2;i++)
		{
			s += a[s2[i]].t2;
		}
		for(int i = 1;i <= c3;i++)
		{
			s += a[s3[i]].t3;
		}
		cout << s << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
