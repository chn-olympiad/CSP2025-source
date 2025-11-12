#include <bits/stdc++.h>
using namespace std;
inline void partitional_copy(vector<pair<int, pair<int, int>>> &a, vector<pair<int, pair<int, int>>> *b, int __first){
	for (pair<int, pair<int, int>> i : a){
		if (i.second.first==__first) b->push_back(i);
	}
}
bool cmp(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b){
	return a.second.second>b.second.second;
}
bool cmp2(pair<int, int> &a, pair<int, int> &b){
	return a.second>b.second;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	int o[t][3] = {};
	for(int i=0;i<t;i++){
		int n;
		scanf("%d", &n);
		int a[n][3] = {};
		vector<pair<int, pair<int, int>>> b;
		int c[3]={};
		int d[3]={};
		for(int j=0;j<n;j++){
			for(int z=0;z<3;z++){
				scanf("%d", &a[j][z]);
			}
		}
		for(int j=0;j<n;j++){
			auto __max = max_element(a[j], a[j]+3);
			b.push_back(pair<int, pair<int, int>>(j, pair<int, int>(__max-a[j], *__max)));
			c[__max-a[j]]++;
			d[__max-a[j]]+=*__max;
			
		}
		if (c[0]<=n/2&&c[1]<=n/2&&c[2]<=n/2){
			o[i][0] = d[0];
			o[i][1] = d[1];
			o[i][2] = d[2];
		}else{
			auto __max_ = max_element(c, c+3);
			int __max__ = *__max_;
			int the_max = __max_-c;
			vector<pair<int, pair<int, int>>> tmp;
			vector<pair<int, int>> cost;
			partitional_copy(b, &tmp, the_max);
			for(size_t _i=0;_i<tmp.size();_i++){
				int now_stu = tmp[_i].first;
				auto now__max = max_element(a[now_stu], a[now_stu]+3);
				int ___t[3] = {1, 1, 1};
				___t[now__max-a[now_stu]]=0;___t[min_element(a[now_stu], a[now_stu]+3)-a[now_stu]]=0;
				cost.push_back(pair<int, int>(now_stu, (*now__max)-a[now_stu][find(___t, ___t+3, 1)-___t]));
			}
			sort(cost.begin(), cost.end(), cmp2);
			//sort(tmp.begin(), tmp.end(), cmp);
			for(int m=0;m<(__max__)-n/2;m++){
				int this_nmber = cost.back().first;
				int __tmp[3] = {};
				copy(a[this_nmber], a[this_nmber]+3, __tmp);
				__tmp[the_max]=-1;
				auto now_max = max_element(__tmp, __tmp+3);
				if (c[now_max-__tmp]+1<=n/2) {
					c[now_max-__tmp]++;
					c[the_max]--;
					d[now_max-__tmp]+=__tmp[now_max-__tmp];
					d[the_max]-=a[this_nmber][the_max];
				}
				else {
					int ___t[3] = {1, 1, 1};
					___t[the_max]=0;___t[now_max-__tmp]=0;
					c[find(___t, ___t+3, 1)-___t]++;
					c[the_max]--;
					d[find(___t, ___t+3, 1)-___t]+=__tmp[find(___t, ___t+3, 1)-___t];
					d[the_max]-=a[this_nmber][the_max];
				}
				cost.pop_back();
			}
			o[i][0] = d[0];
			o[i][1] = d[1];
			o[i][2] = d[2];
			
		}
	}
	for(int i=0;i<t;i++){
		cout<<o[i][0]+o[i][1]+o[i][2]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}