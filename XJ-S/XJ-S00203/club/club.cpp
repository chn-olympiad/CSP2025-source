#include <bits/stdc++.h>
using namespace std;
long long q[10010][10010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,a,b,c;
	cin>>n;
	for(int x=1;x<=n;x++){
		int zushu,v=0;
		cin>>zushu;
		int yiban=zushu/2;
		for(int y=1;y<=zushu;y++){
			for(int z=1;z<=3;z++){
				cin>>q[y][z];
			}
			
		}
	}
	 
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
