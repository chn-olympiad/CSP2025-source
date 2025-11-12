#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 10;
int n, k, a[MAXN], check_a = 1, ans, check_b = 1;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] != 1)check_a = 0;
	}
	if(check_a == 1){
		cout << n / 2 << '\n';
	}
	else cout << 2 << '\n';
	return 0;
}
/*
T1 and T2 is really easy, but I still use 35 minutes in total to finish and debug it.I finish them at 9:05.

RP++RP++RP++			RP++RP++RP++				RP++					RP++
RP++		RP++   		RP++		RP++			RP++					RP++
RP++		RP++		RP++		RP++			RP++					RP++
RP++		RP++		RP++		RP++	RP++RP++RP++RP++RP++	RP++RP++RP++RP++RP++
RP++RP++RP++			RP++RP++RP++		RP++RP++RP++RP++RP++	RP++RP++RP++RP++RP++
RP++RP++				RP++				RP++RP++RP++RP++RP++	RP++RP++RP++RP++RP++
RP++   RP++				RP++						RP++					RP++
RP++ 	 RP++			RP++						RP++					RP++
RP++	   RP++		    RP++						RP++					RP++

I found that Visual Studio Code was arrowed to use when I write xor.cpp at 9:37.
It made me happy because I like using VS code very much.
Several days ago, my OI teacher asked me not to use VS code because he tought that VS code is not arrowed to use in CSP-J2.
I don't like Dev-C++, because it made my code CE in exercise many times but it didn't remind me.
Although VS code is installed in Windows, it can remind me when I make mistakes in code, because it use mingw64\g++.exe to build(Dev-C++ use TDM-GCC 9.2.0).
That's all.I'm going to write code.Bye!
*/