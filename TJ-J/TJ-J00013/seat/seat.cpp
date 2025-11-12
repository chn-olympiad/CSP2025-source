#include<bits/stdc++.h>
using namespace std;
bool cmp (int x,int y) {
	if (x>y) return true;
	else return false;
}
int main () {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	int a[400];
	for (int i=1;i<=n*m;i++) {
		cin >> a[i];
	}
	int R=a[1];
	//cout << R << endl;
	int seat[15][15];
	int c=1,r=1,aa=1;
	sort(a+1,a+(n*m)+1,cmp);
	/*for (int i=1;i<=n*m;i++) {
		cout << a[i];
	}*/
	
	while (seat[r][c]!=R||aa<=n*m) {
		if (c<m&&r%2==1) {
			seat[r][c]=a[aa];
			//cout<<seat[r][c] << " " << R;
			c++; 
			aa++;
			if (seat[r][c]==R) {
				cout << r << " " << c;
				break;
			}
				
		} else if (c<m&&r%2==0) {
			seat[r][c]=a[aa];
			c--; 
			aa++;
			if (seat[r][c]==R) {
				cout << r << " " << c;
				break;
			}
				//cout << r << " " << c;
		} else if (c==m&&r%2==1) {
			r++;
			seat[r][c]=a[aa];
			aa++;
			if (seat[r][c]==R) {
				cout << r << " " << c;
				break;
			}
				//cout << r << " " << c;
		} else if (c==1&&r%2==0) {
			r++;
			seat[r][c]=a[aa];
			aa++;
			if (seat[r][c]==R) {
				cout << r << " " << c;
				break;
			}
		}
		
	}
/*
	2 2
	99 100 97 98	
	*/
	fclose(stdin);
	fclose(stdout);
	return 0;
}
