#include <iostream> 
using namespace std;

int box[20];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int s;
	cin >> s;
	while(s > 0)
	{
		int c = s % 10;
		box[c]++;
		s /= 10; 
	}
	for(int i = 9; i >= 0; i--)
	{
		for(int j = 1; j <= box[i]; j++)
		{
			cout << i;
		}
	}
	return 0;
}
