#include <bits/stdc++.h>
#define node pair<pair<int, int>, bool>
using namespace std;
const int N=1e5+7;

//struct node{
//	int rmc;
//	int rmc2;
//	bool to;		true:2, false:3
//};

int t, n;
long long ans=0;
int max2, max3;
priority_queue<node> my;
priority_queue<node> chack;

int main(){
	freopen("club.in", "r", stdin);		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	freopen("club.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> t;
	while(t--){
		cin >> n;								//n%2==0
		max2 = max3 = n/2;
		for(int i=1; i<=n; i++){
			int c1, c2, t1, t2, t3;
			bool tmpf=false;
			cin >> t1 >> t2 >> t3;
			c1 = max(t2-t1, t3-t1);
			c2 = min(t2-t1, t3-t1);
			if(t2 > t3)	tmpf = true;
			//my.push({c1, 0-c2, tmpf});
			node tmptmp;
			tmptmp.first.first = c1;
			tmptmp.first.second = -c2;
			tmptmp.second = tmpf;
			my.push(tmptmp);
			ans += t1;
		}
		node tmp;
		for(int i=1; i<=n/2; i++){
			tmp = my.top();
			my.pop();
			if(tmp.second){
				max2--;
			}else{
				max3--;
			}
			ans += tmp.first.first;
		}
		while(max2 != 0 && max3 != 0 && my.top().first.first > 0 && !my.empty()){
			tmp = my.top();
			my.pop();
			ans += tmp.first.first;
		}
		if(my.empty() || my.top().first.first <= 0){
			cout << ans << "\n";
			ans = 0;
			while(!my.empty())	my.pop();
			while(!chack.empty())	chack.pop();
			continue;
		}
		while(!my.empty()){
			tmp = my.top();
			my.pop();
			if(max2 == 0 && tmp.second || max3 == 0 && !tmp.second){
				node tmptmp;
				tmptmp.first.first = -tmp.first.second;
				tmptmp.first.second = -tmp.first.first;
				tmptmp.second = !tmp.second;
				chack.push(tmptmp);
			}else{
				chack.push(tmp);
			}
		}
		while((max2 != 0 || max3 != 0) && !chack.empty() && chack.top().first.first > 0){
			tmp = chack.top();
			chack.pop();
			ans += tmp.first.first;
			if(tmp.second){
				max2--;
			}else{
				max3--;
			}
		}
		while(!my.empty())	my.pop();
		while(!chack.empty())	chack.pop();
		cout << ans << "\n";
		ans = 0;
	}
	
	return 0;
}
