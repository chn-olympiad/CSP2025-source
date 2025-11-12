#include<bits/stdc++.h>//AC
#define int long long
#define INF 1145141919810
using namespace std;
char c;
int a[21],xp;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>c){
		if(isdigit(c))
			a[c-48]++;
	}
	for(int i=9;i>=0;i--)
	for(int j=1;j<=a[i];j++)
		cout<<i;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
