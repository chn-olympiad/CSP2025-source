#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n  , m;
struct node{
	long long Grades , id;
};

bool cmp(node a ,node b){
	return a.Grades > b.Grades;
}

node a[N];
int main(){
	
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	
	cin >> n >> m;
	
	for(int i = 1; i <= n * m; i++){
		cin >> a[i].Grades;
		a[i].id = i;
	}
	
	sort(a + 1 , a + n * m + 1 , cmp);
	
	long long line = 1 , list = 1;
	bool flag = true;
	for(int i = 1; i <= n * m; i++){
		
		if(a[i].id == 1) cout << line << " " << list;
		if(list == n && flag == true){
			list = n;
			line++;
			flag = false;
		}
		else if(list == 1 && flag == false){
			list = 1;
			line++;
			flag = true; 
		}
		else if(flag == true)
			list++;
		else list--;
	}
	
	
	return 0;
}