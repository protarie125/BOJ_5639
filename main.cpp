#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;

vi input;
vi output;

void solve(int b, int e) {
	if (b == e) {
		return;
	}

	auto root = input[b];

	if (e - 1 == b) {
		output.push_back(root);
		return;
	}

	auto idx = int{ -1 };
	for (auto i = b; i < e; ++i) {
		if (root < input[i]) {
			idx = i;
			break;
		}
	}

	if (-1 == idx) {
		solve(b + 1, e);
		output.push_back(root);
		return;
	}

	if (b < idx) {
		solve(b + 1, idx);
	}

	if (root < input[e - 1]) {
		solve(idx, e);
	}

	output.push_back(root);
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int x;
	auto ct = int{ 0 };
	while (cin >> x) {
		input.push_back(x);
		++ct;
	}

	solve(0, ct);

	for (const auto& d : output) {
		cout << d << '\n';
	}

	return 0;
}