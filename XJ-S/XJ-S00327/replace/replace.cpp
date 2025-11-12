#include<bits/stdc++.h>
using namespace std;
template <typename type>
inline void read(type &x){
	x = 0;
	static bool flag;
	flag = 0;
	char ch = getchar();
	while (!isdigit(ch)){
		flag = ch == '-';
		ch = getchar();
	} while (isdigit(ch)){
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	} flag ? x = -x : 0;
} template <typename type>
inline void read_char(type &x, type &y, int l){
	int cnt = 1, cnt_legend = 1;
	bool flag = 1;
	char char_var;
	char_var = getchar();
	x[0] = '0'; y[0] = '0';
	for (int i = 0; i < 2 * l; i++){
		if (flag){
			cnt = cnt_legend;
			while (isalpha(char_var)) {
				x[cnt++] = char_var;
				char_var = getchar();
			} x[cnt++] = '0';
			flag = 0;
		} else {
			cnt = cnt_legend;
			while (isalpha(char_var)) {
				y[cnt++] = char_var;
				char_var = getchar();
			} y[cnt++] = '0';
			flag = 1;
			cnt_legend = cnt;
		} if (i != l * 2 - 1)char_var = getchar();
	}
} template <typename type>
void compare_chars(type &x, type &y, type &z){ // 0&0->-1 a&a->0 a&b->1 end->2
	int i = 0;
	while (x[i] != ' ' && y[i] != ' '){
		if (x[i] == y[i]){
			if (x[i] == 0) z[i] = -1;
			else z[i] = 0;
		} else z[i] = 1;
	} z[i] = 2;
} template <typename type>
void presolve(type &x, type &y){
	int i = 0, cnt = 0, cnt_unsame = 0;
	bool flag = 1;
	while (x[i] != 2){
		if (x[i] = -1){
			if (flag){
				flag = 0;
				y[cnt].begin = i;
			} else {
				flag = 1;
				y[cnt].end = i;
				y[cnt].length_sum = y[cnt].end - y[cnt].begin - 1;
				y[cnt++].length_unsame = cnt_unsame;
				cnt_unsame = 0;
				y[cnt].begin = 1;
			}
		} else if (x == 1){
			cnt_unsame++;
		}
	}
} struct node{
	int begin, end, length_sum, length_unsame, front_a_x, back_a_x, front_a_y, back_a_y;
	template <typename type>
	void special_judge_B(type &x, type &y){
		int cnt[2] = {0, 0}, flag = 0;
		for (int i = begin + 1; i < end; i++){
			if (x[i] == 'a'){
				cnt[flag]++;
			} else if (x[i] == 'b'){
				flag = 1;
			}
		} front_a_x = cnt[0];
		back_a_x = cnt[1];
		cnt = {0, 0}, flag = 0;
		for (int i = begin + 1; i < end; i++){
			if (y[i] == 'a'){
				cnt[flag]++;
			} else if (y[i] == 'b'){
				flag = 1;
			}
		} front_a_y = cnt[0];
		back_a_y = cnt[1];
	}
}; const int MAXN1 = 1e7 + 5;
const int MAXN2 = 2e5 + 5;
char s1[MAXN1], s2[MAXN1], t1[MAXN1], t2[MAXN1];
int cs[MAXN1], cq[MAXN1];
int n, q, special_judge_B_length, cnt;
node nl[MAXN2], ql[MAXN2];
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	read(n);
	read(q);
	read_char(s1, s2, n);
	read_char(t1, t2, q);
	compare_chars(s1, s2, cs);
	compare_chars(q1, q2, cq);
	presolve(cs, nl);
	presolve(qs, ql);
	for (int i = 0; i < q; i++){
		cnt = 0;
		if (ql[i].length_unsame == 2){
			nl.special_judge_B(s1, s2);
			ql.special_judge_B(t1, t2);
			special_judge_B_length = ql[i].front_a_x - ql[i].front_a_y;
			for (int j = 0; j < n; j++){
				if (nl[j].front_a_x - nl[j].front_a_y == special_judge_B_length && nl[j].front_a_y <= ql[i].front_a_y && nl[j].back_a_x <= ql[i].back_a_x) cnt++;
			}
		} printf("%d\n", cnt);
	} return 0;
}
