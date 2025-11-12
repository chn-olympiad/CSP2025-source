#include<bits/stdc++.h>
using namespace std;
struct l{
	int x,y,z,num,b,mm;
	int bn,nn,mn;
};
bool cmp(l a1,l a2){
	return a1.b > a2.b;
}
  //    { return *__it1 < *__it2; }

int main(){
	int t;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int ti = 0;ti < t;ti++){
		int n,ans = 0;
		cin >> n;
		l a[n];
		int inf[3];
		for(int i = 0;i < 3;i++){
			inf[i] = n/2;
		}
		for(int i = 0;i < n;i++){
			cin >> a[i].x >> a[i].y >> a[i].z;
			/////////
			//cout << a[i].x << ' ' << a[i].y << ' ' << a[i].z << endl;
			/////////
			int m1 = min(a[i].x,min(a[i].y,a[i].z));
			int m2 = max(a[i].x,max(a[i].y,a[i].z));
			if(a[i].x ==m1){
				a[i].nn = 0;
			}
			else if(a[i].y ==m1){
				a[i].nn = 1;
			}
			else if(a[i].z ==m1){
				a[i].nn = 2;
			}
			if(a[i].x ==m2){
				a[i].bn = 0;
			}
			else if(a[i].y ==m2){
				a[i].bn = 1;
			}
			else if(a[i].z ==m2){
				a[i].bn = 2;
			}
			a[i].mn = 3 - a[i].nn - a[i].bn;
			///cout << a[i].mn;
			if(a[i].mn == 0){
				a[i].mm = a[i].x;
			}
			else if(a[i].mn == 1){
				a[i].mm = a[i].y;
			}
			else if(a[i].mn == 2){
				a[i].mm = a[i].z;
			}
			m1 = a[i].mm;
			a[i].num = a[i].mm;
			a[i].x -= m1;
			a[i].y -= m1;
			a[i].z -= m1;
			a[i].b = m2 - m1;

		}
		sort(a,a + n,cmp);
		////////
		/*
		for(int i = 0;i < n;i++){
			cout << a[i].x << ' ' << a[i].y << ' ' << a[i].z << ' ' << a[i].b << ' ' << a[i].num << ' '<< endl;
		}
		//*////////
		for(int i = 0;i < n;i++){
			ans += a[i].b + a[i].num;
			inf[a[i].bn] -= 1;
			////////
			//cout << a[i].bn;
			////////
			if(inf[0] == 0){
				/////
				//cout << "x";
				////
				for(int j = i + 1;j < n;j++){
					if(a[j].bn == 0){
						int m = max(a[j].y,a[j].z);
						a[j].b = m;
						if(m == a[j].y){
							a[j].bn = 1;
						}
						else{
							a[j].bn = 2;
						}
					}
				}
				sort(a + i + 1,a + n,cmp);
				inf[0] = -1;
			}
			else if(inf[1] == 0){
				/////
				//cout << "y";
				////
				for(int j = i + 1;j < n;j++){
					if(a[j].bn == 1){
						int m = max(a[j].x,a[j].z);
						a[j].b = m;
						if(m == a[j].x){
							a[j].bn = 0;
						}
						else{
							a[j].bn = 2;
						}
					}
				}
				sort(a + i + 1,a + n,cmp);
				inf[1] = -1;
			}
			else if(inf[2] == 0){
				/////
				//cout << "z";
				/////
				for(int j = i + 1;j < n;j++){
					if(a[j].bn == 2){
						int m = max(a[j].y,a[j].x);
						a[j].b = m;
						if(m == a[j].y){
							a[j].bn = 1;
						}
						else{
							a[j].bn = 0;
						}
					}
				}
				sort(a + i + 1,a + n,cmp);
				inf[2] = -1;
			}

		}
		cout << ans << endl;
	}
	return 0;
}
