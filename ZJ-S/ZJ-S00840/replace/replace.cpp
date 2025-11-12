/*
StarLight_Yuran_ovo
我要陪你 走下去 一直到无边天际 感谢我们无数次 交付彼此 的勇气 好的天气 坏的运气 都是值得庆祝的相遇 当我们开始真的爱自己 传说的宝藏就是你 
Clock Paradox
JROI 2023~无限
Starlight OI 2024~无限
RP++
648647291436
*/
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string s1[N],s2[N];
string t1[N],t2[N];
int n,q;
int ans;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++)
	{
		ans=0;
		cin>>t1[i]>>t2[i];
//		cout<<"648647291436\n";
		for(int j=1;j<=n;j++)
		{
//			cout<<t1[i].length()-s1[j].length()<<" 648647291436\n";
			for(int k=0;k<=int(t1[i].size())-int(s1[j].size());k++)
			{
				if(k>10)
				{
					break;
				}
				bool flag=1;
//				cout<<k<<' '<<"648647291436\n";
				string qwq1=t1[i],qwq2=t2[i];
				for(int l=0;l<s1[j].size();l++)
				{
//					cout<<"648647291436\n";
					if(t1[i][k+l]!=s1[j][l]||t2[i][k+l]!=s2[j][l])
					{
						flag=0;
						break;
					}
					else
					{
						qwq1[k+l]=s2[j][l];
					}
				}
				if(flag&&qwq1==qwq2)
				{
//					cout<<j<<"\n";
					ans++;
					break;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//某谷 1.1k 犇犇网红笑传之我是奶龙看了半天才看懂 T3 是什么意思。又是只会暴力的一集。
//倒闭啦！！！（RP 疑似全献祭给 J 了）
//马亥 歹匕 手戈 了 怎 么 RE 了 手戈 是 女乃 龙
//哦我忘了 .size() 返回的是无符号了我是奶龙我是奶龙我才是奶龙糖丸了彻底糖丸了
