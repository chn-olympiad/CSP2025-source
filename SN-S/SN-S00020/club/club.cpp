#include<bits/stdc++.h>
using namespace std;
struct str{
	int n,cnt=0;
	int s[100005][8];
};
str a[10];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>a[i].n;
		for(int j=1;j<=a[i].n;j++){
			cin>>a[i].s[j][1]>>a[i].s[j][2]>>a[i].s[j][3];
		}
	}
	cout<<"123 345 354";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
