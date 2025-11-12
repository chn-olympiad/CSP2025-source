#define file_io(id) do { \
    freopen(id".in", "r", stdin); freopen(id".out", "w", stdout); } while(false)
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

string str;
vector<int> numbers;

int main() {
    file_io("number");
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> str;
    for (char c : str)
        if (isdigit(c)) numbers.push_back(c - '0');
    sort(numbers.begin(), numbers.end(), greater<int>());
    for (int n : numbers)
        cout << n;
    cout << endl;

	return 0;
}

