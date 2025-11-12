//SN-J00337 张巍邺 西安市曲江第一中学
#include<bits/stdc++.h>
using namespace std;
const int N = 5010;
int a[N];
int cmp(int a,int b) {
	return a<b;
}
int tre[N];
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for(int i =1; i<=n; i++) {
		cin >>a[i];

	}
	tre[1]= a[1];
	for(int i =2; i<=n; i++) {
		tre[i] = tre[i-1]+a[i];
	}

	sort(a+1,a+n+1,cmp);
	if(n==3) {
		if(a[1]+a[2]>a[3]) {
			ans++;
		}
		cout <<ans;
		return 0;
	}
	for(int j = 1; j<=n-2; j++) {
		for(int i = j+1; i<=n-1; i++) {

			cout << ":"<<j<<" "<<i<<" ";
			for(int q =i+1; q<=n; q++) {
				if((tre[i]-tre[j]+a[j])>a[q]) {
					cout <<"P"<<tre[i]-tre[j]+a[j]<<'\n';
					ans++;
				}
			}
		}



	}
	cout <<ans;
	return 0;
}
