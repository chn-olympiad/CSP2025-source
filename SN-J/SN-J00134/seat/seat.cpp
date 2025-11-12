// SN-J00134  刘浩辰  西安高新一中沣东中学 

#include <bits/stdc++.h>

using namespace std;

int cj[105] = {0};

int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("D:/SN-J00134/number/number.in","r",stdin);
	freopen("D:/SN-J00134/number/number.out","w",stdout); 
	
	int n,m;
	cin >> n >> m;
	int z = n * m;
	for(int i = 0;i < z;++i)
		cin >> cj[i];
	
	int xr = cj[0];
	sort(cj,cj+z,cmp);
	int pm = 0;
	for(int i = 0;i < z;++i)
		if(cj[i] == xr)
			pm = i+1;
	int c,r;
	if(pm <= m){
		c = 1;
		r = pm;
	}else{
		if(pm % n == 0){
			for(int i = 1;i <= z;++i)
				if(i % 2 == 0)
					r = n;
				else
					r = 1;
			c = pm / n;
		}
		else{
			c = pm / n + 1;
			for(int i = 1;i <= z;++z){
				if (i % 2 == 0)
					r = pm / n;
				
				else
					r = pm / n - 1;
			}
		}
		
		
	}
	cout << c << " " << r;
	return 0;
}

