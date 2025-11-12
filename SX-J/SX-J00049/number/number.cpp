#include <bits/stdc++.h>
using namespace std;

vector<int> validNumber;
char c;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	while (cin >> c) {
		if (c >= '0' && c <= '9') {
			validNumber.push_back(c - '0');
		}
	}

	sort(validNumber.begin(), validNumber.end(), greater<int>());
	for (int i = 0; i < validNumber.size(); i++) {
		cout << validNumber[i];
	}

	return 0;
}

/*
Where did you learn what it means to reciprocate?
And how much can I be expected to tolerate?
So I started to think 'bout the plans I made the debt unpaid.
And you just can't call a spade a spade.

I watch the moon.
Let it run my mood.
Can't stop thinking of you.
I watch you.
So long nice to know you I'll be moving on.

We started it off in such a nice place.
We were talking the same language.
I o-open and I'm closing.
You can't stand the thought,
of real a beating heart.
You'd be holding having,
trouble-e-e owning and,
admit that I'm hoping.

I watch mon.
Let it run my mood.
Can't stop thinking of you.
I watch you.
So long nice to know you I'll be moving on.
*/