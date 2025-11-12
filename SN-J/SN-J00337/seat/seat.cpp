//SN-J00337 张巍邺 西安市曲江第一中学
#include<bits/stdc++.h>
using namespace std;
const int N = 102;
int a[N];
int cmp(int a,int b) {
	return a>b;
}

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >>m;
	int s = n*m;
	for(int i  =1; i<=s; i++) {
		cin >>a[i];
	}
	int w=a[1],v=0;

	for(int i = 1; i<=s; i++) {
		for(int j = i+1; j<=s; j++) {
			if(a[j]>a[i]) {
				swap(a[i],a[j]);
			}
		}
	}

	for(int i  =1; i<=s; i++) {
		if(a[i]==w) {
			v=i;
		}
	}

	int h,l;

	if(v%n==0) {
		l=v/n;
		cout <<l<<" "<<n;

	} else {
		l=(v/n)+1;
		if(l%2!=0) {
			h = v%n;

		} else {
			h =n-(v%n) +1;
		}
		cout <<l<<" "<<h;
	}





	return 0;
}


