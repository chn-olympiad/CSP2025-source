//陶家轩 SN-S00757 曲江第一学校 
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	srand(time(0));
	cout<<(rand()%100000000+1);
	return 0;
}
