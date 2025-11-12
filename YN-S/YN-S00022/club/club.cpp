#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 10005;
ll t, n, a_1, a_2, a_3, cnt;
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		ll each_club_max_people = n / 2;
//		cout<<"e:"<<each_club_max_people<<"\n";
		ll the_number_of_a1 = 0, the_number_of_a2 = 0, the_number_of_a3 = 0;
		for (int i = 0; i < n; i++) {
//			cout<<the_number_of_a1<<"\t"<<the_number_of_a2<<"\t"<<the_number_of_a3<<"\t"<<cnt<<endl;
			cin >> a_1 >> a_2 >> a_3;
			ll the_max_in_each_club = max(a_1, max(a_2, a_3)), the_num_in_the_fulled = max(the_number_of_a1, max(the_number_of_a2, the_number_of_a3));
			if (the_num_in_the_fulled < each_club_max_people) { //保证未满员
				if (the_max_in_each_club == a_1) {
					the_number_of_a1++;
					cnt += a_1;
				} else if (the_max_in_each_club == a_2) {
					the_number_of_a2++;
					cnt += a_2;
				} else if (the_max_in_each_club == a_3) {
					the_number_of_a3++;
					cnt += a_3;
				}
			} else {
				//flag wich club is full
				if (the_number_of_a1 == each_club_max_people) { //1 is_fulled
					if (the_number_of_a2 == each_club_max_people) { //2 also fulled
						the_number_of_a3++;//join into 3
						cnt += a_3;
					} else if (a_2 >= a_3) { //2 isn't fulled and he like 2 better than 3
						the_number_of_a2++;
						cnt += a_2;
					} else if (the_number_of_a3 != each_club_max_people) { //he like 3 better than 2 and 3 isn't fulled
						the_number_of_a3++;
						cnt += a_3;
					} else { //he like 3 better than 2 but 3 is_fulled
						the_number_of_a2++;
						cnt += a_2;
					}
				}
				//2
				if (the_number_of_a2 == each_club_max_people) { //2 is_fulled
					if (a_3 == each_club_max_people) { //3 also fulled
						the_number_of_a1++;//join into 1
						cnt += a_1;
					} else if (a_3 >= a_1) { //3 isn't fulled and he like 3 better than 1
						the_number_of_a3++;
						cnt += a_3;
					} else if (the_number_of_a1 != each_club_max_people) { //he like 1 better than 3 and 1 isn't fulled
						the_number_of_a1++;
						cnt += a_1;
					} else { //he like 1 better than 3 but 1 is_fulled
						the_number_of_a3++;
						cnt += a_3;
					}
				}

				//3
				if (the_number_of_a3 == each_club_max_people) { //3 is_fulled
					if (the_number_of_a2 == each_club_max_people) { //2 also fulled
						the_number_of_a1++;//join into 1
						cnt += a_1;
					} else if (a_2 >= a_1) { //2 isn't fulled and he like 2 better than 1
						the_number_of_a2++;
						cnt += a_2;
					} else if (the_number_of_a1 != each_club_max_people) { //he like 1 better than 2 and 1 isn't fulled
						the_number_of_a1++;
						cnt += a_1;
					} else { //he like 1 better than 2 but 1 is_fulled
						the_number_of_a2++;
						cnt += a_2;
					}
				}

			}
		}
		cout << cnt << endl;
		cnt = 0;
	}

	return 0;
}
