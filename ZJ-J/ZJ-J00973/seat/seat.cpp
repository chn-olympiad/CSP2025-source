#include<iostream>
#include<algorithm>
using namespace std;
int num[120]={};
int a[12][12]={};
bool f(int a,int b ){
	return a>=b;
}
int main(){
	int n , m;
	int k = 1;
	int fen;
	cin >> n;
	cin >> m;
	//cout << n <<" "<<m;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			
			cin >> num[k];
			if (k==1){
				fen = num[k];
			}
			//cout << num[k] << ' ' << i << ' '<< j << " "<< (i<=m) <<endl;
			k++;
		}
	}
	sort(num+1,num+n*m+1,f);
	int hang =1;
	int lie = 1;
	bool flag = true;
	for(int i = 1;i<=n*m;i++){
		a[hang][lie] = num[i];
		if(num[i]==fen){
			break;
		}
		if(flag){
			if(hang == n){
				if(lie==m){
					break;
				}
				else{
					flag = !flag;
					//cout << flag;
					lie++;
				}
			}
			else{
				hang++;
			}
		}
		else{
			if(hang == 1){
				if(lie==m){
					break;
				}
				else{
					flag = !flag;
					//cout << flag;
					lie++;
				}
			}
			else{
				hang--;
			}
		}
		
	}
	cout << lie << ' ' << hang;
	//for(int i = 0;i<=n*m;i++)cout << num[i] << " ";
	return 0;
}