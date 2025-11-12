#include <bits/stdc++.h>

using namespace std;

int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	
	int s[1010]= {0};
	int i,j,f = 0;
	cin >> s[1010];
	
	for(int i=0;i<=110;i++){
		int right=s[0];
		if(s[i]>right){
			swap(s[i],right);
		}
	}
	cout << s << endl;
	
	
	
	
	//fclose(stdin);
	//fclose(stdout);
	
	return 0;
} 
