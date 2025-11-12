#include<bits/stdc++.h>
using namespace std;
const int N=1e2+8;
int n,m,ansc,ansr;
int a[N];
bool cmp(int x,int y) { return x>y; }
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    int x=a[1],pos=1;
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
        if(a[i]==x)
        {
            pos=i;
            break;
        }
    ansc=(pos+n-1)/n;
    ansr=pos%n;
    if(ansr==0) ansr=n;
    int k=2*n;
    if(pos%k>n||pos%k==0) ansr=n-ansr+1;
    cout<<ansc<<" "<<ansr<<"\n";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
