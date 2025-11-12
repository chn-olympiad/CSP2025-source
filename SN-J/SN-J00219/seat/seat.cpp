//SN-J00219唐一齐 西安市交大附中浐灞右岸学校
#include <bits/stdc++.h>
using namespace std;
int n,m,a[200][200];
struct s{
	int grade;
	bool R;
}scores[200];
bool cmp(s xx,s yy);
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++)cin>>scores[i].grade;
	scores[1].R = true;
	sort(scores+1,scores+m*n+1,cmp);
	int cnt = 1;
	bool flag = true;
	for(int i = 1;i<=m;i++)
		if(flag){
			flag = false;
			for(int j = 1;j<=n;j++){
				a[i][j] = scores[cnt].grade;
				if(scores[cnt].R == true){
					cout<<i<<" "<<j;
					return 0;
				}
				cnt++;
			}
		}
		else{
			flag = true;
			for(int j = n;j>=1;j--){
				a[i][j] = scores[cnt].grade;
				if(scores[cnt].R == true){
					cout<<i<<" "<<j;
					return 0;
				}
				cnt++;
			}
		}
	return 0;
}
bool cmp(s xx,s yy){
	return xx.grade>yy.grade;
}
