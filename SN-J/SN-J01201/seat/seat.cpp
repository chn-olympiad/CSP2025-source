#include<bits/stdc++.h> 
using namespace std;
int aligon[105];
int nort,mosten,anserton[15][15],ciljil,iuovem = 1,jubaligons = 1;
bool cmp(int x,int y){
	return x > y;
}
void comaillindta(){
	if((jubaligons == 1 && iuovem%2 == 0)||(jubaligons == nort && iuovem%2 == 1)){
		iuovem++;
		return;
	}
	if(iuovem%2 == 0){
		jubaligons--;
		return;
	}
	if(iuovem%2 == 1){
		jubaligons++;
		return;
	}
	return ;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> nort >> mosten;
	for(int i = 1;i <= nort*mosten;i++){
		cin >> aligon[i];
	}
	ciljil = aligon[1];
	sort(aligon+1,aligon+nort*mosten+1,cmp);
	int cumatusn = 0;
	while(1){
		anserton[iuovem][jubaligons] = aligon[++cumatusn];
		if(aligon[cumatusn] == ciljil){
			cout << iuovem <<' '<< jubaligons;
			return 0;
		}
		comaillindta();
	}
	return 0;
}
