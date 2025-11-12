#include<bits/stdc++.h>
using namespace std;

struct p{
	int place,score;
};
p a[100];
int n,m;

bool cmp(p a,p b){
	return a.score>b.score;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i<n*m;i++){
		cin >> a[i].score;
		a[i].place = i+1;
	}
	sort(a,a+n*m,cmp);
	int ans = 0;
	for(int i = 1;i<=m;i++){
		if(i%2!=0){
			for(int j = 1;j<=n;j++){
				if(a[ans].place == 1){
					cout << i << " " << j;
					return 0;
				}
				ans++;
			}
		}
		else{
			for(int j = n;j>=1;j--){
				if(a[ans].place == 1){
					cout << i << " " << j;
					return 0;
				}
				ans++;
			}
		}
	}
	return 0;
} 
