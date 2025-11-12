#include<bits/stdc++.h>
using namespace std;


int main(){
	freopen("set1.in","r",stdin);
	freopen("set1.out","w",stdout);
	int set[11][11];
	int pm[110];
	int n,m,nq,mq,vis,vispm;
	cin >> n >>m;
	for(int i = 1;i<=n*m;i++){
		cin >> pm[i];
	}
	int f = n*m;
	vispm = pm[1];
	for(int i = 1;i<=f;i++){
		for(int j = i+1;j<=f;j++){
			if(pm[i] < pm[j]){
				int h = pm[i];
				pm[i] = pm[j];
				pm[j] = h;
			}
		}	
	}
	for(int i = 1;i<=f;i++){
		if(pm[i] == vispm){
			vis = i;
		}
	}
	int a = 1;
	for(int i = 1;i<=n;i++){
		nq = i;
		for(int j = 1;j<=m;j++){
			mq = i;
			set[nq][mq] = pm[a];
			a++;
		}
	}
	int ml = 1;
	int nl = 1;
	int avis =vis;
for(int i = 1;i<=m;i++){
	if(vis>n){
		ml++;
		vis-=n;
	}
	if(ml%2 == 1){
	nl = vis;
	}
	if(ml%2 == 0){
		nl = n*m-avis+1;
	}
}
	cout << ml <<" "<< nl;
	return 0;
}
