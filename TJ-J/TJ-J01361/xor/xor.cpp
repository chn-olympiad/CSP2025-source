#include <bits/stdc++.h>
using namespace std;

int a[500500];
int d[500500];
int f[500500];

//wo cai shi tan xin jia qian zhui he
//start: 9:56
//finished: 10:12
//10:18 wei le
//10:32 xian zuo di si ti
//11:18 hui lai le
//11:19 shou bu liao le, xie ge dp ba?
//11:56 zha le zha le zha le
//zhi neng de san bai fen le



int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        d[i]=d[i-1]^a[i];
        //cout<<d[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(d[i]^d[j-1]==k) f[i]=max(f[i],f[j]+1);
            //printf("i:%d j:%d k:%df[i]%d\n",i,j,k,f[i]);
        }
    }
    cout<<f[n];
    /*
    int ans=0;
    int i=1;
    int j=1;
    while(i<=n)
    {
        if((d[i]^d[j-1]) == k)
        {
            printf("if,i:%d j:%d ans:%d xor:%d\n",i,j,ans,d[i]^d[j-1]);
            ans++;
            i++;
            j=i;
            printf("if2,i:%d j:%d ans:%d\n",i,j,ans);
        }
        else{
            printf("else,i:%d j:%d ans:%d\n",i,j,ans);
            i++;
            printf("else2,i:%d j:%d ans:%d\n",i,j,ans);
        }
    }
    printf("%d",ans);
    */
}
