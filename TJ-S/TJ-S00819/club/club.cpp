#include<bits/stdc++.h>
using namespace std;
int t, n, a[100005][3], ans;
auto cmp1 = [](int a1, int a2) {return a[a1][0] > a[a2][0];};
auto cmp2 = [](int a1, int a2) {return a[a1][1] > a[a2][1];};
auto cmp3 = [](int a1, int a2) {return a[a1][2] > a[a2][2];};
priority_queue<int, vector<int>, decltype(cmp1)> va(cmp1);
priority_queue<int, vector<int>, decltype(cmp2)> vb(cmp2);
priority_queue<int, vector<int>, decltype(cmp3)> vc(cmp3);
pair<int, int> fav[3];
/*auto gt(int a1)
{
    if(a1 == 0) return &va;
    else if(a1 == 1) return &vb;
    else return &vc;
}*/
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
    cin >> t;
    while(t--)
    {
        ans = 0;
        while(!va.empty()) va.pop();
        while(!vb.empty()) vb.pop();
        while(!vc.empty()) vc.pop();
        cin >> n;
        for(int i=0; i<n; ++i) cin >> a[i][0] >> a[i][1] >> a[i][2];

        /*
        for(int i=0; i<n; ++i) va.push(i);
        for(int i=0; i<n; ++i) {cout<<va.top()<<' ';va.pop();}
        */


        for(int i=0; i<n; ++i)
        {
            //cout<<"i="<<i<<":\n";
            fav[0] = {a[i][0], 0};
            fav[1] = {a[i][1], 1};
            fav[2] = {a[i][2], 2};
            sort(fav, fav+3, [](pair<int, int> a1, pair<int, int> a2){return a1.first > a2.first;});
            //cout<<"fav[0]:"<<fav[0].first<<' '<<fav[0].second<<endl;
            if(fav[0].second == 0)
            {
                if(va.size() < n/2) {va.push(i); ans += fav[0].first;/*cout<<"1:"<<va.top()<<",len="<<va.size()<<endl;*/}
                else
                {
                    int er = (max(a[va.top()][1], a[va.top()][2]) == a[va.top()][1]) ? 1 : 2;
                    int s = ans + a[va.top()][er] - a[va.top()][0] + fav[0].first;
                    //cout<<s<<' '<<ans + fav[1].first<<endl;

                    if(s > ans + fav[1].first)
                    {
                        ans = s;
                        if(er == 1) vb.push(va.top());
                        else vc.push(va.top());
                        va.pop();
                        va.push(i);
                    }
                    else
                    {
                        ans += fav[1].first;
                        if(fav[1].second == 1) vb.push(i);
                        else vc.push(i);
                    }
                }
            }
            else if(fav[0].second == 1)
            {
                if(vb.size() < n/2) {vb.push(i); ans += fav[0].first;/*cout<<"2:"<<vb.top()<<",len="<<vb.size()<<endl;*/}
                else
                {
                    int er = (max(a[vb.top()][0], a[vb.top()][2]) == a[vb.top()][0]) ? 0 : 2;
                    int s = ans + a[vb.top()][er] - a[vb.top()][1] + fav[0].first;
                    //cout<<s<<' '<<ans + fav[1].first<<endl;

                    if(s > ans + fav[1].first)
                    {
                        ans = s;
                        if(er == 0) va.push(vb.top());
                        else vc.push(vb.top());
                        vb.pop();
                        vb.push(i);
                    }
                    else
                    {
                        ans += fav[1].first;
                        if(fav[1].second == 0) va.push(i);
                        else vc.push(i);
                    }
                }
            }
            else
            {
                if(vc.size() < n/2) {vc.push(i); ans += fav[0].first;/*cout<<"c:"<<vc.top()<<",len="<<vc.size()<<endl;*/}
                else
                {
                    int er = (max(a[vc.top()][0], a[vc.top()][1]) == a[vc.top()][0]) ? 0 : 1;
                    int s = ans + a[vc.top()][er] - a[vc.top()][2] + fav[0].first;
                    //cout<<s<<' '<<ans + fav[1].first<<endl;

                    if(s > ans + fav[1].first)
                    {
                        ans = s;
                        if(er == 1) vb.push(vc.top());
                        else va.push(vc.top());
                        vc.pop();
                        vc.push(i);
                    }
                    else
                    {
                        ans += fav[1].first;
                        if(fav[1].second == 1) vb.push(i);
                        else va.push(i);
                    }
                }
            }
            //cout <<"ans:"<< ans << endl;
        }
        cout << ans << endl;


        //cout << endl;



    }
    return 0;
}
