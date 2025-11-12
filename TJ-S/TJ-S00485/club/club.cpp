#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct Stu{
	int id;
	int a, b, c;
	char p;
};

bool cmpa(Stu A, Stu B){
	return A.a > B.a;
}

bool cmpb(Stu A, Stu B){
	return A.b > B.b;
}

bool cmpid(Stu A, Stu B){
	return A.id < B.b;
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		int flag = 0;
		Stu s[10010];
		scanf("%d", &n);
		for(int i = 1; i <= n; i++){
			s[i].id = i;
			scanf("%d%d%d", &s[i].a, &s[i].b, &s[i].c);
			if(s[i].b != 0 && !s[i].c) flag = 1;
			else if(s[i].b != 0 && s[i].c != 0) flag = 2;
		}
		if(!flag){
			int ans = 0;
			sort(s + 1, s + n + 1, cmpa);
			for(int i = 1; i <= n / 2; i++)
				ans += s[i].a;
			cout << ans << "\n";
		}else if(flag == 1){
			int ans = 0;
			Stu d[10010];
			sort(s + 1, s + n + 1, cmpa);
			for(int i = 1; i <= n / 2; i++){
				d[i].p = 'a';
				d[i].id = s[i].id;
				d[i].a = s[i].a;
				d[i].b = s[i].b;
			}
			sort(s + 1, s + n + 1, cmpb);
			for(int i = 1; i <= n / 2; i++){
				d[i + n / 2].p = 'b';
				d[i + n / 2].id = s[i].id;
				d[i + n / 2].a = s[i].a;
				d[i + n / 2].b = s[i].b;
			}
			sort(d + 1, d + n + 1, cmpid);
			bool v[10010];
			for(int i = 1; i < n; i++){
				if(d[i].id == d[i + 1].id){
					ans += max(d[i].a, d[i].b);
					i++;
					v[d[i].id] = 1;
				}else{
					if(d[i].p == 'a') ans += d[i].a;
					else ans += d[i].b;
					v[d[i].id] = 1;
				}
			}
			for(int i = 1; i <= n; i++){
				if(!v[s[i].id])
					ans += max(s[i].a, s[i].b);
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
