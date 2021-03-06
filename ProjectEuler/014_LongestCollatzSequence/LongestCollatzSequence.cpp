// problem: https://projecteuler.net/problem=14
// hint: math, dynamic programming
// level: easy
#include <iostream>

#define MAX_T   (10000)
#define MAX_N   (5000000)

using namespace std;

inline int getLenOfChain(int64_t n) {
	static int cache[MAX_N+1] = { 0, };
	int &cnt = cache[n];
	if(cnt > 0)
		return cnt;
	cnt = 1;
	while(n > 1) {
		if(n & 0x01) {
			n = 3 * n + 1;
		} else {
			n /= 2;
		}
		if(n <= MAX_N && cache[n] > 0) {
			cnt += cache[n];
			return cnt;
		}
		++cnt;
	}
	return cnt;
}

inline int solve(int n) {
	static int cache[MAX_N+1] = { 0, };
	static int maxLen = 0;
	static int maxStart = 0;
	static int last = 0;
	for(int i = last + 1; i <= n; ++i, ++last) {
		int len = getLenOfChain(i);
		if(len >= maxLen) {
			maxLen = len;
			maxStart = i;
		}
		cache[i] = maxStart;
	}
	return cache[n];
}

int main(void) {
	int nTests;
	cin >> nTests;
	while(nTests--) {
		int n;
		cin >> n;
		cout << solve(n) << endl;
	}
	return 0;
}
