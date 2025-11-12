#include<bits/stdc++.h>
using namespace std;
string s;
int cnt[10];
//10:00 1.5h AKed，倒序开题成功 
//打 CSP 如做 ABC ABCE（） 
//一等线至少 380 qwq 
//为什么不能提前离场啊啊啊 
int main()
{freopen("number.in","r",stdin);
 freopen("number.out","w",stdout);
 cin>>s;
 for(int i=0;i<s.size();i++)
 {if(s[i]>='0'&&s[i]<='9')
  cnt[s[i]-'0']++;
 }
 for(int i=9;i>=0;i--)
 {while(cnt[i])
  {cnt[i]--;
   cout<<i;
  }
 }
 return 0;
}
