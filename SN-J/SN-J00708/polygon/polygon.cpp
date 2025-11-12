//王乙丞 西安滨河学校 SN-J00708 
#include <bits/stdc++.h>
using namespace std;
int Wang1,Wanga[5010],Wang2,Wang3;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	cin >> Wang1;
	for (int i = 1;i <= Wang1;i++)
	{
		cin >> Wanga[i];
	}
	Wang2=max(Wanga[1],max(Wanga[2],Wanga[3]));
	if(Wang2*2<Wanga[1]+Wanga[2]+Wanga[3])cout<<1;
	else cout<<0;
	return 0;
}
