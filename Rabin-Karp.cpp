// Time Complexity :
// The average and best-case running time of the Rabin - Karp algorithm is O(n + m), 
// but its worst - case time is O(nm).
// The worst case of the Rabin - Karp algorithm occurs when all characters of pattern 
// and text are the same as the hash values of all the substrings of txt[] match with 
// the hash value of pat[].
//
// Auxiliary Space : O(1)

#include <iostream>
#include <string>

#define d 256

void search(std::string txt, std::string pat, int q = INT_MAX) {
	size_t M = pat.size(), N = txt.size();
	size_t p = 0, t = 0, h = 1;
	size_t j;

	for (size_t i = 0; i < M - 1; ++i) h = (h * d) % q;
	
	for (size_t i = 0; i < M; ++i) {
		p = (d * p + pat[i]) % q;
		t = (d * t + txt[i]) % q;
	}

	for (size_t i = 0; i <= N - M; ++i) {
		if (p == t) {
			for (j = 0; j < M; ++j) {
				if (txt[i + j] != pat[j]) break;
			}

			if (j == M) std::cout << "Pattern found at index " << i << std::endl;
		}

		if (i < N - M) {
			t = (d * (t - txt[i] * h) + txt[i + M]) % q;

			if (t < 0) t = t + q;
		}
	}
}

int main() {
	std::string txt = "aabaacaadaabaaba";
	std::string pat = "aaba";
	search(txt, pat);
	return 0;
}
