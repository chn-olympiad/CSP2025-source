#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+100;
int ans[N][3];
int arr[N][3];

int max_(int a,int b,int c,int d) {
	if(max(a,max(b,max(c,d))) == a) {
		return 1;
	} else if(max(a,max(b,max(c,d))) == b) {
		return 2;
	} else if(max(a,max(b,max(c,d))) == c) {
		return 3;
	} else if(max(a,max(b,max(c,d))) == d) {
		return 4;
	}
}

int max__(int a,int b,int c) {
	if(max(a,max(b,c)) == a) {
		return 1;
	} else if(max(a,max(b,c)) == b) {
		return 2;
	} else if(max(a,max(b,c)) == c) {
		return 3;
	}
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>> t;
	while(t--) {
		int a;
		cin>>a;
		for(int n = 1; n<=a; n++) {
			for(int i = 1; i<=3; i++) {
				cin >> arr[n][i];
			}
		}
		int x = 0;
		int y = 0;
		int z = 0;
		for(int n = 1; n<=a; n++) {
			for(int i = 1; i<=a; i++) {
				switch(max_(ans[n-1][0]+arr[n][i],ans[n-1][1]+arr[n][i],ans[n-1][2]+arr[n][i],ans[n][i-1])) {
					case 1: {
						if(x == a/2) {
							ans[n][i] = max(ans[n-1][1]+arr[n][i],max(ans[n-1][2]+arr[n][i],ans[n][i-1]));
						} else {
							x++;
							ans[n][i] = ans[n-1][0]+arr[n][i];
						}
						break;
					}
					case 2: {
						if(y == a/2) {
							ans[n][i] = max(ans[n-1][0]+arr[n][i],max(ans[n-1][2]+arr[n][i],ans[n][i-1]));
						} else {
							y++;
							ans[n][i] = ans[n-1][1]+arr[n][i];
						}
						break;
					}
					case 3: {
						if(z == a/2) {
							ans[n][i] = max(ans[n-1][0]+arr[n][i],max(ans[n-1][1]+arr[n][i],ans[n][i-1]));
						} else {
							z++;
							ans[n][i] = ans[n-1][2]+arr[n][i];
						}
						break;
					}
					case 4: {
						switch(max__(ans[n][0],ans[n][1],ans[n][2])) {
							case 1: {
								if(x == a / 2) {
									if(max(ans[n][1],ans[n][2]) == ans[n][1]) {
										ans[n][i] = ans[n][1];
									} else {
										ans[n][i] = ans[n][2];
									}
								}
								x++;
								ans[n][i] = ans[n][0];
								break;
							}
							case 2: {
								if(y == a / 2) {
									if(max(ans[n][0],ans[n][2]) == ans[n][0]) {
										ans[n][i] = ans[n][0];
									} else {
										ans[n][i] = ans[n][2];
									}
								}
								y++;
								ans[n][i] = ans[n][1];
								break;
							}
							case 3: {
								if(z == a / 2) {
									if(max(ans[n][1],ans[n][0]) == ans[n][1]) {
										ans[n][i] = ans[n][1];
									} else {
										ans[n][i] = ans[n][0];
									}
								}
								z++;
								ans[n][i] = ans[n][2];
								break;
							}
						}
						break;
					}
				}
			}
		}
		cout << max(ans[a-1][0],max(ans[a-1][1],ans[a-1][2]));
	}
	return 0;
}
