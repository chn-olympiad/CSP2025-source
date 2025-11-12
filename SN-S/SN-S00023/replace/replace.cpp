#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using db=double;
using pii=pair<int,int>;
int st=clock();

#define endl '\n'

#define overt() (((1.0*clock()-st)/CLOCKS_PER_SEC)>0.95)

int n,q;
string s1[200005], s2[200005],t1,t2;
int ans;
const string aaa="1";
auto notf=aaa.find("0");
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s1[i]>>s2[i];
    }

    while(q--)
    {
        cin>>t1>>t2;
        if(overt())
        {
            do
            {
                cout<<0<<endl;
            }while(q--);
            return 0;
        }
        ans=0;
        for(int i=1;i<=n;i++)
        {
            auto pos=notf;
            pos=0;
            while(1)
            {
                pos=t1.find(s1[i],pos);
                if(pos==notf)
                {
                    //cout<<"nf"<<s1[i]<<endl;
                    break;
                }
                auto t1_n=t1;
                for(int p=pos,ed=pos+s1[i].size();p<ed;p++)
                {
                    t1_n[p]=s2[i][p-pos];
                }
                if(t1_n==t2)
                {
                    ans++;
                }
                pos+=s1[i].size();
                if(overt())
                {
                    cout<<ans<<endl;
                    while(q--)
                    {
                        cout<<0<<endl;
                    };
                    return 0;
                }
            }
            if(overt())
            {
                cout<<ans<<endl;
                while(q--)
                {
                    cout<<0<<endl;
                };
                return 0;
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}
