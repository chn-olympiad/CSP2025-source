#include<bits/stdc++.h>
using namespace std;
int T,n,vis[100005];
int a1 = 0,b1 = 0,c1 = 0,maxn = n/2,tot = 0,cntt = 0,sum = 0;
struct node{
	int num;
	int pos;
	int person;
}b[100005];
int cmp(node x,node y){
	return x.num > y.num;
}
int calc(int cnt){
	int p = b[++cnt].pos;
	if(p == 1){
		if(a1 >= maxn||vis[b[cnt].person]){
			return 0;
		}
		else{
			a1++;
			sum+=b[cnt].num;
			tot--;
			vis[b[cnt].person] = 1;
		}
	}
	if(p == 2){
		if(b1 >= maxn||vis[b[cnt].person]){
			return 0;
		}
		else{
			b1++;
			sum+=b[cnt].num;
			tot--;
			vis[b[cnt].person] = 1;
		}
	}
	if(p == 3){
		if(c1 >= maxn||vis[b[cnt].person]){
			return 0;
		}
		else{
			c1++;
			sum+=b[cnt].num;
			tot--;
			vis[b[cnt].person] = 1;
		}
	}
	return sum; 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--){
		cin >> n;
		
		for(int i = 1;i <= n;i++){
			cin >> b[++tot].num;
			b[tot].pos = 1;
			b[tot].person = i;
			cin >> b[++tot].num;
			b[tot].pos = 2;
			b[tot].person = i;
			cin >> b[++tot].num;
			b[tot].pos = 3;
			b[tot].person = i;
		}
		sort(b+1,b+1+3*n,cmp);
//		for(int i = 1;i <= 3*n;i++){
//			printf("i = %d\nnum = %d  pos = %d  person = %d\n",i,b[i].num,b[i].pos,b[i].person);
//		}
		tot = n;
		int maxx = -1;
		while(tot){
			maxx = max(maxx,max(cntt,cntt+1));
			
		}
		cout << maxx << endl;
		memset(vis,0,sizeof(vis));
		a1 = 0,b1 = 0,c1 = 0,maxn = n/2,tot = 0,cntt = 0,sum = 0;
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

4 5 0
9 58 0
9 42 0
5 30 0
*/
