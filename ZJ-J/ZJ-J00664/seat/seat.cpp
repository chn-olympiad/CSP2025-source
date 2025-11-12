#include <bits/stdc++.h>
using namespace std;
int n,m,score,tot=1;
int c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;++i){
		for (int j=1;j<=m;++j){
			int x;
			cin >> x;
			if (i==1&&j==1) score = x;
			else{
				if (x>score) tot++;
			}
		}
	}
	if (tot%n==0) c = tot/n;
	else c=tot/n+1;
	if (c%2==0){
		if (tot%n==0) r = 1;
		else r = n-(tot%n)+1;
	}
	else{
		if (tot%n==0) r = n;
		else r=tot%n;
	}
	cout << c << " " << r;

	return 0;
}

