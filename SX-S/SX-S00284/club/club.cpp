#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 100005;
int t;
int n;

struct node {
	int emo1, emo2, emo3;
} person[maxn];

struct node2 {
	int num1, num2, num3;
} club;

struct node3 {
	int xv, emo;
} every_person[4];
int text4;
ll ans;

void paixv(int i) {
	if (text[1] == person[i].emo1) {
		max_emo = text[1];
		max_club = 1;
		if (text[2] == person[i].emo1) {
			max_emo = text[2];
			max_club = 2;
		} else if (text[2] == person[i].emo3) {
			max_emo = text[2];
			max_club = 2;
			max_emo = text[3];
			max_club = 3;
		} else if ()
			every_person[1].xv = 1;
		every_person[1].emo = person[i].emo1;
		every_person[2].xv = 2;
		every_person[2].emo = person[i].emo2;
		every_person[3].xv = 3;
		every_person[3].emo = person[i].emo3;
	}

	int main{
		cin >> t;
		for (int ti = 1; ti <= t; ti++) {
			cin >> n;
			for (int i = 1; i <= n; i++) {
				cin >> person[i].emo1 >> person[i].emo2 >> person >> person[i].emo3;
			}
			for (int i = 1; i <= n; i++) {
				text[1] = person[i].emo1;
				text[2] = person[i].emo2;
				text[3] = person[i].emo3;
				sort(text + 1, text + 4);
				paixv(i);
				if (max_club == 1) {
					if (club.num1 < ert) {
						club.num1++;
						ans += max_emo;
					}
				}
				if (max_club == 2) {
					if (club.num2 < ert) {
						club.num2++;
						ans += max_emo;
					}
				}
				if (max_club == 3) {
					if (club.num3 < ert) {
						club.num3++;
						ans += max_emo;
					} else if () {

					}
				}

				//if (text[1] == person[i].emo1) {
				//max_emo = text[1];
				//max_club = 1;
				//if (text[2] == person[i].emo1) {
				//max_emo = text[2];
				//max_club = 2;
				//} else if (text[2] == person[i].emo3) {
				//	max_emo = text[2];
				//	max_club = 2;
				//	max_emo = text[3];
				//max_club = 3;
				//} else if ()
				//every_person[1].xv=1;
				//every_person[1].emo=person[i].emo1;
				//vevery_person[2].xv=2;
				//every_person[2].emo=person[i].emo2;
				//every_person[3].xv=3;
				//every_person[3].emo=person[i].emo3;
				cout << every_person[1].emo << " "every_person[2].emo << every_person[3].emo

				     //int max_club=0,max_emo=0;
				     //if(person[i].emo1>person[i].emo2>person[i].emo3){
				     //max_club=2;
				     //max_emo=person[i].emo1;
				     //}
				     //else

			}
		}

		return 0;
	}
