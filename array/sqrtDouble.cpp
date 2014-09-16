double sqrt(double x) 
{
	if (x < 0) return 0;
    if (x == 0 || x == 1) return x;
	double eps = 0.0000001;
    double l, r;
    if (x > 1) {
        l = 1;
        r = x;
    }
    else {
        l = x;
        r = 1;
    }
    while (1) {
        double mid = l/2 + r/2;
        double multi = mid * mid;
        if (abs(multi-x) <= eps) return mid;
        else {
            if (multi < x) mid = mid/2 + r/2;
            else mid = mid/2 + l/2;
            multi = mid*mid;
            if (abs(multi-x) <= eps) return mid;
            else if (multi < x) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
    }
    return 0;
}

int main(int argc, _TCHAR* argv[])
{
	//double ret = sqrt(1.5);
	double ret = sqrt(0.5);
	return 0;
}
