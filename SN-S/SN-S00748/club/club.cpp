#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;

long long stunum;
long long stuscore[100005][3];
long long can_put[3];

void solve()
{
	
	long long scoresum = 0;
	
	cin >> stunum;
	for (int j = 0; j < stunum; ++j)
	{
		for (int i = 0; i < 3; ++i){
			cin >> stuscore[j][i];
		}
	}
	
	can_put[0] = can_put[1] = can_put[2] = (stunum + stunum % 2) / 2;
	for (int j = 0; j < stunum; ++j)
	{
		map<int, int> mplist;
		for (int j = 0; j < 3; ++j){
			mplist[stuscore[j]] = j;
		}
		sort(mplist[j], mplist[j] + 3);
		if (can_put[mplist[stuscore[2]]] > 0){
			can_put[mplist[stuscore[2]]]--;
			scoresum += stuscore[2];
		}else if(can_put[mplist[stuscore[1]]] > 0)
		{
			can_put[mplist[stuscore[1]]];
			scoresum += stuscore[1];
		}else if(can_put[mplist[stuscore[0]]] > 0)
		{
			can_put[mplist[stuscore[0]]];
			scoresum += stuscore[0];
		}else{
			continue;
		}
	}
	cout << scoresum << endl;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	long long T;
	cin >> T;
	while (T--)
	{
		solve();
	}
	return 0;
}
