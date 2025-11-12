 #include<bits/stdc++.h>
using namespace std;
int n,sum;
int maxx;
int b[100000000];
int q[1000000];
int w[1000000];
int main(){
	int t;
	cin >> t;
	while(t--){
		 
		cin >>n;
		sum = 0;
		if(n != 2){
		for(int i = 1;i <= 10000000;i++){
			b[i] = 0;
		}
		int h,p;
		for(int i = 1;i <= n;i++){
			cin >> b[i] >> h >> p;
		}
		sort(b+1,b+n+1);
		for(int i = n;i > n/2;i--){
			sum += b[i];
		}
		cout << sum << endl;
		}
		else{
			int e,r,t,y,u,o;
			for(int i = 1;i <= 10000;i++){
			q[i] = 0;
			w[i]= 0;
			}
			for(int i = 1;i <= 3;i++){
				cin >> q[i];
			}
			for(int i = 1;i <= 3;i++){
				cin >> w[i];
			}
			e = q[1]+w[2];
			r = q[1]+w[3];
			t = q[2]+w[1];
			y = q[2]+w[3];
			u = q[3]+w[1];
			o = q[3]+w[2];
			sum = max(max(e,r),max(t,max(y,max(u,o))));
			cout<< sum;
		}
	}
	return 0;
}