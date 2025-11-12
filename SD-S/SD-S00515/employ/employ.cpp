#include <algorithm> 
#include <fstream>
#include <string>

int main() {
	using namespace std;
	ifstream cin("employ.in");
	ofstream cout("employ.out");
	int n, m;
	cin >> n >> m;
	string str;
	cin >> str;
	auto c = new int[n];
	for(int i = 0; i < n; i++)
		cin >> c[i];
	sort(c, c + n);
	int ans = 0;
	do
	{
		int pre = 0, done = 0;
		for(int i = 0; i < n; i++)
			if(pre >= c[i] || str[i] == '0')
				++pre;
			else
				++done;
		if(done >= m)
			++ans;
	} while(next_permutation(c, c + n));
	cout << ans << endl;
	delete[] c;
	return 0;
}
