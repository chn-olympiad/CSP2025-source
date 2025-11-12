#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

int t, n;
int a[100010][5];
int b[100010];// 被分入1~3组 
struct node{
	int num, c1, c2;//进c1组 ， c2差 
}c[100010];

bool cmp(node x, node y ){
	return x.c2 < y.c2;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;//输入 
		for( int i = 1;i <= n;i ++ ){
			for( int j = 1; j <= 3; j++ ){
				scanf("%d",&a[i][j]);
			}
		}
		int m1 = n/2, m2 = n/2, m3 = n/2;//人数余
		
		for( int i = 1; i <= n; i++ ){//第一轮 
			if( a[i][1] < a[i][2] ){ 
				b[i] = 2;
				m2--;
			}
			else {
				b[i] = 1;
				m1--;
			}
				
			if( a[i][1] < a[i][3] && b[i] == 1 ){
				b[i] = 3;
				m3--;
				m1++;
			}
			else if( a[i][2] < a[i][3] && b[i] == 2 ){
				b[i] = 3;
				m3--;
				m2++;
			}
		}
		
		//3组 
		if( m3 < 0 ){
			for( int i = 1; i <= n; i++ ){
				int x = a[i][3] - a[i][2];//和 第2组相差
				int y = a[i][3] - a[i][1];//和 第1组相差
				c[i].num = i;
				if( x < 0 || y < 0 ){
					c[i].c1 = b[i];
					c[i].c2 = 1e9;
					continue;
				}
				if( x > y ) c[i].c1 = 1, c[i].c2 = y;
				else if( x < y ) c[i].c1 = 2, c[i].c2 = x;
				else c[i].c1 = 1, c[i].c2 = x;
			}
			sort( c+1,c+n+1,cmp );
			for( int i = 1; i <= abs(m3); i++ ){
				b[c[i].num] = c[i].c1;
			}
		}
		
		//2组
		else if( m2 < 0 ){
			for( int i = 1; i <= n; i++ ){
				int x = a[i][2] - a[i][3];
				int y = a[i][2] - a[i][1];
				c[i].num = i;
				if( x < 0 || y < 0 ){
					c[i].c1 = b[i];
					c[i].c2 = 1e9;
					continue;
				}
				if( x > y ) c[i].c1 = 1, c[i].c2 = y;
				else if( x < y ) c[i].c1 = 3, c[i].c2 = x;
				else c[i].c1 = 1, c[i].c2 = x;
			}
			sort( c+1,c+n+1,cmp );
			for( int i = 1; i <= abs(m2); i++ ){ 
				b[c[i].num] = c[i].c1;
			}
		}
		
		//1组
		else if( m1 < 0 ){
			for( int i = 1; i <= n; i++ ){
				int x = a[i][1] - a[i][3];
				int y = a[i][1] - a[i][2];
				c[i].num = i;
				if( x < 0 || y < 0 ){
					c[i].c1 = b[i];
					c[i].c2 = 1e9;
					continue;
				}
				if( x > y ) c[i].c1 = 2, c[i].c2 = y;
				else if( x < y ) c[i].c1 = 3, c[i].c2 = x;
				else c[i].c1 = 2, c[i].c2 = x;
			}
			sort( c+1,c+n+1,cmp );
			for( int i = 1; i <= abs(m1); i++ ){ 
				b[c[i].num] = c[i].c1;
			}
		}
		
		int ans = 0;//输出
		for( int i = 1; i <= n; i++ ){
		 	ans += a[i][b[i]];
		}
		cout << ans << endl;
	}
	return 0;
}
