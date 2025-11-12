#include<bits/stdc++.h>
using namespace std;
int sc[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	int tmp=0;
	cin >> n >> m;
	int all = n*m;
	int posr=0;
	for(int i=0; i<n*m; i++){
		cin >> sc[i];
	} 
//	for(int i=0; i<all; i++){
//		for(int j=i+1; j<all; j++){
//			if(sc[i] < sc[j]){
//                tmp = sc[i];
//				sc[i] = sc[j];
//				sc[j] = tmp;
//			}else{
//			    continue;
//			}
//		}
//	}
//	for(int i=0; i<n*m; i++){
//		cout << sc[i];
//	} 
    int pos = 100 - sc[0]+1;
    int c = pos/n;
    int c1 = pos%n;
    if(c1 == 0){
    	if(c % 2 == 0){
    		cout << c << " " << 1 << endl;
    		return 0;
		}else{
			cout << c << " " << m << endl;
			return 0;
		}
	}else{
		if(c+1 % 2 == 0){
    		cout << c+1 << " " << n-c1 << endl;
    		return 0;
		}else{
			cout << c+1 << " " << c1 << endl;
			return 0;
		}
	}
	
	return 0;
} 
