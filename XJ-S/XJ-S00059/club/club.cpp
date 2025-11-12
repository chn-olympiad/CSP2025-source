#include <bits/stdc++.h>//贪心版本 
#define int long long
using namespace std;
int n, t, ans1, ans2, ans3, ans4, a1, a2, a3, ans;//a1:部门1被放入的人数 
struct S
{
	int a[5], aa, bb, cc;//aa:一大与二大的差 
	int x, y, z, xx, yy, zz;//xx:部门编号 
};
S s[100005];
bool cmp(S p, S q)
{
	if (p.x != q.x)
	{
		return p.x > q.x;
	}
	else
	{
		if (p.y != q.y)
		{
			return p.y > q.y;
		}
		else
		{
			return p.z > q.z;
		}
	}
}
bool cmp1(S p, S q)
{
	if (p.aa != q.aa)
	{
		return p.aa > q.aa;
	}
	else
	{
		if (p.x != q.x)
		{
			return p.x > q.x;
		}
		else
		{
			if (p.y != q.y)
			{
				return p.y > q.y;
			}
			else
			{
				return p.z > q.z;
			}
		}
	}
}
bool cmp2(S p, S q)
{
	if (p.bb != q.bb)
	{
		return p.bb > q.bb;
	}
	else
	{
		if (p.x != q.x)
		{
			return p.x > q.x;
		}
		else
		{
			if (p.y != q.y)
			{
				return p.y > q.y;
			}
			else
			{
				return p.z > q.z;
			}
		}
	}
}
bool cmp3(S p, S q)
{
	if (p.cc != q.cc)
	{
		return p.cc > q.cc;
	}
	else
	{
		if (p.x != q.x)
		{
			return p.x > q.x;
		}
		else
		{
			if (p.y != q.y)
			{
				return p.y > q.y;
			}
			else
			{
				return p.z > q.z;
			}
		}
	}
}
signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while(t--)
	{
		cin >> n;
		ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0, ans = 0;
		a1 = 0;
		a2 = 0;
		a3 = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> s[i].a[1] >> s[i].a[2] >> s[i].a[3];
			if(s[i].a[1] >= s[i].a[2])
			{//从大到小判断 
				if(s[i].a[1] >= s[i].a[3])
				{
					s[i].x = s[i].a[1];
					s[i].xx = 1;
					if (s[i].a[2] >= s[i].a[3])
					{
						s[i].y = s[i].a[2];
						s[i].yy = 2;
						s[i].z = s[i].a[3];//3<2<1
						s[i].zz = 3;
						s[i].aa = s[i].x - s[i].y;
						s[i].bb = s[i].y - s[i].z;
						s[i].cc = s[i].x - s[i].z;
					}
					else
					{
						s[i].y = s[i].a[3];
						s[i].yy = 3;
						s[i].z = s[i].a[2];//2<3<1
						s[i].zz = 2;
						s[i].aa = s[i].x - s[i].y;
						s[i].bb = s[i].y - s[i].z;
						s[i].cc = s[i].x - s[i].z;
					}
				}
				else
				{
					s[i].x = s[i].a[3];
					s[i].xx = 3;
					s[i].y = s[i].a[1];
					s[i].yy = 1;
					s[i].z = s[i].a[2];//2<1<3
					s[i].zz = 2;
					s[i].aa = s[i].x - s[i].y;
					s[i].bb = s[i].y - s[i].z;
					s[i].cc = s[i].x - s[i].z;
				}
			}
			else
			{//从小到大判断 
				if(s[i].a[1] <= s[i].a[3])
				{
					s[i].z = s[i].a[1];
					s[i].zz = 1;
					if (s[i].a[2] >= s[i].a[3])
					{
						s[i].x = s[i].a[2];
						s[i].xx = 2;
						s[i].y = s[i].a[3];//1<3<2
						s[i].yy = 3;
						s[i].aa = s[i].x - s[i].y;
						s[i].bb = s[i].y - s[i].z;
						s[i].cc = s[i].x - s[i].z;
					}
					else
					{
						s[i].x = s[i].a[3];
						s[i].xx = 3;
						s[i].y = s[i].a[2];//1<2<3
						s[i].yy = 2;
						s[i].aa = s[i].x - s[i].y;
						s[i].bb = s[i].y - s[i].z;
						s[i].cc = s[i].x - s[i].z;
					}
				}
				else
				{
					s[i].z = s[i].a[3];
					s[i].zz = 3;
					s[i].y = s[i].a[1];
					s[i].yy = 1;
					s[i].x = s[i].a[2];//3<1<2 
					s[i].xx = 2;
					s[i].aa = s[i].x - s[i].y;
					s[i].bb = s[i].y - s[i].z;
					s[i].cc = s[i].x - s[i].z;
				}
			}
		}//输入+判断 
