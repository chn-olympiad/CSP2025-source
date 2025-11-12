#include<bits/stdc++.h>
using namespace std;
char cl[20]{'0','1','2','3','4','5','6','7','8','9'};
int tongpx[30];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	cin>>n;
	if(n.size()==1){
		cout<<n;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=0;i<n.size();i++){
		bool fla=false;
		for(int j=0;j<10;j++){
			if(n[i]==cl[j]) fla=true;
		}if(fla){
			int newto=n[i]-48;
			tongpx[newto]++;
		}
	}for(int i=9;i>=0;i--){
		for(int j=0;j<tongpx[i];j++){
			cout<<i;
		}
	}fclose(stdin);
	fclose(stdout);
	return 0;
}
