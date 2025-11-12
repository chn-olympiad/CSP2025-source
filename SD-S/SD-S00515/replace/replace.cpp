#include <fstream>
#include <string>

int main() {
	using namespace std;
	ifstream cin("replace.in");
	ofstream cout("replace.out");
	int n, q;
	cin >> n >> q;
	auto arr = new pair<string, string>[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;
	while(q--)
	{
		string t1, t2;
		cin >> t1 >> t2;
		if(t1.size() != t2.size())
		{
			cout << 0 << '\n';
			continue;
		}
		int front = 0, back = t2.size() - 1;
		while(t1[front] == t2[front])
			++front;
		while(back >= 0 && t1[back] == t2[back])
			--back;
		int res = 0;
		string src = t1.substr(front, back - front + 1), dst = t2.substr(front, back - front + 1);
		for(int i = 0; i < n; i++)
		{
			int now = 0;
			while(now < arr[i].first.size() && arr[i].first.find(src, now) != -1)
			{
				now = arr[i].first.find(src, now);
				if(arr[i].second.substr(now, dst.size()) == dst)
					++res;
				++now;
			}	
		}  	
		cout << res << '\n';
	}
	delete[] arr;
	return 0;
} 
