#include <bits/stdc++.h>
using namespace std;
void main1();
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        main1();
    }
}

struct stu
{
    int max_i, mid_i, min_i;
    int max_v, mid_v, min_v;
    int state; //0:max,1:mid,2:min
    int get_value() const
    {
        if (state == 0)
        {
            return max_v - mid_v;
        }
        if (state == 1)
        {
            return mid_v - min_v;
        }
        return min_v - max_v;
    }
    stu(int a, int b, int c)
    {
        int tmp[3] = {0, 1, 2}, tmp1[3] = {a, b, c};
        for (int j = 0; j < 3; j++)
            for (int i = 0; i < 2; i++)
            {
                if (tmp1[tmp[i]] > tmp1[tmp[i + 1]])
                {
                    swap(tmp[i], tmp[i+1]);
                }
            }
        min_i=tmp[0];
        mid_i=tmp[1];
        max_i=tmp[2];
        min_v=tmp1[min_i];
        mid_v=tmp1[mid_i];
        max_v=tmp1[max_i];
        state=0;
    }
};
bool operator<(const stu &a, const stu &b)
{
    return a.get_value() < b.get_value();
}
bool operator>(const stu &a, const stu &b)
{
    return a.get_value() > b.get_value();
}
void main1()
{
    int n;
    scanf("%d", &n);
    vector<stu>stu_pool[3];
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        stu tmp(a,b,c);
        stu_pool[tmp.max_i].push_back(tmp);
        ans+=tmp.max_v;
    }
    sort(stu_pool[0].begin(),stu_pool[0].end(),greater<stu>());
    sort(stu_pool[1].begin(),stu_pool[1].end(),greater<stu>());
    sort(stu_pool[2].begin(),stu_pool[2].end(),greater<stu>());
    while(stu_pool[0].size()>n/2||stu_pool[1].size()>n/2||stu_pool[2].size()>n/2)
    {
        for(int i=0;i<3;i++)
        {
            if(stu_pool[i].size()>n/2)
            {
                ans-=stu_pool[i].back().get_value();
                stu_pool[i].pop_back();
            }
        }
    }
    printf("%lld\n",ans);
}