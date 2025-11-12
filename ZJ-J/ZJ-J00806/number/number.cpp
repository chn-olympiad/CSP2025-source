#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string n;
	cin >> n;
	for (int i = 0; i < n.size(); i++)
		if (n[i] == '9') printf("9");
	for (int i = 0; i < n.size(); i++)
        if (n[i] == '8') printf("8");
    for (int i = 0; i < n.size(); i++)
        if (n[i] == '7') printf("7");
    for (int i = 0; i < n.size(); i++)
        if (n[i] == '6') printf("6");
    for (int i = 0; i < n.size(); i++)
        if (n[i] == '5') printf("5");
    for (int i = 0; i < n.size(); i++)
        if (n[i] == '4') printf("4");
    for (int i = 0; i < n.size(); i++)
        if (n[i] == '3') printf("3");
    for (int i = 0; i < n.size(); i++)
        if (n[i] == '2') printf("2");
    for (int i = 0; i < n.size(); i++)
        if (n[i] == '1') printf("1");
    for (int i = 0; i < n.size(); i++)
        if (n[i] == '0') printf("0");
    fclose(stdin);
    fclose(stdout);
	return 0;
}