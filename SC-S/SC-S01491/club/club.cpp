#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
struct Person{
	int a1, a2, a3;
} p[N];
bool cmp1(int x, int y){
	return max(p[x].a2, p[x].a3) - p[x].a1 > max(p[y].a2, p[y].a3) - p[y].a1;
}
bool cmp2(int x, int y){
	return max(p[x].a1, p[x].a3) - p[x].a2 > max(p[y].a1, p[y].a3) - p[y].a2;
}
bool cmp3(int x, int y){
	return max(p[x].a1, p[x].a2) - p[x].a3 > max(p[y].a1, p[y].a2) - p[y].a3;
}
int sum, n, t;
vector <int> vec1, vec2, vec3;
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		sum = 0;
		vec1.clear();
		vec2.clear();
		vec3.clear();
		for(int i = 1; i <= n; i++){
			scanf("%d%d%d", &p[i].a1, &p[i].a2, &p[i].a3);
			if(max(p[i].a1, max(p[i].a2, p[i].a3)) == p[i].a1)
				vec1.push_back(i);
			else if(max(p[i].a1, max(p[i].a2, p[i].a3)) == p[i].a2)
				vec2.push_back(i);
			else
				vec3.push_back(i);
			sum += max(p[i].a1, max(p[i].a2, p[i].a3));
		}
		if((int)vec1.size() > n / 2){
			sort(vec1.begin(), vec1.end(), cmp1);
			for(int i = 0; (int)vec1.size() - i > n / 2; i++){
				sum -= p[vec1[i]].a1;
				sum += max(p[vec1[i]].a2, p[vec1[i]].a3);
			} 
		}
		if((int)vec2.size() > n / 2){
			sort(vec2.begin(), vec2.end(), cmp2);
			for(int i = 0; (int)vec2.size() - i > n / 2; i++){
				sum -= p[vec2[i]].a2;
				sum += max(p[vec2[i]].a1, p[vec2[i]].a3);
			} 
		}
		if((int)vec3.size() > n / 2){
			sort(vec3.begin(), vec3.end(), cmp3);
			for(int i = 0; (int)vec3.size() - i > n / 2; i++){
				sum -= p[vec3[i]].a3;
				sum += max(p[vec3[i]].a1, p[vec3[i]].a2);
			} 
		}
		printf("%d\n", sum);
	}
	return 0; 
}