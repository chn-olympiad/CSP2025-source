#include<bits/stdc++.h>
using namespace std;
int hang,lie,a[104],ar;
int b[13][13];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0);
	cin>>hang>>lie;

	int s=hang*lie;
	for(int i=0; i<s; i++) {
		cin>>a[i];
	}
	ar=a[0];
	sort(a,a+s);
	int qjs=0;
	for(int i=0; i<hang; i++) {
		for(int j=0; j<lie; j++) {
			b[i][j]=a[qjs];
			qjs++;
		}
	}
	for(int i=0; i<hang; i++) {
		for(int j=0; j<lie; j++) {
			if(b[i][j]==ar)cout<<j+1<<" "<<i+1;
		}
	}
	fclose(stdin);
    fclose(stdout);
	return 0;
}
