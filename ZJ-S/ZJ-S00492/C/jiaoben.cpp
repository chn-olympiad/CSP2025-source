#include<bits/stdc++.h>
using namespace std;
using vs = vector<string>;
vs re1, wa1, re2, wa2, ac;
string runn;
set<string>S;

void run(string s, vs &re, vs &wa)
{
	// if(S.count(s)) return;
	system(("cp replace"+s+".in replace.in").c_str());
	if(system(runn.c_str())) re.emplace_back(s), S.insert(s);
	else if(system(("diff replace.out replace"+s+".ans -BZ").c_str())) wa.emplace_back(s), S.insert(s);
	else ac.emplace_back(s);
}

void f(vs &re, vs &wa)
{
	run("1",re,wa);
	run("2",re,wa);
	run("3",re,wa);
	run("4",re,wa);
	run("5",re,wa);
}

int main()
{
	if(system("g++ C.cpp -o C -std=c++14 -O2 -static")) return printf("CE"), 0;
	runn = "ulimit -v 2097152;ulimit -s 2097152;timeout 1.0 time ./C";
	f(re1,wa1), ac.clear();
	if(system("g++ C.cpp -o C -std=c++14 -O2 -fsanitize=address,undefined")) return printf("CE2"), 0;
	runn = "ulimit -s 2097152;time ./C";
	f(re2,wa2);
	printf("AC: ");for(auto i:ac) printf("%s ", i.c_str());
	printf("\n");
	printf("RE1: ");for(auto i:re1) printf("%s ", i.c_str());
	printf("\n");
	printf("WA1: ");for(auto i:wa1) printf("%s ", i.c_str());
	printf("\n");
	printf("RE2: ");for(auto i:re2) printf("%s ", i.c_str());
	printf("\n");
	printf("WA2: ");for(auto i:wa2) printf("%s ", i.c_str());
	printf("\n");
	return 0;
}