#include <iostream>
#include <string>
using namespace std;
#define LL long long
#define x first
#define y second

typedef pair<string,string> PB;
const int N = 200010;

PB str[N];
int sle[N];

//字符串函数叕tm忘了 
//花了20分钟左右来试字符串的函数，没全试出来，喜提TLE，一看测试点数据才tm10分
 

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,T;
	cin >> n >> T;
	for (int i = 0;i < n;i++){
		cin >> str[i].x >> str[i].y;
		sle[i] = str[i].x.length();
	}
	string str1,str2,in1,in2;
	while (T--){
		cin >> in1 >> in2;
		int len1 = in1.length(),len2 = in2.length();
		LL result = 0;
		for (int i = 0;i < n;i++){
			if (len1 < sle[i])
				continue;
			str1 = in1,str2 = in2;
			for (int s1 = 0,f1 = in1.find(str[i].x,s1);f1 >= 0;f1 = in1.find(str[i].x,s1)){
				str1 = in1;
				str1.erase(f1,sle[i]);
				str1.insert(f1,str[i].y);
				if (str1 == in2)
					result++;
				s1 = f1 + sle[i];
			}
		}
		cout << result << '\n';
	}

	return 0;
}
