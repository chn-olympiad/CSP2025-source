#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int input_n, input_m;
	cin >> input_n >> input_m;
	int num_of_seats = input_n*input_m;
	int score_of_stu[101];
	for (int i=0;i<num_of_seats;i++) cin >> score_of_stu[i];
	int score_of_r = score_of_stu[0];
	sort(score_of_stu, score_of_stu+num_of_seats);
	int out_c = 1;
	int out_r = 1;
	bool add_forever = true;
	for (int pos_of_stu=0;score_of_stu[num_of_seats-pos_of_stu-1]>score_of_r;pos_of_stu++)
	{
		if (out_r==input_n&&add_forever)
		{
			out_c++;
			add_forever = false;
		}
		else if (out_r==1&&(!add_forever))
		{
			out_c++;
			add_forever = true;
		}
		else if (add_forever) out_r++;
		else out_r--;
	}
	cout << out_c << " " << out_r << flush;
	return 0;
}