//		for (int i = 1; i <= n; i++)
//		{
//			cout << s[i].x << " " << s[i].y << " " << s[i].z << endl;
//		}
//		cout << endl;
		sort(s + 1, s + n + 1, cmp);
		for (int i = 1; i <= n; i++)
		{
			if (s[i].xx == 1)//在最大部门是1的情况下 
			{
				if ((a1 + 1) <= (n / 2))//最大部门编号可用 
				{
					a1++;
					ans1 += s[i].x;
//					cout << "1x ";
				}
				else//否则判断第二大是哪个 
				{
					if (s[i].yy == 2)
					{
						if ((a2 + 1) <= (n / 2))//第二大可用 
						{
							a2++;
							ans1 += s[i].y;
//							cout << "2y ";
						}
						else
						{
							a3++;
							ans1 += s[i].z;
//							cout << "3z ";
						}
					}
					else
					{
						if ((a3 + 1) <= (n / 2)) 
						{
							a3++;
							ans1 += s[i].y;
//							cout << "3y ";
						}
						else
						{
							a2++;
							ans1 += s[i].z;
//							cout << "2z ";
						}
					}
				}
			}
			else if (s[i].xx == 2)//2：第一 
			{
				if ((a2 + 1) <= (n / 2))//最大部门编号可用 
				{
					a2++;
					ans1 += s[i].x;
//					cout << "2x ";
				}
				else//否则判断第二大是哪个 
				{
					if (s[i].yy == 1)
					{
						if ((a1 + 1) <= (n / 2))//第二大可用 
						{
							a1++;
							ans1 += s[i].y;
//							cout << "1y ";
						}
						else
						{
							a3++;
							ans1 += s[i].z;
//							cout << "3z ";
						}
					}
					else
					{
						if ((a3 + 1) <= (n / 2)) 
						{
							a3++;
							ans1 += s[i].y;
//							cout << "3y ";
						}
						else
						{
							a1++;
							ans1 += s[i].z;
//							cout << "1z ";
						}
					}
				}
			}
			else
			{
				if ((a3 + 1) <= (n / 2))//最大部门编号可用 
				{
					a3++;
					ans1 += s[i].x;
//				cout << "3x ";
				}
				else//否则判断第二大是哪个 
				{
					if (s[i].yy == 2)
					{
						if ((a2 + 1) <= (n / 2))//第二大可用 
						{
							a2++;
							ans1 += s[i].y;
//							cout << "2y ";
						}
						else
						{
							a1++;
							ans1 += s[i].z;
//							cout << "1z ";
						}
					}
					else
					{
						if ((a1 + 1) <= (n / 2)) 
						{
							a1++;
							ans1 += s[i].y;
//							cout << "1y ";
						}
						else
						{
							a2++;
							ans1 += s[i].z;
//							cout << "2z ";
						}
					}
				}
			}
		}
