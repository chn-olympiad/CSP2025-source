#include<bits/stdc++.h>
using namespace std;

int seat[110][110];
int score[1100];
int n,m;

bool cmp(int a,int b) {
	return a>b;
}


int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=0; i<n*m; i++) {
		scanf("%d",&score[i]);
	}
	int R=score[0];
	sort(score,score+n*m,cmp);
	bool f=0;
	int index=0;
	for(int i=1; i<=n; i++) {
		if(f==0) {
			for(int j=1; j<=m; j++) {
				if(score[index]==R) {
					cout<<i<<" "<<j<<endl;
					return 0;
				}
				index++;
			}
			f=1;
		} else {
			for(int j=m; j>=1; j--) {
				if(score[index]==R) {
					cout<<i<<" "<<j<<endl;
					return 0;
				}
				index++;
			}
			f=0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
