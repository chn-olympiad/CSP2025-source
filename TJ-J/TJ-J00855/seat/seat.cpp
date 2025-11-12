#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x > y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[105] = {};
    for(int i = 1;i <= n * m;i++) cin>>a[i];
    int c,r,R = a[1];
    sort(a + 1,a + 1 + (n * m),cmp);
    int b[n][m] = {};
    int I = 1;
    for(int i = 1;i <= n;i++){
    	for(int j = 1;j <= m;j++){
    		b[i][j] = a[I];
    		I++;
    		if(b[i][j] == R){
    			c = i;
    			r = j;
			}
		}
	}
	cout<<c<<" "<<r;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

