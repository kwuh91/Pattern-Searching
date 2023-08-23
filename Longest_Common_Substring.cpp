// Time Complexity : O(m* n)
// Auxiliary Space : O(m* n), since m * n extra space has been taken.

#include <iostream>
#include <string>

int LCSubStr(std::string X, std::string Y){
	size_t m = X.size(); size_t n = Y.size();

	int** LCSuff = new int* [m + 1];
	for (size_t i = 0; i < m + 1; ++i) {
		LCSuff[i] = new int[n + 1];
	}

	int result = 0; 

	for (size_t i = 0; i < m+1; i++){
		for (size_t j = 0; j < n+1; j++){

			if (i == 0 || j == 0) LCSuff[i][j] = 0;
				
			else if (X[i - 1] == Y[j - 1]) {
				LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
				result = std::max(result, LCSuff[i][j]);
			}

			else LCSuff[i][j] = 0;
		}
	}

	//for (size_t i = 0; i < m + 1; i++) {
	//	for (size_t j = 0; j < n + 1; j++) {
	//		std::cout << LCSuff[i][j] << " ";
	//	}
	//	std::cout << std::endl;
	//}
	//std::cout << std::endl;
	return result;
}

// Driver code
int main()
{
	std::string X = "babadz";
	std::string Y = "dabab";

	std::cout << LCSubStr(X, Y);
	return 0;
}
