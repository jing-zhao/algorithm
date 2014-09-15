//Find the least number of coins required that can make any change from 1 to 99 cents. The coins can only be pennies (1), nickels (5), dimes (10), and quarters (25), and you must be able to make every value from 1 to 99 (in 1-cent increments) using those coins.

int minCoins(int coins[], int len, int n)
{
    if (len == 1) return n;
    int minCount = INT_MAX;
    for (int i = n/coins[len-1]; i >= 0; i--) {
        minCount = min(minCount, minCoins(coins, len-1, n-i*coins[len-1])+i);
    }
    return minCount;
}
int minCoins(int n) {
    if (n <= 0) return 0;
    int coins[] = {1, 5, 10, 25};
    return minCoins(coins, sizeof(coins)/sizeof(int), n);
}

int main(int argc, _TCHAR* argv[])
{
	int min = minCoins(99);
	return 0;
}
