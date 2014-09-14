int divide(int dividend, int divisor)
	{
		bool neg = (dividend ^ divisor) < 0;
		if (divisor == 0) {
			if (neg) return INT_MIN;
			else return INT_MAX;
		}
		long long absDividend = abs((long long)dividend);
		long long absDivisor = abs((long long)divisor);
		if (absDividend < absDivisor) return 0;
		if (absDividend == absDivisor) return neg ? -1 : 1;
		int multi = 1;
		while ((absDivisor << 1) <= absDividend) {
				multi <<= 1;
				absDivisor <<= 1;
		}
		multi += divide(absDividend - absDivisor, abs(divisor));
		return neg ? -multi : multi;
	}
