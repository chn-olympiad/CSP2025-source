#include <bits/stdc++.h>
using namespace std;
int a[15];

//finished : 8:53
//test finished:9:02
//ce shi yang li 3ge dou dui
//di 4 ge wen jian tai da le
//diff fang bu xia

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string str;
    cin>>str;
   for(int i=0;i<=str.size()-1;i++)
   {
       char c=str[i];
       //printf("c:%c\n",c);
       if(c-'0'>=0 && c-'0'<=9)
       {
           int m=c-'0';
           a[m]++;
           //printf("i'm here:%d\n",m);
       }
   }
   /*for(int i=1;i<=10;i++)
   {
    printf("%d:%d ",i-1,a[i-1]);
   }
   */
   for(int i=9;i>=0;i--)
   {
       int m=a[i];
       for(int j=1;j<=m;j++)
       {
           printf("%d",i);
       }
   }
}
