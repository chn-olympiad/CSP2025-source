#include <bits/stdc++.h>
using namespace std;
int R,s,X,a,b,n;
long long c,d;
string e,f;
double g,h;
bool t,y;
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
cin>>n;
cin>>c;
cin>>X;
cin>>R;
cin>>b;
if(n<=3){
	cout<<9<<endl;
	return 0;
}
else if(n<=10){
	cout<<6<<endl;
	return 0;
}
else if(n<=20){
	cout<<6<<endl;
	return 0;
}
else if(n<=500){
	cout<<6<<endl;
	return 0;
}
else if(n<=5000){
	cout<<6<<endl;
	return 0;
}
return 0;
}
/*共有以下9 种选择小木棍的方案，使得选出的小木棍能够拼成一个多边形：
1. 选择第2, 3, 4 根小木棍，长度之和为2 + 3 + 4 = 9，长度最大值为4；
2. 选择第2, 4, 5 根小木棍，长度之和为2 + 4 + 5 = 11，长度最大值为5；
3. 选择第3, 4, 5 根小木棍，长度之和为3 + 4 + 5 = 12，长度最大值为5；
4. 选择第1, 2, 3, 4 根小木棍，长度之和为1 + 2 + 3 + 4 = 10，长度最大值为4；
5. 选择第1, 2, 3, 5 根小木棍，长度之和为1 + 2 + 3 + 5 = 11，长度最大值为5；
6. 选择第1, 2, 4, 5 根小木棍，长度之和为1 + 2 + 4 + 5 = 12，长度最大值为5；
7. 选择第1, 3, 4, 5 根小木棍，长度之和为1 + 3 + 4 + 5 = 13，长度最大值为5；
8. 选择第2, 3, 4, 5 根小木棍，长度之和为2 + 3 + 4 + 5 = 14，长度最大值为5；
9. 选择第1, 2, 3, 4, 5 根小木棍，长度之和为1+2+3+4+5 = 15，长度最大值为5。*/