//		for (int i = 1; i <= n; i++)
//		{
//			cout << s[i].x << " " << s[i].y << " " << s[i].z << endl;
//		}
//		cout << endl;
		a1 = 0;
		a2 = 0;
		a3 = 0;
		sort(s + 1, s + n + 1, cmp1);
		for (int i = 1; i <= n; i++)
		{
			if (s[i].xx == 1)//在最大部门是1的情况下 
			{
				if ((a1 + 1) <= (n / 2))//最大部门编号可用 
				{
					a1++;
					ans2 += s[i].x;
//					cout << "1x " << s[i].x;
				}
				else//否则判断第二大是哪个 
				{
					if (s[i].yy == 2)
					{
						if ((a2 + 1) <= (n / 2))//第二大可用 
						{
							a2++;
							ans2 += s[i].y;
//							cout << "2y ";
						}
						else
						{
							a3++;
							ans2 += s[i].z;
//							cout << "3z ";
						}
					}
					else
					{
						if ((a3 + 1) <= (n / 2)) 
						{
							a3++;
							ans2 += s[i].y;
//							cout << "3y ";
						}
						else
						{
							a2++;
							ans2 += s[i].z;
//							cout << "2z ";
						}
					}
				}
			}
			else if (s[i].xx == 2)//2：第一 
			{
				if ((a2 + 1) <= (n / 2))//最大部门编号可用 
				{
					a2++;
					ans2 += s[i].x;
//					cout << "2x ";
				}
				else//否则判断第二大是哪个 
				{
					if (s[i].yy == 1)
					{
						if ((a1 + 1) <= (n / 2))//第二大可用 
						{
							a1++;
							ans2 += s[i].y;
//							cout << "1y ";
						}
						else
						{
							a3++;
							ans2 += s[i].z;
//							cout << "3z ";
						}
					}
					else
					{
						if ((a3 + 1) <= (n / 2)) 
						{
							a3++;
							ans2 += s[i].y;
//							cout << "3y ";
						}
						else
						{
							a1++;
							ans2 += s[i].z;
//							cout << "1z ";
						}
					}
				}
			}
			else
			{
				if ((a3 + 1) <= (n / 2))//最大部门编号可用 
				{
					a3++;
					ans2 += s[i].x;
//				cout << "3x ";
				}
				else//否则判断第二大是哪个 
				{
					if (s[i].yy == 2)
					{
						if ((a2 + 1) <= (n / 2))//第二大可用 
						{
							a2++;
							ans2 += s[i].y;
//							cout << "2y ";
						}
						else
						{
							a1++;
							ans2 += s[i].z;
//							cout << "1z ";
						}
					}
					else
					{
						if ((a1 + 1) <= (n / 2)) 
						{
							a1++;
							ans2 += s[i].y;
//							cout << "1y ";
						}
						else
						{
							a2++;
							ans2 += s[i].z;
//							cout << "2z ";
						}
					}
				}
			}
		}
		
//		for (int i = 1; i <= n; i++)
//		{
//			cout << s[i].x << " " << s[i].y << " " << s[i].z << endl;
//		}
//		cout << endl;
		a1 = 0;
		a2 = 0;
		a3 = 0;
		sort(s + 1, s + n + 1, cmp2);
		for (int i = 1; i <= n; i++)
		{
			if (s[i].xx == 1)//在最大部门是1的情况下 
			{
				if ((a1 + 1) <= (n / 2))//最大部门编号可用 
				{
					a1++;
					ans3 += s[i].x;
//					cout << "1x ";
				}
				else//否则判断第二大是哪个 
				{
					if (s[i].yy == 2)
					{
						if ((a2 + 1) <= (n / 2))//第二大可用 
						{
							a2++;
							ans3 += s[i].y;
//							cout << "2y ";
						}
						else
						{
							a3++;
							ans3 += s[i].z;
//							cout << "3z ";
						}
					}
					else
					{
						if ((a3 + 1) <= (n / 2)) 
						{
							a3++;
							ans3 += s[i].y;
//							cout << "3y ";
						}
						else
						{
							a2++;
							ans3 += s[i].z;
//							cout << "2z ";
						}
					}
				}
			}
			else if (s[i].xx == 2)//2：第一 
			{
				if ((a2 + 1) <= (n / 2))//最大部门编号可用 
				{
					a2++;
					ans3 += s[i].x;
//					cout << "2x ";
				}
				else//否则判断第二大是哪个 
				{
					if (s[i].yy == 1)
					{
						if ((a1 + 1) <= (n / 2))//第二大可用 
						{
							a1++;
							ans3 += s[i].y;
//							cout << "1y ";
						}
						else
						{
							a3++;
							ans3 += s[i].z;
//							cout << "3z ";
						}
					}
					else
					{
						if ((a3 + 1) <= (n / 2)) 
						{
							a3++;
							ans3 += s[i].y;
//							cout << "3y ";
						}
						else
						{
							a1++;
							ans3 += s[i].z;
//							cout << "1z ";
						}
					}
				}
			}
			else
			{
				if ((a3 + 1) <= (n / 2))//最大部门编号可用 
				{
					a3++;
					ans3 += s[i].x;
//				cout << "3x ";
				}
				else//否则判断第二大是哪个 
				{
					if (s[i].yy == 2)
					{
						if ((a2 + 1) <= (n / 2))//第二大可用 
						{
							a2++;
							ans3 += s[i].y;
//							cout << "2y ";
						}
						else
						{
							a1++;
							ans3 += s[i].z;
//							cout << "1z ";
						}
					}
					else
					{
						if ((a1 + 1) <= (n / 2)) 
						{
							a1++;
							ans3 += s[i].y;
//							cout << "1y ";
						}
						else
						{
							a2++;
							ans3 += s[i].z;
//							cout << "2z ";
						}
					}
				}
			}
		}
