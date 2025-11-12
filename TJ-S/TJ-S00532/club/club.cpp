#include <bits/stdc++.h>
using namespace std;
long long t,n,aa,bb,cc,maxx,maxn;
struct node
{
    long long a,b,c,d;
}str[100005];
bool cmp(node x,node y)
{
    return x.d > y.d;
}
bool cmp1(node x,node y)
{
    return x.a > y.a;
}
bool cmp2(node x,node y)
{
    return x.b > y.b;
}
bool cmp3(node x,node y)
{
    return x.c > y.c;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int i = 1;i <= t;i++)
    {
        cin >> n;
        maxx = 0;
        for(int j = 1;j <= n;j++)
        {
            cin >> str[j].a >> str[j].b >> str[j].c;
            str[j].d = str[j].a + str[j].b + str[j].c;
        }
            sort(str + 1,str + n + 1,cmp);
            /*for(int j = 1;j <= n;j++)
            {
                cout << str[j].a << " " << str[j].b << " " << str[j].c << " " << str[j].d << endl;
            }*/
            maxn = 0,aa = 0,bb = 0,cc = 0;
            for(int k = 1;k <= n;k++)
            {
                if(str[k].a == 0)
                {
                    if(str[k].b == 0)
                    {
                        if(cc < n / 2)
                        {
                            maxn += str[k].c;
                            cc++;
                        }
                    }
                    else
                    {
                        if(str[k].c == 0)
                        {
                            if(bb < n / 2)
                            {
                                maxn += str[k].b;
                                bb++;
                            }
                        }
                        else
                        {
                            if(str[k].b > str[k].c && bb < n / 2)
                            {
                                maxn += str[k].b;
                                bb++;
                            }
                            if(str[k].b < str[k].c && cc < n / 2)
                            {
                                maxn += str[k].c;
                                cc++;
                            }
                        }
                    }
                }
                else
                {
                    if(str[k].b == 0)
                    {
                        if(str[k].c == 0)
                        {
                            if(aa < n / 2)
                            {
                                maxn += str[k].a;
                                aa++;
                            }
                        }
                        else
                        {
                            if(str[k].a > str[k].c && aa < n / 2)
                            {
                                maxn += str[k].a;
                                aa++;
                            }
                            if(str[k].a < str[k].c && cc < n / 2)
                            {
                                maxn += str[k].c;
                                cc++;
                            }
                        }
                    }
                    else
                    {
                        if(str[k].c == 0)
                        {
                            if(str[k].b > str[k].a && bb < n / 2)
                            {
                                maxn += str[k].b;
                                bb++;
                            }
                            if(str[k].b < str[k].a && aa < n / 2)
                            {
                                maxn += str[k].a;
                                aa++;
                            }
                        }
                    }
                }
            }
            for(int k = 1;k <= n;k++)
            {
                if(str[k].a != 0 && str[k].b != 0 && str[k].c != 0)
                {
                    if(aa == n / 2)
                    {
                        if(str[k].b > str[k].c)
                        {
                            bb++;
                            maxn += str[k].b;
                        }
                        else
                        {
                            cc++;
                            maxn += str[k].c;
                        }
                        continue;
                    }
                    if(bb == n / 2)
                    {
                        if(str[k].a > str[k].c)
                        {
                            aa++;
                            maxn += str[k].a;
                        }
                        else
                        {
                            cc++;
                            maxn += str[k].c;
                        }
                        continue;
                    }
                    if(cc == n / 2)
                    {
                        if(str[k].b > str[k].a)
                        {
                            bb++;
                            maxn += str[k].b;
                        }
                        else
                        {
                            aa++;
                            maxn += str[k].a;
                        }
                        continue;
                    }
                    if(str[k].a > str[k].b)
                    {
                        if(str[k].a > str[k].c)
                        {
                            aa++;
                            maxn += str[k].a;
                        }
                        else
                        {
                            cc++;
                            maxn += str[k].c;
                        }
                    }
                    else
                    {
                        if(str[k].b > str[k].c)
                        {
                            bb++;
                            maxn += str[k].b;
                        }
                        else
                        {
                            cc++;
                            maxn += str[k].c;
                        }
                    }
                }
            }
            maxx = max(maxx,maxn);
            sort(str + 1,str + n + 1,cmp1);
            maxn = 0,aa = 0,bb = 0,cc = 0;
            for(int k = 1;k <= n;k++)
            {
                if(str[k].a == 0)
                {
                    if(str[k].b == 0)
                    {
                        if(cc < n / 2)
                        {
                            maxn += str[k].c;
                            cc++;
                        }
                    }
                    else
                    {
                        if(str[k].c == 0)
                        {
                            if(bb < n / 2)
                            {
                                maxn += str[k].b;
                                bb++;
                            }
                        }
                        else
                        {
                            if(str[k].b > str[k].c && bb < n / 2)
                            {
                                maxn += str[k].b;
                                bb++;
                            }
                            if(str[k].b < str[k].c && cc < n / 2)
                            {
                                maxn += str[k].c;
                                cc++;
                            }
                        }
                    }
                }
                else
                {
                    if(str[k].b == 0)
                    {
                        if(str[k].c == 0)
                        {
                            if(aa < n / 2)
                            {
                                maxn += str[k].a;
                                aa++;
                            }
                        }
                        else
                        {
                            if(str[k].a > str[k].c && aa < n / 2)
                            {
                                maxn += str[k].a;
                                aa++;
                            }
                            if(str[k].a < str[k].c && cc < n / 2)
                            {
                                maxn += str[k].c;
                                cc++;
                            }
                        }
                    }
                    else
                    {
                        if(str[k].c == 0)
                        {
                            if(str[k].b > str[k].a && bb < n / 2)
                            {
                                maxn += str[k].b;
                                bb++;
                            }
                            if(str[k].b < str[k].a && aa < n / 2)
                            {
                                maxn += str[k].a;
                                aa++;
                            }
                        }
                    }
                }
            }
            for(int k = 1;k <= n;k++)
            {
                if(str[k].a != 0 && str[k].b != 0 && str[k].c != 0)
                {
                    if(aa == n / 2)
                    {
                        if(str[k].b > str[k].c)
                        {
                            bb++;
                            maxn += str[k].b;
                        }
                        else
                        {
                            cc++;
                            maxn += str[k].c;
                        }
                        continue;
                    }
                    if(bb == n / 2)
                    {
                        if(str[k].a > str[k].c)
                        {
                            aa++;
                            maxn += str[k].a;
                        }
                        else
                        {
                            cc++;
                            maxn += str[k].c;
                        }
                        continue;
                    }
                    if(cc == n / 2)
                    {
                        if(str[k].b > str[k].a)
                        {
                            bb++;
                            maxn += str[k].b;
                        }
                        else
                        {
                            aa++;
                            maxn += str[k].a;
                        }
                        continue;
                    }
                    if(str[k].a > str[k].b)
                    {
                        if(str[k].a > str[k].c)
                        {
                            aa++;
                            maxn += str[k].a;
                        }
                        else
                        {
                            cc++;
                            maxn += str[k].c;
                        }
                    }
                    else
                    {
                        if(str[k].b > str[k].c)
                        {
                            bb++;
                            maxn += str[k].b;
                        }
                        else
                        {
                            cc++;
                            maxn += str[k].c;
                        }
                    }
                }
            }
            maxx = max(maxx,maxn);
            sort(str + 1,str + n + 1,cmp2);
            maxn = 0,aa = 0,bb = 0,cc = 0;
            for(int k = 1;k <= n;k++)
            {
                if(str[k].a == 0)
                {
                    if(str[k].b == 0)
                    {
                        if(cc < n / 2)
                        {
                            maxn += str[k].c;
                            cc++;
                        }
                    }
                    else
                    {
                        if(str[k].c == 0)
                        {
                            if(bb < n / 2)
                            {
                                maxn += str[k].b;
                                bb++;
                            }
                        }
                        else
                        {
                            if(str[k].b > str[k].c && bb < n / 2)
                            {
                                maxn += str[k].b;
                                bb++;
                            }
                            if(str[k].b < str[k].c && cc < n / 2)
                            {
                                maxn += str[k].c;
                                cc++;
                            }
                        }
                    }
                }
                else
                {
                    if(str[k].b == 0)
                    {
                        if(str[k].c == 0)
                        {
                            if(aa < n / 2)
                            {
                                maxn += str[k].a;
                                aa++;
                            }
                        }
                        else
                        {
                            if(str[k].a > str[k].c && aa < n / 2)
                            {
                                maxn += str[k].a;
                                aa++;
                            }
                            if(str[k].a < str[k].c && cc < n / 2)
                            {
                                maxn += str[k].c;
                                cc++;
                            }
                        }
                    }
                    else
                    {
                        if(str[k].c == 0)
                        {
                            if(str[k].b > str[k].a && bb < n / 2)
                            {
                                maxn += str[k].b;
                                bb++;
                            }
                            if(str[k].b < str[k].a && aa < n / 2)
                            {
                                maxn += str[k].a;
                                aa++;
                            }
                        }
                    }
                }
            }
            for(int k = 1;k <= n;k++)
            {
                if(str[k].a != 0 && str[k].b != 0 && str[k].c != 0)
                {
                    if(aa == n / 2)
                    {
                        if(str[k].b > str[k].c)
                        {
                            bb++;
                            maxn += str[k].b;
                        }
                        else
                        {
                            cc++;
                            maxn += str[k].c;
                        }
                        continue;
                    }
                    if(bb == n / 2)
                    {
                        if(str[k].a > str[k].c)
                        {
                            aa++;
                            maxn += str[k].a;
                        }
                        else
                        {
                            cc++;
                            maxn += str[k].c;
                        }
                        continue;
                    }
                    if(cc == n / 2)
                    {
                        if(str[k].b > str[k].a)
                        {
                            bb++;
                            maxn += str[k].b;
                        }
                        else
                        {
                            aa++;
                            maxn += str[k].a;
                        }
                        continue;
                    }
                    if(str[k].a > str[k].b)
                    {
                        if(str[k].a > str[k].c)
                        {
                            aa++;
                            maxn += str[k].a;
                        }
                        else
                        {
                            cc++;
                            maxn += str[k].c;
                        }
                    }
                    else
                    {
                        if(str[k].b > str[k].c)
                        {
                            bb++;
                            maxn += str[k].b;
                        }
                        else
                        {
                            cc++;
                            maxn += str[k].c;
                        }
                    }
                }
            }
            maxx = max(maxx,maxn);
            sort(str + 1,str + n + 1,cmp1);
            maxn = 0,aa = 0,bb = 0,cc = 0;
            for(int k = 1;k <= n;k++)
            {
                if(str[k].a == 0)
                {
                    if(str[k].b == 0)
                    {
                        if(cc < n / 2)
                        {
                            maxn += str[k].c;
                            cc++;
                        }
                    }
                    else
                    {
                        if(str[k].c == 0)
                        {
                            if(bb < n / 2)
                            {
                                maxn += str[k].b;
                                bb++;
                            }
                        }
                        else
                        {
                            if(str[k].b > str[k].c && bb < n / 2)
                            {
                                maxn += str[k].b;
                                bb++;
                            }
                            if(str[k].b < str[k].c && cc < n / 2)
                            {
                                maxn += str[k].c;
                                cc++;
                            }
                        }
                    }
                }
                else
                {
                    if(str[k].b == 0)
                    {
                        if(str[k].c == 0)
                        {
                            if(aa < n / 2)
                            {
                                maxn += str[k].a;
                                aa++;
                            }
                        }
                        else
                        {
                            if(str[k].a > str[k].c && aa < n / 2)
                            {
                                maxn += str[k].a;
                                aa++;
                            }
                            if(str[k].a < str[k].c && cc < n / 2)
                            {
                                maxn += str[k].c;
                                cc++;
                            }
                        }
                    }
                    else
                    {
                        if(str[k].c == 0)
                        {
                            if(str[k].b > str[k].a && bb < n / 2)
                            {
                                maxn += str[k].b;
                                bb++;
                            }
                            if(str[k].b < str[k].a && aa < n / 2)
                            {
                                maxn += str[k].a;
                                aa++;
                            }
                        }
                    }
                }
            }
            for(int k = 1;k <= n;k++)
            {
                if(str[k].a != 0 && str[k].b != 0 && str[k].c != 0)
                {
                    if(aa == n / 2)
                    {
                        if(str[k].b > str[k].c)
                        {
                            bb++;
                            maxn += str[k].b;
                        }
                        else
                        {
                            cc++;
                            maxn += str[k].c;
                        }
                        continue;
                    }
                    if(bb == n / 2)
                    {
                        if(str[k].a > str[k].c)
                        {
                            aa++;
                            maxn += str[k].a;
                        }
                        else
                        {
                            cc++;
                            maxn += str[k].c;
                        }
                        continue;
                    }
                    if(cc == n / 2)
                    {
                        if(str[k].b > str[k].a)
                        {
                            bb++;
                            maxn += str[k].b;
                        }
                        else
                        {
                            aa++;
                            maxn += str[k].a;
                        }
                        continue;
                    }
                    if(str[k].a > str[k].b)
                    {
                        if(str[k].a > str[k].c)
                        {
                            aa++;
                            maxn += str[k].a;
                        }
                        else
                        {
                            cc++;
                            maxn += str[k].c;
                        }
                    }
                    else
                    {
                        if(str[k].b > str[k].c)
                        {
                            bb++;
                            maxn += str[k].b;
                        }
                        else
                        {
                            cc++;
                            maxn += str[k].c;
                        }
                    }
                }
            }
            maxx = max(maxx,maxn);
            cout << maxx << endl;
    }
	fclose(stdin);
	fclose(stdout);
	return 0;
}
