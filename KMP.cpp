// Time complexity : o(n + m) where n is the length of the textand m is the length of the pattern to be found.
// Auxiliary space : o(m)

#include <iostream>
#include <string>
#include <vector>
#include <type_traits>

// function for printing
template <class t>
void print(t container) {
	if (std::is_same<t, std::string>::value) {
		for (auto i : container) std::cout << i;
	}
	else if (std::is_same<t, std::vector<int>>::value) {
		for (auto i : container) std::cout << i << " ";
	}
	std::cout << std::endl;
}

class patternsearching {
public:
	// method for kmp search
	void kmpsearch(std::string txt, std::string pat) {
		size_t n = txt.size(); size_t m = pat.size();
		std::vector<int> lps;
		computelpsarray(pat, lps);
		size_t i = 0, j = 0;
		while ((n - i) >= (m - j)) {
			if (txt[i] == pat[j]) { i++; j++; }
			if (j == m) {
				std::cout << "found pattern at index " << i - j << std::endl;
				j = lps[j - 1];
			}
			else if (i < n && pat[j] != txt[i]) {
				if (j != 0) j = lps[j - 1];
				else i++;
			}
		}

	}
private:
	// method for constructing lps 
	void computelpsarray(std::string pat, std::vector<int>& lps) {
		lps.clear();
		size_t m = pat.size();
		size_t len = 0; size_t i = 0;

		while (i < m) {
			if (i == 0) { lps.push_back(0); i++; }
			if (pat[i] == pat[len]) {
				len++;
				lps.push_back(len);
				i++;
			}
			else if (pat[i] != pat[len] && len > 0) len = lps[len - 1];
			else {
				lps.push_back(len);
				i++;
			}
		}
	}
};

int main() {
	std::string txt = "aabaacaadaabaaba";
	std::string pat = "aaba";
	patternsearching obj;
	obj.kmpsearch(txt, pat);
	return 0;
}
