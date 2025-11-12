#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int T,n;
struct Node{
	int id,pos1,pos2,c;
}b[N];
bool cmp(Node a,Node b){
	return a.c > b.c;
};
ll ans;
int a[N][4];
int main(){
	freopen("club.in","r",stdin); 
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin >> T;
	while(T --){
		ans = 0;
		cin >> n;
		int num[4];
		num[1] = num[2] = num[3] = 0;
		for(int i = 1;i <= n;i ++){
			a[i][0] = -1;
			for(int j = 1;j <= 3;j ++){
				cin >> a[i][j];
			}
			int Pos1 = 0,Pos2 = 0;
			for(int j = 1;j <= 3;j ++){
				if(a[i][j] > a[i][Pos1]){
					Pos1 = j;
				}
			}
			for(int j = 1;j <= 3;j ++){
				if(a[i][j] > a[i][Pos2] && j != Pos1){
					Pos2 = j;
				}
			}
			b[i].id = i;
			b[i].pos1 = Pos1,b[i].pos2 = Pos2;
			b[i].c = a[i][Pos1] - a[i][Pos2];
		}
		sort(b + 1,b + 1 + n,cmp);
		for(int i = 1;i <= n;i ++){
			int Id = b[i].id,Pos1 = b[i].pos1,Pos2 = b[i].pos2;
			if(num[Pos1] >= n / 2){
				ans += a[Id][Pos2];
				num[Pos2] ++;
			}
			else{
				ans += a[Id][Pos1];
				num[Pos1] ++; 
			}
		}
		cout << ans << "\n";
	}
	
	
	
	
	
	
	
	
	return 0;
} 
