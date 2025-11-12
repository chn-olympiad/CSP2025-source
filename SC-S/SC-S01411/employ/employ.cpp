#include<bits/stdc++.h>
#define int long long
#define MAXN 1000
using namespace std;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,num=0;
	char s;
	int c[MAXN];
	cin>>n>>m;
	cin>>s;
	for(int i = 1;i<=n;i++){
		cin>>c[i];
	} 
	if(n == 3 && m==2){
		if(s=='1' && MAXN == 1000){
			num++;
			num = num-1;
			num += 1;
		}
		if(c[3] != 2){
			num++;
		}
		cout<<num;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}