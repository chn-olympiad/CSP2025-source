#include <bits/stdc++.h>
using namespace std;
int th,c1,c2,c3,t,n,k2 = 0,b[100001][2];

int dv(){
	c1 = 0;
	c2 = 0;
	c3 = 0;
	int thv = 0;
	for (int i = 0;i < n;i++){
		int g = max(max(b[i][0],b[i][1]),max(b[i][1],b[i][2]));
		thv += g;
/*/		
		if(b[i][0] == g && !(b[i][1] == g || b[i][2] == g)) c1++;
		else if(b[i][1] == g && !(b[i][0] == g || b[i][2] == g)) c2++;
		else if(b[i][2] == g && !(b[i][1] == g || b[i][0] == g)) c3++;
		else if(!(b[i][0] == g) && (b[i][1] == g || b[i][2] == g)) c2 ++;
		else c1 ++;
/*/		
	}	

	if (c1 > n/2){
		int p = b[0][0];
		int pm = 0;
		for (int l = 0;l < n;l++){
			if (b[l][0] < p) p = b[l][0];pm = l;
		}
		b[pm][0] = 0;
		dv();
	}
	if (c2 > n/2){
		int p = b[0][1];
		int pm = 0;
		for (int l = 0;l < n;l++){
			if (b[l][1] < p) p = b[l][1];pm = l;
		}
		b[pm][1] = 0;
		dv();
	}
	if (c3 > n/2){
		int p = b[0][2];
		int pm = 0;
		for (int l = 0;l < n;l++){
			if (b[l][2] < p) p = b[l][2];pm = l;
		}
		b[pm][2] = 0;
		dv();
	}

	
	return thv;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int i=0;i <t;i++){
		cin >> n;
		for (int i = 0;i < n;i++){
			for(int j = 0;j < 3;j++){
				cin >> b[i][j];
			}
		}
		th = dv();
		
		cout << th << "\n";
		th = 0;	
	}
	return 0;
}
