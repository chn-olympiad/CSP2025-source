//SN-J00589 李雨轩 陕西延安中学 
#include <iostream>
using namespace std;
int num[15];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	 string s;
	 cin >> s;
	 for (int i=0;i<s.length();i++)
	 {
	 	if (s[i]>='0' && s[i]<='9')
	 	{
	 		num[s[i]-'0']++;	
		}
	 }
	 for (int i=9;i>=0;i--)
	 {
	 	for (int j=1;j<=num[i];j++)
	 	{
	 		cout << i;	
		}
	 }
	return 0;
}
