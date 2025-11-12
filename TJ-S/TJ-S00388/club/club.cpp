#include<bitsa/stdc++.h>
using namespace std;
int t;
struct node
{
    int s1;
    int s2;
    int s3;
    int maxn;
    int second;
    int third;
};
/*struct order
{
    int maxn;
    int second;
    int third;
    int choose;
};*/
node a[100005],choose1[100005],choose2[100005],choose3[100005];
order b[100005];
int cus1=0,cus2=0,cus3=0;//man yi zhi
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        int cnt1=0,cnt2=0,cnt3=0;
        cin>>n;
        if(n==2)//pian5'
        {
            int pi,an,fen;
            cin>>pi>>an>>fen;
            int max1=max(pi,max(an,fen));
            int max13=min(pi,min(an,fen));
            int max12=pi+an+fen-max1-max13;
            cin>>pi>>an>>fen;
            int max2=max(pi,max(an,fen));
            int max23=min(pi,min(an,fen));
            int max22=pi+an+fen-max2-max23;
            if(max1!=max2)
            {
                cout<<max1+max2;
                continue;
            }
            else if(max22>max12)
            {
                cout<<max22+max1;
                continue;
            }
            else
            {
                cout<<max12+max2;
                continue;
            }
        }
        if(n==4)
        {

        }

    return 0;
}
