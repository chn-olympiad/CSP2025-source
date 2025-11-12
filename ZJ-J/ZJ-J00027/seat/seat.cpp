#include<bits/stdc++.h>
using namespace std;

int sc[1005];

int cmp(int a, int b){
	return (a>b);
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n, m, k=1, a;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> sc[k++];
		}
	}
	k--;
	a = sc[1];
	sort(sc+1, sc+k+1, cmp);
	for(int i=1;i<=k;i++){
		if(sc[i]==a){
			if(((i-1)/n)%2){
				cout << (i-1)/n+1 << ' ' << n-(i-1)%n;
			}
			else{
				cout << (i-1)/n+1 << ' ' << (i-1)%n+1;
			}
			break;
		}
	}
	
	fclose(stdin);
	fclose(stdout);

	return 0;
	
}


