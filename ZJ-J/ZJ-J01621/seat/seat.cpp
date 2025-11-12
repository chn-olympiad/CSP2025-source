#include <bits/stdc++.h>
using namespace std;
const int maxn=110;
int score[maxn];
bool cmp(int n,int m){
	return n>m;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,place,hang,lie;
	cin >> n >> m;
	int p;
	cin >> p;
	for(int i=1;i<n*m;i++){
		cin >> score[i];
	}
	sort(score+1,score+n*m,cmp);
	if(p>score[1]){
		cout << 1 << ' ' << 1;
		return 0;
	}
	for(int i=1;i<n*m;i++){
		if(p<score[i]&&p>score[i+1]){
			place=i+1;
			break;
		}
	}
	lie=ceil(place/(double)n);
	if(lie%2==0){
		if(place%n==0)hang=1;
		else hang=n+1-place%n;
	}
	else{
		if(place%n==0)hang=n;
		else hang=place%n;
	}
	cout << lie << ' ' << hang;
}