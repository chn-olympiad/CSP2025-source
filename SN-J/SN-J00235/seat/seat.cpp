#include <bits/stdc++.h>
using namespace std;
int a[11000];
int n,m;
int cj;
int h,l;
int v;
bool cmp(int a1,int a2){
	return a1 > a2;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    int nm = n * m;
    for (int i = 1; i <= nm; i++){
    	scanf("%d",&a[i]);
	}
	cj = a[1];
	sort(a+1,a+nm+1,cmp);
	for (int i = 1; i <= nm; i++){
		if (a[i] == cj) v = i;
	}
	if (v % n != 0){
		l = v / n + 1;
		h = v % m;
	}
	else{
		l = v / n;
	    h = m;
	}
	cout << l << " " << h;
	return 0;
}

