class BlackScholes
{
public:
	BlackScholes(double strike, double spot, double rate,
		double time_to_exp, PayoffType pot);

	double operator()(double vol);

private:
	void compute_norm_args_(double vol);		// d_1 and d_2

	double strike_, spot_, rate_, sigma_, time_to_exp_;
	PayoffType pot_;

	double d1_{ 0.0 }, d2_{ 0.0 };
};

double BlackScholes::operator()(double vol)
{
	int phi = static_cast<int>(pot_);		// (1)

	double opt_price = 0.0;
	if (time_to_exp_ > 0.0)					// (2)
	{
		compute_norm_args_(vol);			// (3)

		auto norm_cdf = [](double x) -> double		// (4)
		{
			return (1.0 + std::erf(x / std::numbers::sqrt2)) / 2.0;
		};

		double nd_1 = norm_cdf(phi * d1_);		// N(d1_) (5)
		double nd_2 = norm_cdf(phi * d2_);		// N(d2_) (5)
		double disc_fctr = exp(-rate_ * time_to_exp_);		// (6)

		opt_price = phi * (spot_ * nd_1 - disc_fctr * strike_ * nd_2);		// (7)
	}
	else
	{
		opt_price = std::max(phi * (spot_ - strike_), 0.0);		// <algorithm>  // (8)
	}

	return opt_price;
}

double strike = 75.0;
auto corp = PayoffType::Call;	// corp = "call or put"
double spot = 100.0;
double rate = 0.05;
double vol = 0.25;
double time_to_exp = 0.0;

// ITM Call at expiration (time_to_exp = 0):
BlackScholes
	bsc_itm_exp{ strike, spot, rate, time_to_exp, corp };

double value = bsc_itm_exp(vol);	// Result: 25 (payoff - intrinsic value only)

// OTM put with time remaining:
time_to_exp = 0.3;
corp = PayoffType::Put;
BlackScholes
		bsp_otm_tv{ strike, spot, rate, time_to_exp, corp };

value = bsp_otm_tv(vol);		// Result: 0.056 (time value only

double implied_volatility_with_move(BlackScholes&& bsc, double opt_mkt_price, double x0, double x1,
	double tol, unsigned max_iter)
{
	auto f = [&bsc, opt_mkt_price](double x) -> double
	{
		return bsc(x) - opt_mkt_price;
	};

	double y0 = f(x0);
	double y1 = f(x1);

	//. . . (Code exactly the same as in the previous implied_volatility(.) example...

	if (count_iter < max_iter)
	{
		return impl_vol;
	}
	else
	{
		return std::nan(" ");		// std::nan(" ") in <cmath>
	}
}