#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

struct Stu
{
    int one,two,three;
};

bool cmp1(Stu a,Stu b)
{
    return a.one > b.one;
}
bool cmp2(Stu a,Stu b)
{
    return a.two > b.two;
}
bool cmp3(Stu a,Stu b)
{
    return a.three > b.three;
}


int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int T,n;
    vector<Stu> mat;

    cin >> T;
    Stu in_s;
    int in_mx,ans = 0,mx1,mx2,mx3,x,y,len,hh = 0,g1,g2,g3;
    bool A = 1,B = 1;

    for(int i = 0;i < T;i++)
    {
        ans = hh = 0;
        mx1=mx2=mx3=0;
        mat.clear();
        g1 = g2 = g3 = 0;

        cin >> n;
        for(int j = 0;j < n;j++)
        {
            cin >> in_s.one >> in_s.two >> in_s.three;
            if(in_s.two != 0 || in_s.three != 0)
            {
                A = 0;
            }
            if(in_s.three != 0)
            {
                B = 0;
            }
            mx1 += in_s.one,mx2 += in_s.two,mx3 += in_s.three;
            if(in_s.one >= in_s.two && in_s.two >= in_s.three)
            {
                g1++;
            }
            else if(in_s.two >= in_s.one && in_s.two >= in_s.three)
            {
                g2++;
            }
            else{
                g3++;
            }
            hh += max(in_s.one,max(in_s.two,in_s.three));
            mat.push_back(in_s);
        }
        if(A)
        {
            sort(mat.begin(),mat.end(),cmp1);
            for(int i = 0;i < n / 2;i++)
            {
                ans += mat[i].one;
            }
            cout << ans << '\n';
            continue;
        }

        if(g1 <= n/2 && g2 <= n/2 && g3 <= n/2)
        {
            cout << hh << '\n';
            continue;
        }
        if(mx1 >= mx2 && mx2 >= mx3)
        {
            sort(mat.begin(),mat.end(),cmp1);
            x =mat.size(),y = n/2;
            len = min(x,y);
            for(int j = 0;j < len;j++)
            {
                ans += mat[j].one;
                mat[j].one = 0;
                mat[j].two = 0;
                mat[j].three = 0;
            }
            x =mat.size(),y = n/4;
            sort(mat.begin(),mat.end(),cmp2);
            for(int j = 0;j < len;j++)
            {
                ans += mat[j].two;
                mat[j].one = 0;
                mat[j].two = 0;
                mat[j].three = 0;
            }
            x =mat.size(),y = n/4;
            sort(mat.begin(),mat.end(),cmp3);
            for(int j = 0;j < len;j++)
            {
                ans += mat[j].three;
                mat[j].one = 0;
                mat[j].two = 0;
                mat[j].three = 0;
            }
        }
        else if(mx2 >= mx1 && mx1 >= mx3)
        {
            sort(mat.begin(),mat.end(),cmp2);
            x =mat.size(),y = n/2;
            len = min(x,y);
            for(int j = 0;j < len;j++)
            {
                ans += mat[j].two;
                mat[j].one = 0;
                mat[j].two = 0;
                mat[j].three = 0;
            }
            x =mat.size(),y = n/4;
            sort(mat.begin(),mat.end(),cmp1);
            for(int j = 0;j < len;j++)
            {
                ans += mat[j].one;
                mat[j].one = 0;
                mat[j].two = 0;
                mat[j].three = 0;
            }
            x =mat.size(),y = n/4;
            sort(mat.begin(),mat.end(),cmp3);
            for(int j = 0;j < len;j++)
            {
                ans += mat[j].three;
                mat[j].one = 0;
                mat[j].two = 0;
                mat[j].three = 0;
            }
        }
        else if(mx3 >= mx1 && mx1 >= mx2)
        {
            sort(mat.begin(),mat.end(),cmp3);
            x =mat.size(),y = n/2;
            len = min(x,y);
            for(int j = 0;j < len;j++)
            {
                ans += mat[j].three;
                mat[j].one = 0;
                mat[j].two = 0;
                mat[j].three = 0;
            }
            x =mat.size(),y = n/4;
            sort(mat.begin(),mat.end(),cmp1);
            for(int j = 0;j < len;j++)
            {
                ans += mat[j].one;
                mat[j].one = 0;
                mat[j].two = 0;
                mat[j].three = 0;
            }
            x =mat.size(),y = n/4;
            sort(mat.begin(),mat.end(),cmp2);
            for(int j = 0;j < len;j++)
            {
                ans += mat[j].two;
                mat[j].one = 0;
                mat[j].two = 0;
                mat[j].three = 0;
            }
        }
        else if(mx1 >= mx3 && mx3 >= mx2)
        {
            sort(mat.begin(),mat.end(),cmp1);
            x =mat.size(),y = n/2;
            len = min(x,y);
            for(int j = 0;j < len;j++)
            {
                ans += mat[j].one;
                mat[j].one = 0;
                mat[j].two = 0;
                mat[j].three = 0;
            }
            x =mat.size(),y = n/4;
            sort(mat.begin(),mat.end(),cmp3);
            for(int j = 0;j < len;j++)
            {
                ans += mat[j].three;
                mat[j].one = 0;
                mat[j].two = 0;
                mat[j].three = 0;
            }
            x =mat.size(),y = n/4;
            sort(mat.begin(),mat.end(),cmp2);
            for(int j = 0;j < len;j++)
            {
                ans += mat[j].two;
                mat[j].one = 0;
                mat[j].two = 0;
                mat[j].three = 0;
            }
        }
        else if(mx2 >= mx3 && mx3 >= mx1)
        {
            sort(mat.begin(),mat.end(),cmp2);
            x =mat.size(),y = n/2;
            len = min(x,y);
            for(int j = 0;j < len;j++)
            {
                ans += mat[j].two;
                mat[j].one = 0;
                mat[j].two = 0;
                mat[j].three = 0;
            }
            x =mat.size(),y = n/4;
            sort(mat.begin(),mat.end(),cmp3);
            for(int j = 0;j < len;j++)
            {
                ans += mat[j].three;
                mat[j].one = 0;
                mat[j].two = 0;
                mat[j].three = 0;
            }
            x =mat.size(),y = n/4;
            sort(mat.begin(),mat.end(),cmp1);
            for(int j = 0;j < len;j++)
            {
                ans += mat[j].one;
                mat[j].one = 0;
                mat[j].two = 0;
                mat[j].three = 0;
            }
        }
        else if(mx3 >= mx1 && mx1 >= mx2)
        {
            sort(mat.begin(),mat.end(),cmp3);
            x =mat.size(),y = n/2;
            len = min(x,y);
            for(int j = 0;j < len;j++)
            {
                ans += mat[j].three;
                mat[j].one = 0;
                mat[j].two = 0;
                mat[j].three = 0;
            }
            x =mat.size(),y = n/4;
            sort(mat.begin(),mat.end(),cmp1);
            for(int j = 0;j < len;j++)
            {
                ans += mat[j].one;
                mat[j].one = 0;
                mat[j].two = 0;
                mat[j].three = 0;
            }
            x =mat.size(),y = n/4;
            sort(mat.begin(),mat.end(),cmp2);
            for(int j = 0;j < len;j++)
            {
                ans += mat[j].two;
                mat[j].one = 0;
                mat[j].two = 0;
                mat[j].three = 0;
            }
        }
        else{
            cout << hh << '\n';
            continue;
        }
        cout << ans << '\n';
    }
    return 0;
}
