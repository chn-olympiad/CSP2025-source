#include<bits/stdc++.h>
using namespace std;
int n , m,  r, a[20][20],lie,hang,b[110];
int pos;
bool cmp(int a, int b){
	return a > b;
}
int main(){

	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n *m ;i++){
		cin >> b[i];
	}
	r = b[1];
	
	sort(b+1,b+1+n*m,cmp);
	
	for(int i = 1; i <= n*m; i++){
		if(b[i]==r){
			pos = i;
			break;
		}
	}

	
	if(pos % n == 0){
		lie = pos / n;
		if(lie%2 == 1) hang = n;
		else hang = 1;
	}else{
		lie = pos/n;
		hang = pos %n;
		if(lie%2==1){
			hang = n - hang + 1;
		}
		lie += 1;
	}

	
	cout << lie <<" "<<hang << endl; 
	
	
	
	
	return 0;
} 
