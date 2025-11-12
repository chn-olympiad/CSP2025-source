#include<bits/stdc++.h>
using namespace std;
vector<int>a={1,2,3,4,5,6},b={1,1,1,4,4,5},c;
int main(){
	merge(a.begin(),a.end(),b.begin(),b.end(),c.end());
	return 0;
}
