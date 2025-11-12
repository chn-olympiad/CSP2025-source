#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

struct Student{
	int A, B, C, S;
}a[N];

bool cmpA(Student a, Student b){
	return a.A > b.A;
}

bool cmpS(Student a, Student b){
	return a.S > b.S;
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		
		bool ff = true, fff = true;
		
		for(int i = 1;i <=n; i++){
			cin >> a[i].A >> a[i].B >> a[i].C;
			if (a[i].B != 0) ff = false;
			if (a[i].C != 0) fff = false;
			a[i].S = abs(a[i].A-a[i].B)+abs(a[i].C-a[i].B)+abs(a[i].A-a[i].C);
		}
		
		if(ff){
			sort(a+1, a+1+n, cmpA);
			int sum = 0;
			for(int i = 1; i<=n/2; i++){
				sum += a[i].A;
			}
			cout << sum << '\n';
			continue;
		}
		int sum =0;
		int an=0, bn=0, cn=0;
		sort(a+1, a+1+n, cmpS);
		for(int i = 1;i <= n; i++){
			if(a[i].A>a[i].B && a[i].A>a[i].C){
				if(an<n/2){
				an++;sum+=a[i].A;
				}else if(a[i].B > a[i].C && bn < n/2){
					bn++;sum+=a[i].B;
				}else{
					cn++;sum+=a[i].C;
				}
			}
			else if(a[i].B>a[i].A && a[i].B>a[i].C){
				if(bn<n/2){
				bn++;sum+=a[i].B;
				}else if(a[i].A > a[i].C && an < n/2){
					an++;sum+=a[i].A;
				}else{
					cn++;sum+=a[i].C;
				}
			}
			else if(a[i].C>a[i].A && a[i].C>a[i].B){
				if(cn<n/2){
				cn++;sum+=a[i].C;
				}else if(a[i].B > a[i].A && bn < n/2){
					bn++;sum+=a[i].B;
				}else{
					an++;sum+=a[i].A;
				}
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
}
