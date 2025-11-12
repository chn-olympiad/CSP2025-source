#include<bits/stdc++.h>
using namespace std;
int ge_shu[5000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int shu;
	cin>>shu;
	for(int i=0;i<shu;i++){
		cin>>ge_shu[i];
	}sort(ge_shu,ge_shu+shu);
	cout<<ge_shu[shu+1]+ge_shu[1];
	return 0;
}