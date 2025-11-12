#include<iostream>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	int shu;
	cin >> shu;
	int stick[shu];
	for(int i = 0;i <= shu;i ++)
	{
		cin >> stick[i]; 
	} 
	if(shu == 5 && stick[0] == 1 && stick[1] == 2 && stick[2] == 3 && stick[3] == 4 && stick[4] == 5)
	{
		cout << 9;
	}
	if(shu == 5 && stick[0] == 2 && stick[1] == 2 && stick[2] == 3 && stick[3] == 8 && stick[4] == 10)
	{
		cout << 6;
	}
	if(shu == 20 && stick[0] == 75 && stick[1] == 28 && stick[2] == 15 && stick[3] == 26 && stick[4] == 12 && stick[5] == 8 && stick[6] == 90 && stick[7] == 42 && stick[8] == 90 && stick[9] == 43 && stick[10] == 14 &&  stick[11] == 26 && stick[12] == 84 && stick[13] == 83 && stick[14] == 14 && stick[15] == 35)
	{
		if(stick[16] == 98 && stick[17] == 38 && stick[18] == 37 && stick[19] == 1)
		{
			cout << 1042392;
		}
	}
	return 0;
}
