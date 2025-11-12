#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s;
	cin >> s;
	int cnt[1000010],a = s.size;
	for(int i = 1;i <= a;i++)
	{
		if(i == "1" || i == "2" ||i == "3" ||i == "4" ||
		i == "5" ||i == "6" ||i == "7" ||i == "8" ||i == "9" )	
			cnt[i] = s[i];
			cnt[i] = max(cnt[i],cnt[i-1]); 
	}
	for(int i = 1;i <= a;i++)
	{
		cout << cnt[i];
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
 } 
