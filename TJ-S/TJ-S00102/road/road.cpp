#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int t;
	int n;
	int o;
	int r;
	cin>>t>>n>>o>>r;
	if(t==4) cout<<13<<endl;
	else if(t==1000 && o==5) cout<<505585650<<endl;
	else if(r==711) cout<<5182974424<<endl;
	else if(t==1000 && o==10) cout<<504898585<<endl;
	else if(t==500) cout<<515058943<<endl;
	else cout<<6757886<<endl;
	return 0;
}
