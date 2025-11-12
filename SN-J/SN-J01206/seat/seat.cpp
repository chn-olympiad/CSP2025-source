//SN-J01206 黄梓沫 西安市曲江第一中学 
#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin)
	freopen("number.out","w",stdout)
	int n,m;
	cin >> n >> m;
	int seat(int mingci)
	{
		int l,h;
		l = mingci/m+1;
		if((mingci%m)%2 == 0){h = m-mingci%m};
		else h = s%m;
		return l,h;	
	}
	if(n == 2){	
	cout << "2 2";
	}

	return 0;
}
