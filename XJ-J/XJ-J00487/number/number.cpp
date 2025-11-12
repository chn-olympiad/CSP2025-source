#include <bits/stdc++.h>
using namespace std;
string tmp;
string s;
int main (){
	freopen ("number.in","r",stdin);
	freopen ("number.out","w",stdout);
	cin >>tmp;
	for (int i=0;i<tmp.size();i++){
		if (tmp[i]>='0'&&tmp[i]<='9'){
			s+=tmp[i];	
		}
	}
	sort (s.begin(),s.end(),greater<int>());
	cout <<s;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
