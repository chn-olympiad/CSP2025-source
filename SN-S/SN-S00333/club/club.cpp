#include<bits/stdc++.h>
using namespace std;
struct students{
	int manyi[3] = {};
	int paiming[3] = {};
}stdu[10005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	for(int a = 0;a<t;a++){
		int n ;
		cin >> n;
		for(int i = 0;i<n;i++){
			for(int j = 0;j<3;j++){
				cin >> stdu[i].manyi[j];
				stdu[i].paiming[j] = stdu[i].manyi[j];
			}
			sort(stdu[i].paiming,stdu[i].paiming+3);
			
			for(int j = 0;j<3;j++){
				if(stdu[i].manyi[0] == stdu[i].paiming[j]){stdu[i].paiming[j] = 0;}
				else if(stdu[i].manyi[1] == stdu[i].paiming[j]){stdu[i].paiming[j] = 1;}
				else  if(stdu[i].manyi[2] == stdu[i].paiming[j]){stdu[i].paiming[j] = 2;}
			}
			//ceshi
//			for(int j = 0;j <3;j++)
//			{
//				cout << stdu[i].paiming[j] << " ";
//			}
//			cout << endl;
			
		}
		
		int man = 0;
		
		for(int i = 0;i<n;i++){
			int people[3] = {};
			int j = 2;
			
			L1:
			if(people[stdu[i].paiming[j]] < n/2){
				man = man+stdu[i].manyi[stdu[i].paiming[j]];
				people[stdu[i].paiming[j]]++;
//				cout << i <<" goes to" << stdu[i].paiming[j] << endl;
			}else{
				j--;
				goto L1;
			}
		}
		cout << man;
	}
	fclose(stdin);
	fclose(stdout);
}