//		for (int i = 1; i <= n; i++)
//		{
//			cout << s[i].x << " " << s[i].y << " " << s[i].z << endl;
//		}
//		cout << endl;
		a1 = 0;
		a2 = 0;
		a3 = 0;
		sort(s + 1, s + n + 1, cmp3);
		for (int i = 1; i <= n; i++)
		{
			if (s[i].xx == 1)//在最大部门是1的情况下 
			{
//				cout << "*" << a1; 
				if ((a1 + 1) <= (n / 2))//最大部门编号可用 
				{
					a1++;
					ans4 += s[i].x;
//					cout << "1x " << s[i].x;
				}
				else//否则判断第二大是哪个 
				{
					if (s[i].yy == 2)
					{
						if ((a2 + 1) <= (n / 2))//第二大可用 
						{
							a2++;
							ans4 += s[i].y;
//							cout << "2y ";
						}
						else
						{
							a3++;
							ans4 += s[i].z;
//							cout << "3z ";
						}
					}
					else
					{
						if ((a3 + 1) <= (n / 2)) 
						{
							a3++;
							ans4 += s[i].y;
//							cout << "3y ";
						}
						else
						{
							a2++;
							ans4 += s[i].z;
//							cout << "2z ";
						}
					}
				}
			}
			else if (s[i].xx == 2)//2：第一 
			{
				if ((a2 + 1) <= (n / 2))//最大部门编号可用 
				{
					a2++;
					ans4 += s[i].x;
//					cout << "2x ";
				}
				else//否则判断第二大是哪个 
				{
					if (s[i].yy == 1)
					{
						if ((a1 + 1) <= (n / 2))//第二大可用 
						{
							a1++;
							ans4 += s[i].y;
//							cout << "1y ";
						}
						else
						{
							a3++;
							ans4 += s[i].z;
//							cout << "3z ";
						}
					}
					else
					{
						if ((a3 + 1) <= (n / 2)) 
						{
							a3++;
							ans4 += s[i].y;
//							cout << "3y ";
						}
						else
						{
							a1++;
							ans4 += s[i].z;
//							cout << "1z ";
						}
					}
				}
			}
			else
			{
				if ((a3 + 1) <= (n / 2))//最大部门编号可用 
				{
					a3++;
					ans4 += s[i].x;
//				cout << "3x ";
				}
				else//否则判断第二大是哪个 
				{
					if (s[i].yy == 2)
					{
						if ((a2 + 1) <= (n / 2))//第二大可用 
						{
							a2++;
							ans4 += s[i].y;
//							cout << "2y ";
						}
						else
						{
							a1++;
							ans4 += s[i].z;
//							cout << "1z ";
						}
					}
					else
					{
						if ((a1 + 1) <= (n / 2)) 
						{
							a1++;
							ans4 += s[i].y;
//							cout << "1y ";
						}
						else
						{
							a2++;
							ans4 += s[i].z;
//							cout << "2z ";
						}
					}
				}
			}
		}
//		for (int i = 1; i <= n; i++)
//		{
//			cout << s[i].x << " " << s[i].y << " " << s[i].z << endl;
//		}
//		cout << endl;
//    	cout << ans1 << " " << ans2 << " " << ans3 << " " << ans4 << endl;
//		ans = max(ans, ans4);
		cout << max(ans1, max(ans2, max(ans3, ans4))) << endl;
	}
	return 0;
 } 
