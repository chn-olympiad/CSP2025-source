#include<bits/stdc++.h>
using namespace std;

long long int t,cnt = 0,ans[99999999],all_n;

struct mm{
	int a;
	int b;
	int c;
}member[100001];

/*bool cmp(mm x,mm y){
	if(x.a >= y.a){
		if(x.b >= y.b){
			if(x.c >= y.c){
				return 1;
			}
			return 0;
		}
		if(x.b <= y.b){
			if(x.c >= y.c){
				return 1;
			}
			return 0;
		}
	}
	return 0;
}*/

void dfs(long long int n,long long int sum,long long int c1,long long int c2,long long int c3){
	if(n > all_n || c1 > all_n / 2 || c2 > all_n / 2 || c3 > all_n / 2){
		return;
	}
	if(n == all_n){
		cnt ++;
		//cout << c1 << " " << c2 << " " << c3 <<" " << sum << endl;  
		ans[cnt] = sum;
		//cout << c1 << " " << c2 << " " << c3 <<" " << ans[cnt] << endl; 
		//cout << n << endl;
		return;
	}
	
	//cout << cnt << endl;
	dfs(n + 1,sum + member[n + 1].a,c1 + 1,c2,c3);
	dfs(n + 1,sum + member[n + 1].b,c1,c2 + 1,c3);
	dfs(n + 1,sum + member[n + 1].c,c1,c2,c3 + 1);
}

int main(){
	freopen("club.in","r",stdin);																																							
	freopen("club.out","w",stdout);
	cin >> t;
	for(long long int i = 1 ; i <= t ; i ++){
		cin >> all_n ;
		for(long long int j = 1 ; j <=  all_n ; j ++){
			cin >> member[j].a >> member[j].b >> member[j].c;
		}
		dfs(0,0,0,0,0);
		dfs(0,0,0,0,0);
		dfs(0,0,0,0,0);
		sort(ans + 1,ans + 1 + cnt);
		cout << ans[cnt]<<endl;
		cnt=0;
		//sort(member + 1 , member + 1 + n , cmp);
	}
	return 0; 
} 
//TMD怎么算啊
//哇还有搜搜爆 
//dfs具有超级牛力 
