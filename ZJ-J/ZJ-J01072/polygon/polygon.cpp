#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5010];
int f[5005][3];
long long ans;
//如何省空间——一个预处理，一个边处理边计算 
//卡常——模运算太慢，直接展开 
//思路糖丸了，好在才 30min，先排序！
//这样一个背包就够了，滚动数组优化也不卡常了 
//大样例不过，完了！ 
//原来要选 3 以上，糖丸了
//又卡常 
//大样例还是错，炸扎炸 
//5000*5000* 常数，一点不卡常！
//warning:样例1~3弱爆了 
//9:15 过阳历！ 
//9:25 随机生成大样例 0.7s 
int main()
{freopen("polygon.in","r",stdin);
 freopen("polygon.out","w",stdout);
 cin>>n;
 for(int i=1;i<=n;i++)
 cin>>a[i];
 sort(a+1,a+1+n);
 f[0][0]=1;
 //枚举断点，甚至不用前缀和优化 
  for(int i=1;i<=n;i++)
 {//当前断点 
  for(int j=5001;j>=0;j--)
  {if(j>a[i]) ans+=f[j][2];
   else break;
   if(ans>=mod) ans-=mod;
  }
  //j=10001 单独处理
  for(int j=5001;j>=5001-a[i];j--)
  {f[5001][2]+=f[j][2];
   if(f[5001][2]>=mod) f[5001][2]-=mod;
   f[5001][2]+=f[j][1];
   if(f[5001][2]>=mod) f[5001][2]-=mod;
   f[5001][1]+=f[j][0];
   if(f[5001][1]>=mod) f[5001][1]-=mod;
  }
  for(int j=5000;j>=a[i];j--)
  {f[j][2]+=f[j-a[i]][2];
   if(f[j][2]>=mod) f[j][2]-=mod;
   f[j][2]+=f[j-a[i]][1];
   if(f[j][2]>=mod) f[j][2]-=mod;
   f[j][1]+=f[j-a[i]][0];
   if(f[j][1]>=mod) f[j][1]-=mod;
  }
 }
 cout<<ans;
 return 0;
}
