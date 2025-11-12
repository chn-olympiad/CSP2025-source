#include <bits/stdc++.h> 
using namespace std;

int t, n;
long long ms = 0, ta = 0, tb = 0, tc = 0;

bool cmp(int x, int y){
	return x>y;
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		ms = 0, ta = 0, tb = 0, tc = 0;
		int a[n], b[n], c[n], ma[n], mc[n], mb[n];
		bool f1 = 1, f2 = 1;
		
		for(int j = 0; j < n; j++){
			cin >> a[j] >> b[j] >> c[j];
			if(b[j] != 0){
				f1 = 0;
				if(c[j] != 0){
					f2 = 0;
				}
			}
			if(a[j] > b[j] && a[j] > c[j]){
				ma[ta++] = j;
				ms+=a[j];
			}
			else if(b[j] > a[j] && b[j] > c[j]){
				mb[tb++] = j;
				ms+=b[j];
			}
			else if(c[j] > a[j] && c[j] > b[j]){
				mc[tc++] = j;
				ms+=c[j];
			}
		}
		
		if(ta > n/2){
			for(int j = 0; j < ta -1; j++){
				int ti = j;
				for(int k = j+1; k < ta; k++){
					if(a[ma[k]]>a[ma[ti]]) ti = k;
				}
				swap(ma[j], ma[ti]);
				swap(a[j], a[ti]);
			}
			if(f1){
				int nms;
				for(int x = 0; x < n/2; x++) nms+= a[x];
				cout << nms;
				break;
			}
			
			for(int j = 0; j < ta - n/2; j++){
				if((tb < n/2 || tc > n/2 ) && b[ma[j]] > c[ma[j]]) ms = ms-a[ma[j]]+b[ma[j]];
				else ms = ms-a[ma[j]]+c[ma[j]];
			}
		}
		else if(tb > n/2){
			for(int j = 0; j < tb - 1; j++){
				int ti = j;
				for(int k = j+1; k < tb; k++){
					if(a[mb[k]]>a[mb[ti]]) ti = k;
				}
				swap(mb[j], mb[ti]);
				swap(b[j], b[ti]);
			}
			
			for(int j = 0; j < tb - n/2; j++){
				if((ta/4 < n/2 || tc > n/2 ) && a[ma[j]] > c[ma[j]]) ms = ms-b[mb[j]]+a[mb[j]];
				else ms = ms-b[mb[j]]+c[mb[j]];
			}
		}
		else if(tc > n/2){
			for(int j = 0; j < tc -1; j++){
				int ti = j;
				for(int k = j+1; k < tc; k++){
					if(a[mc[k]]>a[mc[ti]]) ti = k;
				}
				swap(mc[j], mc[ti]);
				swap(c[j], c[ti]);
			}
			
			for(int j = 0; j < tc - n/2; j++){
				if((tb < n/2 || ta > n/2 ) && b[ma[j]] > a[ma[j]]) ms = ms-c[mc[j]]+b[mc[j]];
				else ms = ms-c[mb[j]]+a[mb[j]];
			}
		}
		
		
		cout << ms << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
