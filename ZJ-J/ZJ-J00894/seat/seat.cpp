#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define IO
using namespace std;
#define ll long long
#define Max(a,b) (((a)>(b))?(a):(b))
#define Min(a,b) (((a)<(b))?(a):(b))
#define L(i,j,k) for(int i=(j);i<=(k);i++)
#define R(i,j,k) for(int i=(j);i>=(k);i--)
int n,m,pos,anx,any;
int a[105],k=1;
int mp[15][15];
int main(){
#ifdef IO
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	scanf("%d %d",&n,&m);
	L(i,1,n*m){
		scanf("%d",&a[i]);
	}
	pos=a[1];
	sort(a+1,a+n*m+1,[](int a,int b){
		return a>b;
	});
	L(i,1,n){
		if(i&1){
			L(j,1,m){
				mp[i][j]=a[k++];
			}
		}else{
			R(j,m,1){
				mp[i][j]=a[k++];
			}
		}
	}
	L(i,1,n){
		L(j,1,m){
			if(mp[i][j]==pos){
				anx=i;
				any=j;
				break;
			}
		}
	}
	printf("%d %d",anx,any);
	putchar('\n');
	fclose(stdin);
	fclose(stdout);
	return 0;
}
