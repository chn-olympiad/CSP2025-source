#include <bits/stdc++.h>
using namespace std;
int q, n; 
int c1, c2, c3;
long long b=0;
struct Info {
	int v1, v2, v3;
} a[300000];
int main (){
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	scanf ("%d", &q);
	for (int i=1; i<=q; i++){
		b=0, c1=0, c2=0, c3=0;
		scanf ("%d", &n);
		for (int j=1; j<=n; j++){		
			scanf ("%d%d%d", &a[j].v1, &a[j].v2, &a[j].v3);
			int v1=a[j].v1, v2=a[j].v2, v3=a[j].v3;
			if (v1>v2&&v1>v3){
				if (c1<n/2){
					c1++;
					b+=v1;
				}
				else {
					if (v2>v3){
						if (c2<n/2){
							c2++;
							b+=v2;
						}
						else {
						    c3++;
							b+=v3;
						}
					} 
					if (v2<v3){
						if (c3<n/2){
							c3++;
							b+=v3;	
						}
						else {
							c2++;
							b+=v2;
						}
					}
				}
			} 
			if (v2>v1&&v2>v3){
 				if (c2<n/2){
					c2++;
					b+=v2;
				}
				else {
					if (v1>v3){
						if (c1<n/2){
							c1++;
							b+=v1;
						}
						else {
						    c3++;
							b+=v3;
						}
					} 
					if (v1<v3){
						if (c3<n/2){
							c3++;
							b+=v3;	
						}
						else {
							c1++;
							b+=v1;
						}
					}
				}				
			}
			if (v3>v1&&v3>v2){
				if (c3<n/2){
					c3++;
					b+=v3;
				}
				else {
					if (v1>v2){
						if (c1<n/2){
							c1++;
							b+=v1;
						}
						else {
						    c2++;
							b+=v2;
						}
					} 
					if (v1<v2){
						if (c2<n/2){
							c2++;
							b+=v2;	
						}
						else {
							c1++;
							b+=v1;
						}
					}
				}			
			}
	    }
	    printf ("%lld\n", b);
	}
	return 0;
} 
/*
3
4    
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
