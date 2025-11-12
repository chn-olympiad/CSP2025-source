#include<bits/stdc++.h>
using namespace std;
int n,m,a[10010],R,x,y,cnt,ans[110][110],k;
bool flag;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	k=n*m;
	for(int i=1;i<=k;i++){
		cin>>a[i];
		if(i==1)R=a[i];
	}
	sort(a+1,a+1+k);
	reverse(a+1,a+1+k);
	x=y=1;
	while(cnt<k){
		ans[x][y]=a[++cnt];
		if(a[cnt]==R){
			cout<<y<<" "<<x;
			return 0;
		}
		if(!flag)x++;
		else x--;
		if(x>n){
			x=n;
			flag=!flag;
			y++;
		}
		if(x<1){
			x=1;
			flag=!flag;
			y++;
		}
	}
	return 0;
}
/*
2 2
99 100 97 98

2 2
98 99 100 97

10 10
1 99 98 97 96 95 94 93 92 91 90 89 88 87 86 85 84 83 82 81 80
79 78 77 76 75 74 73 72 71 70 69 68 67 66 65 64 63 62 61 60 
59 58 57 56 55 54 53 52 51 50 49 48 47 46 45 44 43 42 41 40
39 38 37 36 35 34 33 32 31  30 29 28 27 26 25 24 23 22 21 20
19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 100
*/