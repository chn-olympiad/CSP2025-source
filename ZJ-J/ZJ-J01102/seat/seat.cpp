#include<bits/stdc++.h>
using namespace std;
#define int64 long long
vector<int> v;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n*m;++i){
		int s;
		scanf("%d",&s);
		v.push_back(s);
	}
	const int R=v[0];
	sort(v.begin(),v.end(),greater<int>());
	int findR=n*m;
	for(int i=0;i<n*m;++i){
		if(v[i]==R){
			findR=i;
			break;
		}
		
	}
	int lie=findR/n,hang=findR%n;
	++lie;
	if(lie%2==0){
		hang=m-hang;
	}else{
		++hang;
	}
	printf("%d %d\n",lie,hang);
	return 0;
}
// chaotic code -> UNchaotic code PLS!
// Huh?a_i<=100?No 1e6?No 1e9?Wow!
//Thank you CCF!


//first:RE 0
//second:WA 0
//third:WA 0
//fourth:AC 100
//So 100pts