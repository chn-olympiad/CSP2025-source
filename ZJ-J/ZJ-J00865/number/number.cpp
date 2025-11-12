#include <iostream>
#include <string> 
using namespace std;
char s;
int cnt[20];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    while(cin >> s)
		if(s<='9' && s>='0') cnt[s-'0']++;
	bool flag = 0;
	for(int i = 9; i >= 0; i--)
	    if(cnt[i])
	    	for(int j = cnt[i]; j >= 1; j--) cout << i;
	return 0;
}
//#Shang4Shan3Ruo6Shui4
//number 
