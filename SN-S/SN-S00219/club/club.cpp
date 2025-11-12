//club
#include<iostream> 
#include<algorithm>
using namespace std;
const int MAX = 100005;

class Student{
public:
	int num;
	int a;
	int b;
	int c;
	int fp;		//0 = a , 1 = b , 2 = c;
	int change;
	int value;
	
	void set(int num,int a,int b,int c){
		this->num = num;
		this->a = a;
		this->b = b;
		this->c = c;
		change = derta();
	}
	
	void kill(){
		num = -1;
		a = b = c = 0;
		fp = -1;
		change = 0;
		value = -1;
	}
	
	int derta(){
		int val = max(max(a , b) , c);

		int tmpArr[3];
		tmpArr[0] = val - a;
		tmpArr[1] = val - b;
		tmpArr[2] = val - c;
		sort(tmpArr , tmpArr + 3);
		return tmpArr[1];
	}
};
int t , n;
Student stu[MAX];

bool compare(Student astu,Student bstu){
	return astu.change < bstu.change;
}

long long tackle(){
	cin >> n;
	//ini
	for(int i = 0;i < n;i++){
		stu[i].kill();
	}
	int tmp01 , tmp02 , tmp03;
	for(int i = 0;i < n;i++){
		cin >> tmp01 >> tmp02 >> tmp03;
		stu[i].set(i , tmp01 , tmp02 , tmp03);
	}
	int cla , clb , clc;
	cla = clb = clc = 0;
	for(int i = 0;i < n;i++){
		tmp01 = max(max(stu[i].a , stu[i].b) , stu[i].c);
		if(stu[i].a == tmp01){
			cla++;
			stu[i].fp = 0;
		} else if(stu[i].b == tmp01){
			clb++;
			stu[i].fp = 1; 
		} else {
			clc++;
			stu[i].fp = 2; 
		}
		stu[i].value = tmp01;
	}
	/*for(int i = 0;i < n;i++){
		cout << stu[i].value << " ";
	}
	cout << "\n" << cla << " " << clb << " " << clc;
	cout << "\n=================\n";*/
	
	//chaneg club
	int remove = 0;
	if(cla > (n/2)){
		sort(stu , stu + n , compare);
		for(int i = 0;((i < n) && (cla - remove > (n/2)));i++){
			if(stu[i].fp == 0){
				stu[i].value -= stu[i].change;
				remove++;
			}
		}
	} else if(clb > (n/2)){
		sort(stu , stu + n , compare);
		for(int i = 0;((i < n) && (clb - remove > (n/2)));i++){
			if(stu[i].fp == 1){
				stu[i].value -= stu[i].change;
				remove++;
			}
		}
	} else if(clc > (n/2)){
		sort(stu , stu + n , compare);
		for(int i = 0;((i < n) && (clc - remove > (n/2)));i++){
			if(stu[i].fp == 2){
				stu[i].value -= stu[i].change;
				remove++;
			}
		}
	}
	long long ans = 0;
	for(int i = 0;i < n;i++){
		ans += stu[i].value;
	}
	return ans;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int i = 0;i < t;i++){
		cout << tackle() << "\n";
	}
	return 0;
}
