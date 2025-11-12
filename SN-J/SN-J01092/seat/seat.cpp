#include<bits/stdc++.h>
using namespace std;
int n,m,f[114] = {};//114514
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++){
		cin >> f[i];
	}
	int rf = f[1];
	sort(f + 1,f + 1 + n + m,cmp);
	for(int de,hang = 1,i = 1,lie = 0;i <= n * m;i++){
		if(i % n == 1){
			lie ++;
			if(lie % 2 == 1){
				//ji shu wei zheng xu pai lie
				de = 1,hang = 0;
			}else{
				//ou shu wei dao xu pai lie
				de = 0,hang = n + 1;
			}
		}
		if(de){
			hang ++;
		}else{
			hang --;
		}
		if(f[i] == rf){
			//manba out
			printf("%d %d",lie,hang);
			return 0;
		} 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
